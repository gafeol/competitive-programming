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

const int MAXN = 4123;

int n, m, k;

map<string, int> ind;
map<int, string> inv;
map<int, int> liga;
int degs = 0;
int comp[MAXN], pai[MAXN];
int leaf[MAXN];
int in[MAXN];
char s1[10], s2[10];
int npaths;

vector<int> paths[MAXN];

int mrk[MAXN];

vector<int> adj[MAXN]; 
vector<int> adjC[MAXN];
set<pii> q;


void go(int u, int h){
	debug("go(%d %d)\n", u, h);
//	cout << inv[u] << endl;
	if(h == 0) pai[u] = u;
	int cnt = 0;
	mrk[u] = 1;
	for(int nxt: adj[u])
		cnt += (mrk[nxt] == 0);
	if(cnt >= 2)
		q.insert(pii(-h, u));
	for(int nxt: adj[u]){
		if(mrk[nxt]) continue;
		go(nxt, h+1);
		pai[nxt] = u;
	}
}

int rmv[MAXN];

int findleaf(int u, int t){
	in[u] = npaths;
	rmv[u] = 1;
	if(!t){
		paths[npaths].pb(u);
		debug("%d ", u);
	}
	for(int nxt: adj[u]){
		if(rmv[nxt]) continue;
		findleaf(nxt, t);
	}
	if(t){
		paths[npaths].pb(u);
		debug("%d ", u);
	}
}

bool findpath(int u){
	debug("findpath %d chama de %d\n",  npaths, u);
	int cnt = 0;
	for(int nxt: adj[u]){
		if(rmv[nxt] || nxt == pai[u]) continue;
		cnt++;
	}
	// era um divisor agora nao e mais// era um divisor agora nao e mais
		if(cnt  < 2)
		return true;
	if(cnt != 2){
		return false;
	}
	cnt = 0;
	rmv[u] = 1;
	for(int nxt: adj[u]){
		if(rmv[nxt] || nxt == pai[u]) continue;
		cnt++;
		if(cnt == 1)
			findleaf(nxt, 1);
		else{
			in[u] = npaths;
			paths[npaths].pb(u);
			debug("%d ", u);
			findleaf(nxt, 0);
		}
	}
	npaths++;
	return true;
}

int mrkC[MAXN];
int pre[MAXN];

int goC(int u, int cnt){
	mrkC[u] = 1;
	int ans = 0;
	for(int nxt: adjC[u]){
		if(mrkC[nxt]) continue;
		ans = max(ans, goC(nxt, cnt+1));
		pre[nxt] = u;
	}
	if(cnt == npaths) ans = 1;
	return ans;
}

void print(int u){
	cout << inv[u] << " ";
	mrk[u] = 1;
	int cnt = 0;
	for(int nxt: adj[u]){
		if(in[nxt] == in[u] && !mrk[nxt]){	
			print(nxt);
			cnt++;
		}
	}
	assert(cnt <= 1);
	if(leaf[u] && !mrk[liga[u]])
		print(liga[u]);
}

void put(string S){
	if(ind.find(S) == ind.end()){
		ind[S] = degs++;
		inv[degs-1] = S;
	}
}

int main (){
	for_tests(t, tt){
		for(int a=0;a<degs;a++){
			mrk[a] = 0;
			mrkC[a] = 0;
			adj[a].clear();
			adjC[a].clear();
			rmv[a] = 0;
		}
		degs = 0;
		npaths = 0;
		liga.clear();
		ind.clear();
		inv.clear();
		scanf("%d %d %d", &k, &n, &m);
		for(int a=0;a<k+n-1;a++){
			scanf(" %s %s", s1, s2);
			put(s1);
			put(s2);

			comp[ind[s1]] = 0;
			comp[ind[s2]] = 0;

			if(s1[1] == 'S')
				leaf[ind[s1]] = 1;
			else
				leaf[ind[s1]] = 0;
			if(s2[1] == 'S')
				leaf[ind[s2]] = 1;
			else
				leaf[ind[s2]] = 0;

			adj[ind[s1]].pb(ind[s2]);
			adj[ind[s2]].pb(ind[s1]);
		}
		for(int a=0;a<k+m-1;a++){
			scanf(" %s %s", s1, s2);
			put(s1);
			put(s2);

			comp[ind[s1]] = 1;
			comp[ind[s2]] = 1;

			if(s1[1] == 'S')
				leaf[ind[s1]] = 1;
			else
				leaf[ind[s1]] = 0;
			if(s2[1] == 'S')
				leaf[ind[s2]] = 1;
			else
				leaf[ind[s2]] = 0;

			adj[ind[s1]].pb(ind[s2]);
			adj[ind[s2]].pb(ind[s1]);
		}

		int fodeu = 0;
		for(int a=0;a<degs;a++){
			if(!leaf[a] && !mrk[a]){
				go(a, 0);
				while(!q.empty()){
					int u = q.begin()->snd;
					q.erase(q.begin());
					if(!findpath(u)){
						fodeu = 1;
						q.clear();
						break;
					}
				}
			}
			if(fodeu)
				break;
		}

/*
		debug("\nTODOS OS PATH\n");
		for(int a=0;a<npaths;a++){
			debug("path %d: ", a); 
			for(int u: paths[a])
				debug("%d ", u);

			debug("\n");
		}
*/
		for(int a=0;a<k;a++){
			scanf(" %s %s", s1, s2);
			int u = ind[s1], v = ind[s2];
			liga[u] = v;
			liga[v] = u;
			adjC[in[u]].pb(in[v]);
			adjC[in[v]].pb(in[u]);
		}
		if(fodeu || !goC(0, 1)){
			puts("NO");
			continue;
		}
		//imprimir o caminho
		printf("YES ");
		memset(mrk, 0, sizeof(mrk));
		print(0);
		printf("\n");
	}
}
