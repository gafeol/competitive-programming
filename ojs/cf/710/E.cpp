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

const int MAXN = 10000005;

ll n, m, k;

ll dp[MAXN];

int main (){
	for(int a=0;a<MAXN;a++){
		dp[a] = LLONG_MAX;
	}
	scanf("%lld%lld%lld", &n, &m, &k);
	dp[0] = 0;
	for(ll a=0;a<=n;a++){
//		debug("dp[%lld] %lld\n", a, dp[a]);
		ll nxt = a*2ll;
		if(nxt <= n){
			assert(nxt > MAXN);
			dp[nxt] = min((nxt - a)*m + dp[a], dp[nxt]);
			dp[nxt] = min(dp[nxt], dp[a] + k);
		}
		nxt++;
		assert(nxt < MAXN);
		if(nxt <= n){
			dp[nxt] = min((nxt - a)*m + dp[a], dp[nxt]);
			dp[nxt] = min(dp[nxt], dp[a] + k + m);
		}
		nxt-=2;
		assert(nxt < MAXN);
		if(nxt > a){
			dp[nxt] = min((nxt - a)*m + dp[a], dp[nxt]);
			dp[nxt] = min(dp[nxt], dp[a] + k + m);
		}
	}
	printf("%lld\n", dp[n]);
}
