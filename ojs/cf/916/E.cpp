#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)
#define pb push_back
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

#define int ll

const int MAXN = 212345, LOGN = 30;

int n, m, k;
int s[MAXN];

int g[MAXN];
int deg;
int ini[MAXN], fim[MAXN];

vector<int> adj[MAXN];

int p[MAXN][LOGN], h[MAXN];

void dfs(int v,int pai, int alt){
	g[deg] = v;
	debug("%lld ", v);
	ini[v] = deg++;
	h[v] = alt;
	p[v][0] = pai;
	for(int a = 1;a<LOGN;a++){
		p[v][a] = p[p[v][a-1]][a-1];
	}
	for(int a = 0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt == pai) continue;
		dfs(nxt,v,alt+1);
	}
	fim[v] = deg;
}

int lca(int i, int j){
	if(h[j] > h[i]) swap(i,j);
	if(h[i] > h[j]){
		for(int a=LOGN-1;a>=0;a--){
			if(h[p[i][a]] > h[j]){
				i = p[i][a];
			}
		}
		i = p[i][0];
	}

	if(i != j){
		for(int a = LOGN-1;a>=0;a--){
			if(p[i][a] != p[j][a]){
				i = p[i][a];
				j = p[j][a];
			}
		}
		i = p[i][0];
	}

	return i;
}

int llca(int i, int j){
// i filho distante de j, devolve filho direto de j ancestral de i
	for(int a=LOGN-1;a>=0;a--){
		if(h[p[i][a]] > h[j]){
			i = p[i][a];
		}
	}
	return i;
}

int rlca(int nr, int u, int v){
	vector<int> a;
	a.pb(lca(nr, u));
	a.pb(lca(nr, v));
	a.pb(lca(u, v));
	sort(a.begin(), a.end());
	if(a[0] != a[1] && a[1] != a[2])
		debug("todos sao diferentes!\n");
	if(a[0] != a[1])
		return a[0];
	return a[2];

}

struct arv{
	ll sum, lz;
} tree[MAXN*4];

void build(int idx, int i, int j){
	tree[idx].lz = 0;
	if(i == j){
		tree[idx].sum = s[g[i]];	
		debug("build %lld - %lld v %lld tree %lld sum %lld\n", i, j, g[i], idx, tree[idx].sum);
		return ;
	}
	int m = (i + j)/2;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
	tree[idx].sum = tree[idx*2].sum + tree[idx*2+1].sum;
	debug("build %lld - %lld tree %lld sum %lld\n", i, j, idx, tree[idx].sum);
}

void unlaze(int idx, int i, int j){
	ll aux = tree[idx].lz;
	debug("unlaze %lld de %lld %lld\n", aux, i, j);
	int m = (i + j)/2;
	tree[idx].lz = 0;
	if(i != j){
		tree[idx*2].sum += aux*(m-i+1);
		tree[idx*2].lz += aux;
		tree[idx*2+1].sum += aux*(j-m);
		tree[idx*2+1].lz += aux;
	}
}

void upd(int idx, int i, int j, int l, int r, ll x){
	if(i > r || j < l) return ;
	unlaze(idx, i, j);
	if(i >= l && j <= r){
		tree[idx].sum += x*(j - i + 1);
		tree[idx].lz += x;
		return ;
	}
	int m = (i+j)/2;
	upd(idx*2, i, m, l, r, x);
	upd(idx*2+1, m+1, j, l, r, x);
	tree[idx].sum = tree[idx*2].sum + tree[idx*2+1].sum;
}

ll qry(int idx, int i, int j, int l, int r){
	if(i > r || j < l) return 0;
	unlaze(idx, i, j);
	if(i >= l && j <= r)
		return tree[idx].sum;
	int m = (i+j)/2;
	return qry(idx*2, i, m, l, r) + 
		qry(idx*2+1, m+1, j, l, r);
}

main (){
	scanf("%lld%lld", &n, &m);
	for(int a=1;a<=n;a++){
		scanf("%lld", s+a);
	}
	for(int a=0;a<n-1;a++){
		int i, j;
		scanf("%lld %lld", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	dfs(1, 1, 0);
	debug("\n");
	build(1, 0, deg-1);
	int nr = 1;
	int r =  1;
	for(int a=0;a<m;a++){
		int t;
		scanf("%lld", &t);
		if(t == 1){
			int u;
			scanf("%lld", &u);
			nr = u;
		}
		else if(t == 2){
			int u, v, x;
			scanf("%lld %lld %lld", &u, &v, &x);
			int rl = rlca(nr, u, v);
			debug("soma %lld pra real lca %lld\n", x, rl);
			if(lca(nr, rl) != rl){
				debug("+x %lld %lld\n", ini[rl], fim[rl]-1);
				upd(1, 0, deg-1, ini[rl], fim[rl]-1, x);
			}
			else{
				debug("+x %lld %lld\n", ini[1], fim[1]-1);
				upd(1, 0, deg-1, ini[1], fim[1]-1, x);
				if(nr != rl){
					int ls = llca(nr, rl);
					upd(1, 0, deg-1, ini[ls], fim[ls]-1, -x); 
				}
			}
		}
		else{
			ll res = 0;
			int rl;
			scanf("%lld", &rl);
			if(lca(nr, rl) != rl){
				res = qry(1, 0, deg-1, ini[rl], fim[rl]-1);
				debug("qry %lld %lld = %lld\n", ini[rl], fim[rl]-1, res);
			}
			else{
				res = qry(1, 0, deg-1, ini[1], fim[1]-1);
				if(nr != rl){
					int ls = llca(nr, rl);
					res -= qry(1, 0, deg-1, ini[ls], fim[ls]-1); 
				}
			}
			printf("%lld\n", res);
		}
	}
}

