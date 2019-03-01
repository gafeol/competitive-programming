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

const int MAXN = 312345;
const int INF = 0x3f3f3f3f;

int n, m, k;
ll dp[MAXN][2];

ll s[MAXN][2];



int main (){
	scanf("%d%d", &n, &k);
	for(int t=0;t<2;t++)
		for(int a=1;a<=n;a++)
			scanf("%lld", &s[a][t]);


	memset(dp, INF, sizeof(dp));
	dp[0][0] = dp[0][1] = 0;

	for(int i=1;i<=n;i++){

		//printf("val %d %d\n", s[i][0], s[i][1]);
		for(int t=0;t<2;t++){
			// t -> t
			ll px = dp[i-1][t];
			ll x = s[i][t];
			ll y = s[i][1-t];

			if(px > k) continue;

			if(x*k >= y && px + x <= y*k)
				dp[i][t] = min(dp[i][t], 1ll);
			else if(px + x > y*k)
				dp[i][t] = min(dp[i][t], px + x - y*k);	

			// t -> 1 - t
			if(x*k >= y && x + px <= y*k)
				dp[i][1 - t] = min(dp[i][1-t], 1ll);

			else if(y > x*k)
				dp[i][1 - t] = min(dp[i][1-t], y - x*k);
			
		}
		//printf("A %d x %d y %d\n", i, dp[i][0], dp[i][1]);
	}

	puts((min(dp[n][0], dp[n][1]) <= k ? "YES" : "NO"));
}

