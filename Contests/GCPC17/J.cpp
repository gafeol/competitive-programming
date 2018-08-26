#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 19;
const int BIT = (1<<19) + 10;

int n, m, k;
int h, w;
int sz[MAXN];
char s[MAXN][MAXN];
int cost[MAXN][MAXN];
queue<pii> q;

int fit(int a, int b){
	int ta = strlen(s[a]);
	int tb = strlen(s[b]);
	for(int i=0;i<ta;i++){
		int ok = 1;
		for(int j=i;j<ta && j - i < tb;j++){
			if(s[a][j] != s[b][j-i]){
				ok = 0; 
				break;
			}
		}
		if(ok){
			return max(0, tb - (ta - i));
		}
	}
	return tb;
}

pii d[MAXN][BIT], bef[MAXN][BIT];

pii join(pii state, int i, int j){
	if(state.snd + cost[i][j] <= w)
		return pii(state.fst, state.snd + cost[i][j]);
	return pii(state.fst + 1, sz[j]);
}

pii lst;

void go(int u){
	lst = pii(INT_MAX, INT_MAX);
	for(int a=0;a<n;a++){
		d[a][(1<<a)] = pii(0, sz[a]);
		q.push(pii(a, (1<<a)));
	}
	while(!q.empty()){
		pii top = q.front();	
		q.pop();
		int u = top.fst;
		int bm = top.snd;
		if(d[u][bm].fst >= h) 
			continue; 
//		debug("u %d bm %d\n dp %d %d\n", u, bm, d[u][bm].fst, d[u][bm].snd);

		if(bm == ((1<<n)-1))
			lst = pii(u, bm);

		for(int a=0;a<n;a++){
			if((bm&(1<<a)))
				continue;
			int bmm = (bm|(1<<a));
			if(d[a][bmm].fst == INT_MAX && d[a][bmm].snd == INT_MAX){
//				debug(" -> %d %d\n", a, bmm);
				q.push(pii(a, bmm));
			}

			pii jc = join(d[u][bm], u, a);

			if(d[a][bmm] > jc){
				d[a][bmm] = jc;
				bef[a][bmm] = pii(u, bm);
			}
		}
	}
}

char res[MAXN][MAXN];

int mrk[MAXN];

vector<string> pal;

int main (){
	scanf("%d%d%d", &h, &w, &n);
	for(int a=0;a<n;a++){
		for(int bm=0;bm < (1<<n);bm++){
			d[a][bm] = pii(INT_MAX, INT_MAX);
		}
	}
	for(int a=0;a<n;a++){
		scanf(" %s", s[a]);
		sz[a] = strlen(s[a]);
		if(sz[a] > w){
			puts("impossible");
			return 0;
		}
	}
	for(int a=0;a<n;a++){
		for(int b=a+1;b<n;b++){
			if(sz[a] < sz[b]){
				if(fit(b, a) == 0){
					mrk[a] = 1;
				}
			}
			else{
				if(fit(a, b) == 0){
					mrk[b] = 1;
				}
			}
		}
	}
	for(int a=0;a<n;a++){
		if(!mrk[a])
			pal.pb(s[a]);
	}
	n = pal.size();
	for(int a=0;a<n;a++){
		for(int i=0;i<pal[a].size();i++){
			s[a][i] = pal[a][i];
		}
		s[a][pal[a].size()] = '\0';
		sz[a] = strlen(s[a]);
		debug("clean %s\n", s[a]);
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			cost[a][b] = fit(a, b);
		}
	}
	go(0);

	if(lst.fst == INT_MAX){
		puts("impossible");
		return 0;
	}
	else{
		int cnt = n;
		while(cnt > 0){
			int id = lst.fst;
			debug("put %d: line %d from %d - %d\n", id, d[id][lst.snd].fst, d[id][lst.snd].snd- sz[id], d[id][lst.snd].snd);
			int line  = d[id][lst.snd].fst;
			int ini = d[id][lst.snd].snd - sz[id];
			for(int i = 0;i < sz[id];i++){
				res[line][i+ini] = s[id][i];
			}
			lst = bef[lst.fst][lst.snd];
			cnt--;
		}
		for(int a=0;a<h;a++){
			for(int b=0;b<w;b++){
				if(res[a][b] == 0)
					res[a][b] = 'A';
				printf("%c", res[a][b]);
			}
			puts("");
		}
	}
}

