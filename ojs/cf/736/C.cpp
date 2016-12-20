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

const int MAXN = 212, MAXK = 22;

int n, m, k;
int s[MAXN], mrk[MAXN], desl[MAXN];
ll dp[MAXN][MAXN][MAXK];
int tempo;
vector<int> adj[MAXN];


ll go(int u, int ini, int l){
	ll &r = dp[u][ini][l];
	if(r != -1)
		return r; 
	if(l > k) return r = 0;
	mrk[u] = tempo;
	dp[u][ini][l] = 0;
	int fol = 1;
	for(int nxt: adj[u]){
		if(mrk[nxt] != tempo){
			fol = 0;
			if(desl[nxt]){
				dp[u][ini][l] = mod(dp[u][ini][l] + go(nxt, ini, l+1));
			}
			else{
				if(ini == u)
					dp[u][ini][l] = mod(dp[u][ini][l] + go(nxt, ini, l+1));
				else if(l != k)
					dp[u][ini][l] = mod(dp[u][ini][l] + go(nxt, ini, l+1) + go(nxt, ini, 0));
				else
					dp[u][ini][l] = mod(dp[u][ini][l] + go(nxt, ini, 0));
			}
		}
	}
	if(desl[u] && l == k && !fol) return r = 0;
	if(fol){
		r = 1;
	}
	debug("dp[%d][%d][%d]: %lld\n", u, ini, l, dp[u][ini][l]);
	return dp[u][ini][l];
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &k);
	for(int a=0;a<n-1;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	ll res = 0;
	for(int a=1;a<=n;a++){
		tempo++;
		res = mod(res + go(a, a, 0));
		desl[a] = 1;
	}
	printf("%lld\n", res);
}
