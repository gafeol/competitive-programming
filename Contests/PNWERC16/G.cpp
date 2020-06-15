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
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 41;

int n, m, k;
int s[MAXN];

namespace f {
	const int maxv = MAXN*MAXN;
	const int maxe =  MAXN*MAXN*4* 2;
	typedef int num;
	num inf = INT_MAX;
	int n = maxv;

	int to[maxe], en, nx[maxe], es[maxe], lv[maxv], qu[maxv], cr[maxv];
	num cp[maxe], fl[maxe];


	bool bfs(int s, int t) {
		memset(lv, -1, sizeof(int) * n);
		lv[s] = 0;
		int a = 0, b = 0;
		qu[b++] = s; cr[s] = es[s];
		while(a < b) {
			for(int i = es[qu[a]]; i != -1; i = nx[i]) {
				if(cp[i] > fl[i] && lv[to[i]] == -1) {
					lv[to[i]] = lv[qu[a]] + 1;
					qu[b++] = to[i];
					cr[to[i]] = es[to[i]];
					if(to[i] == t) return true;
				}
			}
			a++;
		}
		return false;
	}

	num dfs(int u, int t, num mx) {
		if(u == t) return mx;
		for(int &i = cr[u]; i != -1; i = nx[i])
			if(cp[i] > fl[i] && lv[to[i]] == lv[u] + 1)
				if(num a = dfs(to[i], t, min(mx, cp[i] - fl[i]))) {
					fl[i] += a;
					fl[i ^ 1] -= a;
					return a;
				}
		return 0;
	}


	num max_flow(int s, int t) {
		num fl = 0, a;
		while(bfs(s, t))
			while(a = dfs(s, t, inf))
				fl += a;
		return fl;
	}

	void reset_all(int n2=maxv) { n = n2; en = 0; memset(es, -1, sizeof(int) * n); }
	void reset_flow() { memset(fl, 0, sizeof(num) * en); }

	void add_edge(int a, int b, num c, num rc=0) {
		fl[en] = 0; to[en] = b; cp[en] = c;  nx[en] = es[a]; es[a] = en++;
		fl[en] = 0; to[en] = a; cp[en] = rc; nx[en] = es[b]; es[b] = en++;
	}
}

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m);
}

int vi[] = { 0, 0, 1, -1};
int vj[] = { 1, -1, 0, 0};

int mrk[MAXN][MAXN];

char M[MAXN][MAXN];

int id(int i, int j){
	return (i*m + j);
}

void go(int i, int j){
	mrk[i][j] = 1;
	for(int d=0;d<4;d++){
		int ii = i + vi[d];
		int jj = j + vj[d];
		if(!mrk[ii][jj] && M[ii][jj] == 'L')
			go(ii, jj);
	}
}

int main (){
	scanf("%d%d", &n, &m);
	f::reset_all();
	int S = (n*m);
	int R = (n*m + 1);
	int cnt = 0, ans = 0;
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			scanf(" %c", &M[a][b]);
		}
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			if(M[a][b] == 'C'){
				for(int d=0;d<4;d++){
					int i = a + vi[d], j = b + vj[d];
					if(valid(i, j) && M[i][j] == 'L')
						M[a][b] = 'W';
				}
			}
			if(M[a][b] == 'C'){
				cnt++;
				if((a+b)&1){
					f::add_edge(S, id(a, b), 1);
					for(int d=0;d<4;d++){
						int i = a + vi[d], j = b + vj[d];
						if(valid(i, j) && M[i][j] == 'C'){
							f::add_edge(id(a, b), id(i, j), 1);
						}
					}
				}
				else
					f::add_edge(id(a, b), R, 1);
			}
		}
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			if(M[a][b] == 'L' && !mrk[a][b]){
				go(a, b);
				ans++;
			}
		}
	}
	int mx = f::max_flow(S, R);
	printf("%d\n", ans + cnt - mx);
}
