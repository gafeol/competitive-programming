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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1123;
const ll INF = 2000000000LL;

int n, m, k;
ll s[MAXN], tim[MAXN];
int x;
int t;

vector<int> adj[MAXN];

ll dp[MAXN][MAXN];

ll go(int u, int tot){
	debug("go u %d tot %d\n", u, tot);
	if(tot > x) return INF;
	ll &r = dp[u][tot];
	if(r != -1) return r;
	r = INF;
	if(u == 0 && tot == x) return r = 0;
	r = min(r, go(u, tot + tim[u]) + s[u]);
	for(int nxt: adj[u]){
		debug("u %d -> %d\n", u, nxt);
		r = min(r, go(nxt, tot + t + tim[nxt]) + s[nxt]);
	}
	return r;
}

int main (){
	scanf("%d", &x);
	scanf("%d%d%d", &n, &m, &t);
	memset(dp, -1, sizeof(dp));
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);	
		i--;j--;
		adj[i].pb(j);
		adj[j].pb(i);

	}
	for(int a=0;a<n;a++){
		scanf("%lld%lld", tim+a, s+a);
	}
	ll res = go(0, tim[0]) + s[0];
	if(res >= INF)
		puts("It is a trap.");
	else
		printf("%lld\n", res);
}

