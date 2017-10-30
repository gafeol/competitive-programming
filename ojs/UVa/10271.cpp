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

const int MAXN = 5123, MAXK = 1123;

const ll INF = 100000000000000LL;

int n, m, k;
ll s[MAXN];

ll dp[MAXN][MAXK];

bool cmp(int a, int b){
	return a > b;
}

ll go(int i, int nc){
	if(dp[i][nc] != -1) return dp[i][nc];

	if(nc == k) return dp[i][nc] = 0;
	if(i >= n-1) return dp[i][nc] = INF;

	dp[i][nc] = INF;

	dp[i][nc] = min(dp[i][nc], go(i+1, nc));

	if(i-1 >= nc*3)
		dp[i][nc] = min(dp[i][nc], go(i+2, nc+1) + (s[i] - s[i+1])*(s[i] - s[i+1]));
	
	return dp[i][nc];
}

int main (){
	for_tests(t, tt){
		scanf("%d%d", &k, &n);
		k += 8;
		for(int a=0;a<n;a++){
			scanf("%lld", s+a);
		}
		sort(s, s+n, cmp);
		memset(dp, -1, sizeof(dp));
		printf("%lld\n", go(0, 0));
	}
}

