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

const int MAXN = 312, MAXW = 8123, INF = 8000;

int n, m, k;
int s[MAXN];

int dp[MAXN][MAXW];

int go(int i, int w){
	if(i == -1) return (w >= 0 ? 0:-INF);
	if(dp[i][w] != -1) return dp[i][w];
	dp[i][w] = go(i-1, w);
	if(s[i] <= w){
		if(w == INF)
			dp[i][w] = max(dp[i][w], 1+go(i-1, s[i]*6));
		else
			dp[i][w] = max(dp[i][w], 1+go(i-1, min(s[i]*6, w-s[i])));
	}
	return dp[i][w];
}

int main (){
	for_tests(t, tt){
		memset(dp, -1, sizeof(dp));
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			scanf("%d", s+a);
		}
		printf("Case #%d: %d\n", tt, go(n-1, INF));
	}
}

