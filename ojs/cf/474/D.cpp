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
int s[MAXN];

ll dp[MAXN];
ll acu[MAXN];

int main (){
	scanf("%d%d", &n, &k);
	dp[0] = 1;
	acu[0] = 1;
	for(int i=0;i<=100000;i++){
		dp[i+1] = mod(dp[i+1] + dp[i]);
		dp[i+k] = mod(dp[i+k] + dp[i]); 
		if(i > 0)
			acu[i] = mod(acu[i-1] + dp[i]);
	}
	for(int a=0;a<n;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		printf("%lld\n", mod(modn + mod(acu[j] - acu[i-1])));
	}
}

