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

const int MAXN = 83;
const int INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];

vector<pii> adj[MAXN];

int dp[MAXN][MAXN][MAXN][MAXN], d[MAXN];

int go(int u, int mn, int mx, int kk){
	if(dp[u][mn][mx][kk] != -1)
		return dp[u][mn][mx][kk];

	int &r = dp[u][mn][mx][kk];
	if(kk == k)
		return r = 0;

	r = INF;

	for(pii nxt: adj[u]){
		int nx = nxt.fst;
		int c = nxt.snd;
		if(nx <= mn || nx >= mx || nx == u)
			continue;
		r = min(r, c + min(go(nx, max(mn, nx), mx, kk+1), go(nx, mn, min(mx, nx), kk+1)));
	}
	return r;
}

int main (){
	scanf("%d%d", &n, &k);
	scanf("%d", &m);
	memset(dp, -1,sizeof(dp));
	for(int a=0;a<m;a++){
		int i, j, c;
		scanf("%d%d%d", &i, &j, &c);
		adj[i].pb(pii(j, c));
	}
	int ans = INT_MAX;
	for(int a=1;a<=n;a++){
		ans = min(ans, min(go(a, a, n+1, 1), go(a, 0, a, 1)));
	}
	if(ans >= INF)
		ans = -1;
	printf("%d\n", ans);
}
