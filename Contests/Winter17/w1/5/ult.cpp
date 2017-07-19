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

int n, m, k;
ll d;
ll mx[MAXN];
int s[MAXN], nv[MAXN];

vector<int> adj[MAXN];

void pre(int u, int p, int dist){
	for(int nxt: adj[u]){
		if(nxt == p) continue;
		pre(nxt, u, dist+1);
		nv[u] += nv[nxt];
		mx[u] = max(mx[u], mx[nxt]);
	}
	nv[u]++;
	d += dist;
}

void dfs(int u, int p){
	int mxv = 0, imxv;
	for(int nxt: adj[u]){
		mxv = max(mxv, nv[nxt]);
		if(mxv == nv[nxt])
			imxv = nxt;
	}
	debug("u %d\n mx[u] %d d %d nv[u] %d\n", u, mx[u], d, nv[u]);
	if(mxv*2 == n){
		printf("%lld\n", 2*d - mx[imxv] - 1);
	}
	else if(mxv*2 < n)
		printf("%lld\n", 2*d - mx[u]);
	else
		puts("-1");
	for(int nxt: adj[u]){
		if(nxt == p) continue;
		nv[u] -= nv[nxt];
		d -= nv[nxt];
		nv[nxt] += nv[u];
		d += nv[u];
		mx[u] = -1;
		for(int nnxt: adj[u]){
			if(nnxt == nxt) continue;
			mx[u] = max(mx[u], mx[nnxt]);
		}
		mx[nxt] = max(mx[nxt], mx[u]);
		dfs(nxt, u);
	}
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n-1;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	pre(1, 1, 0);
	dfs(1, 1);
}
