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
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1123;

int n, M, k;
int s[MAXN];
int sq[MAXN], sum[MAXN];


int dp[MAXN][MAXN], opt[MAXN][MAXN];

int cus(int i, int j){
	if(i-1 == j)
		return 0;
	return ((sum[j] - sum[i-1])*(sum[j] - sum[i-1]) - (sq[j] - sq[i-1]))/2;
}

void solve(int i, int j, int opti, int optj, int k){
	if(i > j) return;
	int m = (i + j)/2;
	for(int a=opti;a<=min(m, optj);a++){
//		printf("testa com %d\ndp[%d][%d] %d + cus(%d, %d) %d\n", a, a, k-1, dp[a][k-1], a+1, m, cus(a+1, m)); 
		if(dp[m][k] > dp[a][k-1] + cus(a+1, m)){
			dp[m][k] = dp[a][k-1] + cus(a+1, m);
			opt[m][k] = a;
		}
 	}
//	printf("dp[%d][%d] %d\nopt[%d][%d] %d\n\n", m, k, dp[m][k], m, k, opt[m][k]);
	solve(i, m-1, opti, opt[m][k], k);
	solve(m+1, j, opt[m][k], optj, k);
}

int main (){
	while(scanf("%d%d", &n, &M)!= EOF && n+M){
		memset(dp, 0x3f3f3f3f, sizeof(dp));
		dp[0][0] = 0;
		for(int a=1;a<=n;a++){
			scanf("%d", &s[a]);
			sum[a] = sum[a-1] + s[a];
			sq[a] = sq[a-1] + s[a]*s[a];
			dp[a][0] = cus(1, a);
		}
		for(int a=1;a<=M;a++){
			solve(1, n, 0, n, a);
		}
		printf("%d\n", dp[n][M]);
	}
}
