#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
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

const int MAXN = 102345, LOGN = 18;

int n, m, k;
vector<pil> adj[MAXN];

int p[MAXN][LOGN];
ll dp[MAXN], d[MAXN];

ll s[MAXN], v[MAXN];

int nxt[MAXN];

int deg;

struct ln {
	ll a, b;
	ll at(ll x){
		return a*x + b;
	}
} lns[MAXN];

inline int novo(ll a, ll b){
	assert(deg < MAXN);
	lns[deg++] = {a, b};	
	return deg-1;
}

//cmp fracao
/*
inline bool men(pll a, pll b){
	assert(b.snd >= 0 && a.snd >= 0);
	if(a.snd < 0){
		a.snd *= -1;
		a.fst *= -1;
	}
	if(b.snd < 0){
		b.snd *= -1;
		b.fst *= -1;
	}
	return (a.fst*b.snd < a.snd*b.fst);
}
*/

inline bool men(double a, double b){
	return a < b;
}

//interseccao de duas retas de lns em fracao
inline pll fint2(int i, int j){
	assert(i > 0 && j > 0 && i < MAXN && j < MAXN);
	return pll(lns[j].b - lns[i].b, lns[i].a - lns[j].a);
}

inline double fint(int i, int j){
	assert(i > 0 && j > 0 && i < MAXN && j < MAXN);
	return (double(lns[j].b - lns[i].b)/(lns[i].a - lns[j].a));
}

inline bool cmp(int i, int j, int k){
	//deve retirar j do convex?
	return !men(fint(i, j), fint(j, k));
}

inline ll qry(int u, ll x){
	if(u == 0) return 0;
	ll ans = lns[u].at(x);
	for(int i=LOGN-1;i>=0;i--){
		int v = p[u][i];
		int vv = nxt[v];
		if(vv == 0) continue;
		//pll f = fint(vv, v);
		double f = fint(vv, v);
		//if(men(pll(x, 1), f))
		if(men((double)x, f))
			u = p[u][i];
	}
	ans = min(ans, lns[u].at(x));
	u = nxt[u];
	if(u != 0)
		ans = min(ans, lns[u].at(x));
	return ans;
}

void go(int u, int pai, int nd){
	int id = 0;
	if(u != 1){
		ll x = v[u];
		dp[u] = d[u]*v[u] + s[u] + min(0ll, qry(nd, x));
		id = novo(-d[u], dp[u]);
		for(int i=LOGN-1;i>=0;i--){
			int nnd = p[nd][i];
			if(nxt[nnd] == 0 || nnd == 0) continue;
			if(cmp(nxt[nnd], nnd, id)){
				nd = nxt[nnd];	
			}
		}
		while(nxt[nd] != 0){
			if(!cmp(nxt[nd], nd, id)) break;
			nd = nxt[nd];
			assert(nd >= 0 && nd < MAXN);
		}
		
		p[id][0] = nd;
		nxt[id]  = nd;
		for(int i = 1;i<LOGN;i++)
			p[id][i] = p[p[id][i-1]][i-1];
	}

	for(pil ar: adj[u]){
		int nxt = ar.fst;
		if(nxt == pai) continue;
		ll dis = ar.snd;
		d[nxt] = d[u] + dis;
		go(nxt, u, id);
	}
}

int main (){
	deg = 1;
	scanf("%d", &n);
	for(int a=1;a<n;a++){
		int i, j;
		ll c;
		scanf("%d %d %lld", &i, &j, &c);
		adj[i].pb(pil(j, c));
		adj[j].pb(pil(i, c));
	}
	for(int a=2;a<=n;a++){
		scanf("%lld %lld", s+a, v+a);
	}
	go(1, 1, 0);
	for(int a=2;a<=n;a++)
		printf("%lld%c", dp[a], " \n"[a==n]);
}

