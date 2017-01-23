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

int n;
ll s[MAXN], dp[MAXN], sum[MAXN];

int bb(int i, int j, ll val){
	int ini = i;
	while(i < j){
		int m = (i + j+1)/2;
		if(s[m] > val)
			j = m-1;
		else
			i = m;
	}
	return i;
}

int main(){
	scanf("%d", &n);
	for(int a=0;a<=n;a++){
		dp[a] = LLONG_MAX;
	}
	for(int a=1;a<=n;a++){
		scanf("%lld", &s[a]);
	}
	dp[0] = 0;
	dp[1] = 20;
	for(int a=1;a<=n;a++){
		dp[a+1] = min(dp[a+1], dp[a]+20);
		int i = bb(a, n, s[a]+90-1);
		dp[i] = min(dp[i], dp[a-1] + 50);
		i = bb(a, n, s[a]+1440-1);
		dp[i] = min(dp[i], dp[a-1] + 120);
	}
	for(int a=n-1;a>=1;a--){
		if(dp[a] > dp[a+1])
			dp[a] = dp[a+1];
	}
	for(int a=1;a<=n;a++){
		printf("%lld\n", dp[a] - dp[a-1]);
	}
}
