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
ll s[MAXN];
ll dp[MAXN][2];

ll go(int i, int foi){
	if(dp[i][foi] == -1){
		dp[i][foi] = max(dp[i][foi], go(i+1, 0));
		if(foi == 0) dp[i][foi] = max(dp[i][foi], go(i+1, 1) + s[i]);
	}
	return dp[i][foi];
}

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		memset(dp, -1, sizeof(dp));
		dp[n+1][0] = dp[n+1][1] = 0;
		for(int a=1;a<=n;a++){
			scanf("%lld", &s[a]);	
		}
		printf("Case %d: %lld\n", tt, go(1, 0)); 
	}
}
