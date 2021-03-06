#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;
const int LOGN = 30;

int n, m, k;
int s[MAXN], d[MAXN], pc[MAXN], sz[MAXN], mx[MAXN], imx[MAXN];
int ans[MAXN], h[MAXN];
int pai[MAXN][LOGN], hi[MAXN];

vector<int> adj[MAXN];

void dfs(int u, int p){
	sz[u] = 1;
	mx[u] = 0;
	imx[u] = -1;
	for(int nxt: adj[u]){
		if(nxt == p || h[nxt] != -1)
			continue;
		dfs(nxt, u);
		sz[u] += sz[nxt];
		mx[u] = max(mx[u], sz[nxt]);
		if(mx[u] == sz[nxt])
			imx[u] = nxt;
	}
//	printf("	DFS %d mx %d imx %d sz %d\n", u, mx[u], imx[u], sz[u]);
}

void idfs(int u, int p){
	sz[u] = 1;
	pai[u][0] = p;
	for(int a=1;a<LOGN;a++){
		pai[u][a] = pai[pai[u][a-1]][a-1];
	}
	for(int nxt: adj[u]){
		if(nxt == p)
			continue;
		hi[nxt] = hi[u] + 1;
		idfs(nxt, u);
		sz[u] += sz[nxt];
	}
}

void build(int u, int p, int niv){
//	printf("BUILD %d %d %d\n", u, p, niv);
	dfs(u, u);
	int tot = sz[u];
	while(imx[u] != -1 && mx[u] > tot/2){
		u = imx[u];
	}
//	printf("	u: %d\n\n", u); 
	h[u] = niv;
	pc[u] = p;
//	printf("pc[%d] =  %d\n", u, p);
	for(int nxt: adj[u]){
//		printf("%d ta ligado com %d %d\n", u, nxt, h[nxt]);
		if(h[nxt]== -1)
			build(nxt, u, niv+1);
	}
//	printf("\n\n");
}

int lca(int u, int v){
//	printf("LCA %d %d\n", u, v);
	if(u == v) return u;
	if(hi[u] < hi[v])
		swap(u, v);
	for(int a=LOGN-1;a>=0;a--){
		if(hi[pai[u][a]] >= hi[v])
			u = pai[u][a];
	}
	if(u == v){
//		printf("	RETORN1 %d\n", u);
		return u;
	}
	for(int a=LOGN-1;a>=0;a--){
		if(pai[u][a] != pai[v][a]){
			u = pai[u][a];
			v = pai[v][a];
		}
	}
//	printf("	RETORN2 %d\n", pai[u][0]);
	return pai[u][0];
}

int dist(int u, int v){
//	printf("dist (%d %d) = %d\n", u, v, hi[u] + hi[v] -2*hi[lca(u, v)]);
	return hi[u] + hi[v] - 2*hi[lca(u, v)];	
}

void upd(int u){
	int uu = u;
	while(uu != -1){
		ans[uu] = min(ans[uu], dist(u, uu));
//		printf("upd %d ans[%d] eh %d\n", u, uu, ans[uu]);
		uu = pc[uu];
	}
}

void qry(int u){
	int res = INT_MAX;
	int uu = u;
	while(uu != -1){
//		printf("para u %d uu %d res = %d ou %d + %d\n", u, uu, res, dist(u, uu), ans[uu]); 
		res = min(res, dist(u, uu) + ans[uu]);
		uu = pc[uu];
	}
	printf("%d\n", res);
}

int main ()	{
	scanf("%d%d", &n, &m);
	for(int a=0;a<=n;a++){
		pc[a] = -1;
		h[a] = -1;
		ans[a] = 1000000;
	}
	for(int a=0;a<n-1;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	hi[1] = 1;
	idfs(1, 1);
//	printf("fim\n");
	build(1, -1, 1);
//	printf("fim\n");
	upd(1);
//	printf("fim\n");
	for(int a=0;a<m;a++){
		int t, u;
		scanf("%d%d", &t, &u);
		if(t == 1)
			upd(u);
		else
			qry(u);
	}
}
