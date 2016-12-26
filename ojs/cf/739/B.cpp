
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
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
#define int ll

const int MAXN = 212345;

int n, m, k, deg;
int s[MAXN], p[MAXN], w[MAXN];
int res[MAXN], cte[MAXN], ind[MAXN];
multiset<int> v[MAXN];
vector<pii> adj[MAXN];

void join(int u, int nxt){
	debug("join %lld -%lld com %lld -%lld\n", u, ind[u], nxt, ind[nxt]);
	if(v[ind[u]].size() < v[ind[nxt]].size())
		swap(ind[u], ind[nxt]);
	for(auto& x: v[ind[nxt]]){
		debug("bota em v[ind[%lld]] o valor %lld + %lld - %lld\n", u, x, cte[ind[nxt]], cte[ind[u]]);
		v[ind[u]].insert(x + cte[ind[nxt]] - cte[ind[u]]);
	}
	debug("fim join u %lld %lld v %lld %lld\n", u, ind[u], nxt, ind[nxt]);
}

void printt(int u){
	debug("\nprintt %lld\n", u);
	debug("cte %lld\n", cte[ind[u]]);
	for(auto& x: v[ind[u]]){
		debug("%lld ", x);
	}
	debug("\n");
}

void go(int u){
	ind[u] = u;
	cte[u] = 0;
	for(pii nxt: adj[u]){
		go(nxt.fst);
		cte[ind[nxt.fst]] -= w[nxt.fst];
		join(u, nxt.fst);
		printt(u);
	}
	auto it2 = v[ind[u]].end();
	auto it = v[ind[u]].lower_bound(-cte[ind[u]]);
	res[u] = distance(it, it2);
	v[ind[u]].insert(s[u]-cte[ind[u]]);
	debug("sai %lld\n", u);
	printt(u);
}

main (){
	scanf("%lld", &n);
	for(int a=1;a<=n;a++){
		scanf("%lld", &s[a]);
	}
	for(int a=2;a<=n;a++){
		scanf("%lld%lld", &p[a], &w[a]);
		adj[p[a]].pb(pii(a, w[a]));
	}
	go(1);
	for(int i=1;i<=n;i++){
		printf("%lld ", res[i]);
	}
}
