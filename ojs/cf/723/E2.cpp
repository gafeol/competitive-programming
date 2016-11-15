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

const int MAXN = 212;

int n, m, k;
int s[MAXN], img[MAXN][MAXN];
int dir[MAXN][MAXN], bal[MAXN];
int res;

vector<int> adj[MAXN], imp;
int mrk[MAXN], deg[MAXN], vis[MAXN][MAXN];

void go(int u){
	if(deg[u]&1)
		imp.pb(u);
	mrk[u] = 1;
	for(int nxt: adj[u]){
		if(mrk[nxt]) continue;
		go(nxt);
	}
}

void dfs(int u){
	mrk[u] = 1;
	debug("dfs %d\n", u);
	for(int nxt: adj[u]){
		if(vis[u][nxt]) continue;
		vis[u][nxt] = 1;
		vis[nxt][u] = 1;
		bal[u]--;
		bal[nxt]++;
		debug("u %d -> nxt %d\n", u, nxt);
		dir[u][nxt] = 1;
		dir[nxt][u] = 0;
		dfs(nxt);
	}
}

int main (){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int a=1;a<=n+1;a++){
			adj[a].clear();
			deg[a] = 0;
			bal[a] = 0;
			mrk[a] = 0;
		}
		res = 0;
		memset(dir, 0, sizeof(dir));
		memset(img, 0, sizeof(img));
		memset(vis, 0, sizeof(vis));
		for(int a=0;a<m;a++){
			int i, j;
			scanf("%d%d", &i, &j);
			deg[i]++;
			deg[j]++;
			adj[i].pb(j);
			adj[j].pb(i);
		}
		imp.clear();
		for(int a=1;a<=n;a++){
			if(!mrk[a]){
				go(a);
			}
		}
		for(int b=0;b<imp.size();b++){
			debug("cria aresta %d - %d\n", imp[b], n+1);
			img[imp[b]][n+1] = 1;
			img[n+1][imp[b]] = 1;
			adj[imp[b]].pb(n+1);
			adj[n+1].pb(imp[b]);
		}
		memset(mrk, 0, sizeof(mrk));
		for(int a=1;a<=n;a++){
			if(!mrk[a])
				dfs(a);
		}
		for(int a=1;a<=n;a++){
			res += (bal[a] == 0 && !(deg[a]&1));
		}
		printf("%d\n", res);
		for(int a=1;a<=n;a++){
			for(int nxt: adj[a]){
				debug("RES %d %d\n", a, nxt);
				if(dir[a][nxt] && !img[a][nxt])
					printf("%d %d\n", a, nxt);
				if(img[a][nxt])
					img[a][nxt] = 0;
			}
		}
	}
}
