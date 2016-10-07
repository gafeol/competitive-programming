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

int n, m, k;
int s[MAXN];

vector<pii> adj[MAXN];

int p[MAXN][LOGN], pc[MAXN], d[MAXN], h[MAXN], sz[MAXN], mx[MAXN], imx[MAXN];

int hc[MAXN], cor[MAXN];

multiset<int> s[MAXN];

int res;

void ini(int u, int pai){
	p[u][0] = pai;
	for(int a=0;a<LOGN;a++){
		p[u][a] = p[p[u][a-1]][a-1];
	}
	for(pii nxt: adj[u]){
		int v = nxt.fst;
		int c = nxt.snd;
		if(v == pai) continue;
		d[v] = d[u] + c;
		h[v] = h[u] + 1;
		ini(v, u);
	}
}

int lca(int u, int v){
	if(h[u] < h[v])
		swap(u, v);
	for(int a=LOGN-1;a>=0;a--){
		if(h[p[u][a]] >= h[v])
			u = p[u][a];
	}
	if(u == v)
		return u;
	for(int a=LOGN-1;a>=0;a--){
		if(p[u][a] != p[v][a]){
			u = p[u][a];
			v = p[v][a];
		}
	}
	return p[u][0];
}

int dist(int u, int v){
	return d[u] + d[v] - 2*d[lca(u, v)];
}

void go(int u, int pai){
	sz[u] = 1;
	mx[u] = -1;
	imx[u] = -1;
	for(pii nxt: adj[u]){
		int v = nxt.fst;
		int c = nxt.snd;
		if(hc[v] != -1 || v == pai) continue; 
		go(v, u);
		sz[u] += sz[v];
		mx[u] = max(mx[u], sz[u]);
		if(mx[u] == sz[u])
			imx[u] = v;
	}
}

void build(int u, int rc, int niv){
	go(u, u);
	int tot = sz[u];
	while(u != -1 && mx[u] > tot/2){
		u = imx[u];
	}
	pc[u] = rc;
	hc[u] = niv;
	for(pii nxt: adj[u]){
		int v = nxt.fst;
		int c = nxt.snd;
		build(v, u, niv + 1); 
	}	
}

void upd(int u){
	while(u != -1){
		if(cor[u])
	}
}

int main (){
	res = INT_MIN;
	scanf("%d", &n);
	for(int a=0;a<=n;a++){
		hc[a] = -1;
	}
	for(int a=0;a<n-1;a++){
		int i, j, c;
		scanf("%d%d%d", &i, &j, &c);
		adj[i].pb(pii(j, k));
		adj[j].pb(pii(i, k));
	}
	d[1] = 1;
	ini(1, 1);
	build(1, -1, 1);
	for(int a=1;a<=n;a++){
		upd(a);
		cor[a] = 1;
	}
}
