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

const int MAXN = 1123456;

int n, m, k;
ll s[MAXN];
ll dp[10][3];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld", &s[a]);
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for(int i=0;i<n;i++){
		int t = (i&1);
		for(int a=0;a<7;a++){
			int aa = (a + s[i])%7;
			if(dp[a][t] != -1){
				dp[a][1-t] = max(dp[a][1-t], dp[a][t]);
				dp[aa][1-t] = max(dp[aa][1-t], dp[a][t] + s[i]);
			}
			dp[a][t] = -1;
		}
		dp[0][t] = 0;
	}
	printf("%lld\n", dp[0][(n&1)]);
}
