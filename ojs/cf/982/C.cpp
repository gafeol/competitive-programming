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
int s[MAXN];

int sz[MAXN];

vector<int> adj[MAXN];

int dfs(int u, int p){
	sz[u] = 1;
	for(int nxt: adj[u]){
		if(nxt == p) continue;
		sz[u] += dfs(nxt, u);
	}
	return sz[u];
}

int go(int u, int p){
	int ans = 0;
	for(int nxt: adj[u]){
		if(nxt == p) continue;
		if(!(sz[nxt]&1))
			ans += 1 + go(nxt, u);	
		else
			ans += go(nxt, u);
	}
	return ans;
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<n;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	if(n&1){
		puts("-1");
		return 0;
	}
	dfs(1, 1);
	printf("%d\n", go(1, 1));

}

