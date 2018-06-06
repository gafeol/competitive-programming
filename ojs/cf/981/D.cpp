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

const int MAXN = 52;

int n, m, sh;
ll s[MAXN];

int dp[MAXN][MAXN];

ll fx;

int go(int i, int k){
	if(dp[i][k] != -1) return dp[i][k];
	if(i == n) return dp[i][k] = (k == 0);
	dp[i][k] = 0;
	ll sum = 0;
	for(int j=i;j<n;j++){
		sum += s[j];
		if((sum&fx) == fx){
			dp[i][k] = max(dp[i][k], go(j+1, k-1));
		}
	}
	return dp[i][k];
}

int main (){
	scanf("%d%d", &n, &sh);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
	}
	ll ans = 0;
	for(ll i = 60;i>=0;i--){
		fx = (ans|(1ll<<i));
		memset(dp, -1, sizeof(dp));
		if(go(0, sh))
			ans |= (1ll<<i);
	}
	printf("%lld\n", ans);
}

