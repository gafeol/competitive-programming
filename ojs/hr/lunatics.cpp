#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef unsigned long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 8123, MAXK = 812;

int n, m;
ll s[MAXN], sum[MAXN];

ll dp[MAXN][MAXK], opt[MAXN][MAXK];

ll cus(int i, int j){
	// i incluso
	return (sum[j] - sum[i-1])*((ll)j - (ll)i + 1ll);
}

void solve(int i, int j, int opti, int optj, int k){
	if(i > j)
		return ;
	int m = (i + j)/2;
	for(int a = opti; a<=min(m-1, optj);a++){
		if(dp[m][k] > dp[a][k-1] + cus(a+1, m)){
			dp[m][k] = dp[a][k-1] + cus(a+1, m);
			opt[m][k] = a;
		}
	}
	solve(i, m-1, opti, opt[m][k], k);
	solve(m+1, j, opt[m][k], optj, k);
}

int main (){
	scanf("%d%d", &n, &m);
	m--;
	if(m > n)
		m = n;
	for(int a=0;a<=n;a++){
		for(int b=0;b<=m;b++){
			dp[a][b] = 9e15;
		}
	}
	dp[0][0] = 0;
	for(int a=1;a<=n;a++){
		scanf("%llu", &s[a]);
		sum[a] = sum[a-1] + s[a];
		dp[a][0] = cus(1, a);
	}
	for(int a=1;a<=m;a++){
		solve(1, n, 0, n, a);
	}
	printf("%llu\n", dp[n][m]);
}
