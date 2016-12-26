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

const int MAXN = 212345;

int n, m, k, deg;
int s[MAXN], p[MAXN], w[MAXN];
int res[MAXN], cte[MAXN], ind[MAXN];
set<int> v[MAXN];
vector<pii> adj[MAXN];

void join(int u, int nxt){
	debug("join %d -%d com %d -%d\n", u, ind[u], nxt, ind[nxt]);
	if(v[ind[u]].size() < v[ind[nxt]].size())
		swap(ind[u], ind[nxt]);
	for(auto& x: v[ind[nxt]]){
		debug("bota em v[ind[%d]] o valor %d + %d - %d\n", u, x, cte[ind[nxt]], cte[ind[u]]);
		v[ind[u]].insert(x + cte[ind[nxt]] - cte[ind[u]]);
	}
	debug("fim join u %d %d v %d %d\n", u, ind[u], nxt, ind[nxt]);
}

void go(int u){
	ind[u] = u;
	cte[u] = 0;
	for(pii nxt: adj[u]){
		go(nxt.fst);
		cte[nxt.fst] += w[nxt.fst];
		join(u, nxt.fst);
	}
	auto it = v[ind[u]].begin();
	auto it2 = v[ind[u]].lower_bound(s[u]-cte[ind[u]]);
	res[u] = distance(it, it2);
	v[ind[u]].insert(0);

}

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
	}
	for(int a=2;a<=n;a++){
		scanf("%d%d", &p[a], &w[a]);
		adj[p[a]].pb(pii(a, w[a]));
	}
	go(1);
	for(int i=1;i<=n;i++){
		printf("%d ", res[i]);
	}
}
