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
	mx[u] = 1;
	imx[u] = u;
	for(int nxt:adj[u]){
		printf("%d tenta %d, porem %d != -1 || %d == p %d", u, nxt, h[nxt], nxt, p); 
		if(nxt == p || h[nxt] != -1)
			continue;
		dfs(nxt, u);
		sz[u] += sz[nxt];
		mx[u] = max(mx[u], sz[nxt]);
		if(mx[u] == sz[nxt])
			imx[u] = nxt;
	}
	printf("%d mx %d imx %d sz %d\n", u, mx[u], imx[u], sz[u]);
}

void idfs(int u, int p){
	sz[u] = 1;
	mx[u] = 1;
	imx[u] = u;
	pai[u][0] = p;
	for(int a=1;a<LOGN-1;a++){
		pai[u][a] = pai[pai[u][a-1]][a-1];
	}
	for(int nxt:adj[u]){
		if(nxt == p)
			continue;
		hi[nxt] = hi[u] + 1;
		idfs(nxt, u);
		sz[u] += sz[nxt];
		mx[u] = max(mx[u], sz[nxt]);
		if(mx[u] == sz[nxt])
			imx[u] = nxt;
	}
}

void build(int u, int p, int niv){
	printf("%d %d %d\n", u, p, niv);
	dfs(u, u);
	printf("%d %d %d\n", u, p, niv);
	int tot = sz[u];
	while(mx[u] > tot/2){
	//	printf("%d %d %d\n", u, mx[u], tot);
		u = imx[u];
	}
	h[u] = niv;
	pc[u] = p;
	for(int nxt: adj[u]){
		if(h[nxt]!= -1)
			build(nxt, u, niv+1);
	}

}

int lca(int u, int v){
	if(u == v) return u;
	if(h[u] < h[v])
		swap(u, v);
	for(int a=LOGN-1;a>=0;a--){
		if(h[pai[u][a]] < h[v])
			u = pai[u][a];
	}
	u = pai[u][0];
	if(u == v)
		return u;
	for(int a=LOGN-1;a>=0;a--){
		if(pai[u][a] != pai[v][a]){
			u = pai[u][a];
			v = pai[v][a];
		}
	}
	return pai[u][0];
}

int dist(int u, int v){
	return hi[u] + hi[v] - 2*hi[lca(u, v)];	
}

void upd(int u){
	int uu = u;
	while(pc[uu] != uu){
		ans[uu] = min(ans[uu], dist(u, uu));
		uu = pc[uu];
	}
	ans[uu] = min(ans[uu], dist(u, uu));
}

void qry(int u){
	int res = INT_MAX;
	int uu = u;
	while(pc[uu] != uu){
		res = min(res, dist(u, uu) + ans[uu]);
		uu = pc[uu];
	}
	res = min(res, dist(uu, u) + ans[uu]);
	printf("%d\n", res);
}

int main ()	{
	scanf("%d%d", &n, &m);
	for(int a=0;a<=n;a++){
		d[a] = INT_MAX;
		pc[a] = -1;
		h[a] = -1;
		ans[a] = INT_MAX;
	}
	for(int a=0;a<n-1;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	hi[1] = 1;
	idfs(1, 1);
	printf("fim\n");
	build(1, 1, n);
	printf("fim\n");
	upd(1);
	printf("fim\n");
	for(int a=0;a<m;a++){
		int t, u;
		scanf("%d%d", &t, &u);
		if(t == 1)
			upd(u);
		else
			qry(u);
	}
}
