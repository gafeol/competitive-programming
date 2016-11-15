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

const int MAXN = 2123;

int n, m, k;
int t;
int bal[MAXN], mrk[MAXN][MAXN], deg[MAXN];

vector<int> adj[MAXN];

void ares(int u, int v){
	debug("%d deg %d bal %d -  %d deg %d bal %d\n", u, deg[u], bal[u], v, deg[v], bal[v]);
	if(deg[u]&1)
		swap(u, v);
	mrk[u][v] = (bal[u] > 0);
	mrk[v][u] = !(bal[u] > 0);
	if(bal[u] > 0)
		debug("%d -> %d\n", u, v);
	else
		debug("%d -> %d\n", v, u);
	if(bal[u] <= 0)
		swap(u, v);
	bal[u]--;
	bal[v]++;
}

void go(int u){
	debug("\n GO %d \n", u);
	for(int nxt: adj[u]){
		if(mrk[u][nxt] != -1) continue;
		ares(u, nxt);
		go(nxt);
	}
}

main (){
	scanf("%d", &t);
	while(t--){
		memset(mrk, -1, sizeof(mrk));
		scanf("%d %d", &n, &m);
		for(int a=1;a<=n;a++){
			adj[a].clear();
			deg[a] = 0;
			bal[a] = 0;
		}
		for(int a=0;a<m;a++){
			int i, j;
			scanf("%d%d", &i, &j);
			adj[i].pb(j);
			adj[j].pb(i);
			deg[i]++;
			deg[j]++;
		}
		for(int a=1;a<=n;a++){
			if(deg[a]&1) continue;
			for(int nxt: adj[a]){
				if(mrk[a][nxt] == -1){
					go(a);
					debug("SAI\n");
				}
			}
		}
		for(int a=1;a<=n;a++){
			for(int nxt: adj[a]){
				if(mrk[a][nxt] == -1){
					ares(a, nxt);
				}
			}
		}
		int res =0;
		for(int a=1;a<=n;a++){
			if(deg[a]&1) continue;
			if(bal[a] == 0) res++;
		}
		printf("%d\n", res);
		for(int a=1;a<=n;a++){
			for(int nxt: adj[a]){
				if(mrk[a][nxt] == 3) continue;
				else if(mrk[a][nxt] == 0){
					printf("%d %d\n", nxt, a);
					mrk[a][nxt] = 3;
					mrk[nxt][a] = 3;
				}
				else{
					printf("%d %d\n", a, nxt);
					mrk[a][nxt] = 3;
					mrk[nxt][a] = 3;
				}
			}
		}
	}
}
