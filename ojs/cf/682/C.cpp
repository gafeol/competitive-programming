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

int n, m, k, sz[MAXN], mrk[MAXN], pai[MAXN], sz2[MAXN];
ll s[MAXN], d[MAXN], res;

vector<pii> adj[MAXN];

void go(int u, int p){
	sz[u] = 1;
	for(pii nxt: adj[u]){
		int v = nxt.fst;
		if(v == p) continue;
		ll c = nxt.snd;
		d[v] = max(0ll, d[u] + c); 
		go(v, u);
		sz[u]+=sz[v];
	}
}

void go2(int u, int p){
	if(d[u] > s[u]){
		debug("achei alguem u %d  %lld %lld\n", u, d[u], s[u]);
		res += sz[u];
		return;
	}
	for(pii nxt: adj[u]){
		int v = nxt.fst;
		if(v == p) continue;
		ll c = nxt.snd;
		go2(v, u);
	}
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		scanf("%lld", &s[a]);
	}
	for(int a=2;a<=n;a++){
		int i;
		ll c;
		scanf("%d%lld", &i, &c);
		adj[a].pb(pii(i, c));
		adj[i].pb(pii(a, c));
	}
	d[1] = 0;
	go(1, 1);
	go2(1, 1);
	printf("%lld\n", res);
}
