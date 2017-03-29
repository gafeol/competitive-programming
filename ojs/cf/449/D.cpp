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

const int MAXN = (1<<20)+10;

int n, m, k;
int s[MAXN];

ll dp[MAXN][22];

ll expo(ll x){
	if(x == 0) return 1;

	ll ans = expo(x/2);
	ans = mod(ans*ans);

	if(x&1)
		ans = mod(ans*2);

	return ans;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		dp[s[a]][0]++;
	}
	for(int a=(1<<20)-1;a>=0;a--){
		for(int i = 0;i < 20;i++){
			dp[a][i+1] = dp[a][i];
			if(!(a&(1<<i))){
				dp[a][i+1] = mod(dp[a][i+1] + dp[a|(1<<i)][i]);
			}
			if(dp[a][i+1] != 0){
				debug("dp[%d][%d] %lld\n", a, i+1, dp[a][i+1]);
			}
		}
	}
	ll res = 0;
	for(int a=0;a<(1<<20);a++){
			res = mod(modn+mod(res + ((__builtin_popcount(a)&1) ? -1:1)*expo(dp[a][20])));
			//debug("a %d soma %lld\n", a, ((__builtin_popcount(a)&1) ? -1:1)*(1ll<<(dp[a][20])));
	}
	printf("%lld\n", mod(modn + res));
}
