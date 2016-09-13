#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod2(ll x) { return x % modn; }
inline  ll mod(ll x){ ll ans = mod2(x); if(ans < 0){ ans = ans + modn; } return ans; }

const int MAXN = 612345, Z = 312000;

int n, m, k, t;
ll dp[MAXN][3], s[MAXN];

ll f(int i){
	if(i > 2*k + 1)
		i = 2*k + 1 - (i - (2*k + 1));
	return i;
}

int main (){
	scanf("%d%d%d%d", &n, &m, &k, &t);
	dp[n - m + Z][0] = 1;
	for(int i = 1;i <= t;i++){
		int ii = i&1;
		for(int a=0;a<MAXN;a++){
			if(a != 0) s[a] = s[a-1];
			else s[a] = 0;
			s[a] = mod(s[a] + dp[a][1-ii]);
			dp[a][ii] = 0;
		}
		ll sum = 0;

		for(int a=1;a<=4*k+1;a++){
			sum = mod(sum + f(a)*dp[a][1-ii]);
		}
		for(int a=2*k+1;a<MAXN - 2*k-1;a++){
			dp[a][ii] = sum;
			if(sum != 0 && sum < 1000){
				printf("dp[%d][%d] = %lld\n", a, ii, dp[a][ii]);

			}
			sum = mod(sum - (s[a] - s[a - 2*k - 1]));
			sum = mod(sum + (s[a + 2*k + 1] - s[a]));

		}
	}
	ll ans = 0;
	for(int a=Z+1;a<MAXN;a++){
		ans = mod(ans + dp[a][t&1]);
	}
	printf("%lld\n", ans);
}
