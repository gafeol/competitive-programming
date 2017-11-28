#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
#define int ll
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345, LOGN = 30;

int n, m, k;

int sz[MAXN], pai[MAXN];

int p[MAXN][LOGN], mx[MAXN][LOGN];
int h[MAXN];
int ind[MAXN];

vector<pii> adj[MAXN];

struct ares{
	int u, v;
	ll c;
	ares(){}
	ares(int uu, int vv, ll cc) : u(uu), v(vv), c(cc) {}
} ar[MAXN];

bool cmp(int a, int b){
	return ar[a].c < ar[b].c;
}

int raiz(int a){
	if(pai[a] == a) return a;
	return pai[a] = raiz(pai[a]);
}

void join(int i, int j){
	i = raiz(i);
	j = raiz(j);
	if(i == j) return ;
	if(sz[i] > sz[j])
		swap(i, j);
	pai[i] = j;
	sz[j] += sz[i];
}

void go(int u, int pai, ll c){
	h[u] = h[pai] + 1;
	p[u][0] = pai;
	mx[u][0] = c;
	for(int i=1;i<LOGN;i++){
		mx[u][i] = max(mx[u][i-1], mx[p[u][i-1]][i-1]);
		p[u][i] = p[p[u][i-1]][i-1];
	}
	for(pii ar: adj[u]){
		int nxt = ar.fst;
		int cus = ar.snd;
		if(nxt == pai) continue;
		go(nxt, u, cus);
	}
}

int lca(int u, int v){
	int ans = 0;
	if(h[u] != h[v]){
		if(h[u] < h[v])
			swap(u, v);
		for(int i=LOGN-1;i>=0;i--){
			if(h[p[u][i]] > h[v]){
				ans = max(ans, mx[u][i]);
				u = p[u][i];
			}
		}
		ans = max(ans, mx[u][0]);
		u = p[u][0];
	}
	if(u == v) return ans;
	for(int i = LOGN-1;i>=0;i--){
		if(p[u][i] != p[v][i]){
			ans = max(ans, max(mx[u][i], mx[v][i]));
			u = p[u][i];
			v = p[v][i];
		}
	}
	ans = max(ans, max(mx[u][0], mx[v][0]));
	return ans;
}

main (){
	scanf("%lld%lld", &n, &m);
	for(int a=1;a<=n;a++){
		sz[a] = 1;
		pai[a] = a;
	}
	for(int a=0;a<m;a++){
		int i, j;
		ll c;
		scanf("%lld %lld %lld", &i, &j, &c);
		ar[a] = ares(i, j, c);
		ind[a] = a;
	}
	sort(ind, ind+m, cmp);
	ll cus = 0;
	for(int aa=0;aa<m;aa++){
		int a = ind[aa];
		int i = ar[a].u;
		int j = ar[a].v;
		if(raiz(i) == raiz(j)) continue;
		join(i, j);
		cus += ar[a].c;
		adj[i].pb(pii(j, ar[a].c));
		adj[j].pb(pii(i, ar[a].c));
	}
	h[1] = 0;
	go(1, 1, 0);
	for(int a=0;a<m;a++){
		int mx = lca(ar[a].u, ar[a].v);		
		printf("%lld\n", cus - mx + ar[a].c);
	}
}

