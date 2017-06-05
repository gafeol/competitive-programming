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
ll dp[MAXN];
ll pot[MAXN];
ll s[MAXN];

int main (){
	pot[0] = 1;
	for(int a=1;a<MAXN-5;a++){
		pot[a] = mod(2ll*pot[a-1]);
	}
	for_tests(t, tt){
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			scanf("%lld", &s[a]);
			s[a] = mod(s[a]);
		}
		dp[n-1] = s[n-1];
		for(int a=n-2;a>=0;a--){
			dp[a] = mod(mod(s[a]*dp[a+1]) + mod(mod(s[a]*pot[n-2 - a]) + dp[a+1]));
		}
		printf("%lld\n", dp[0]);
	}
}
