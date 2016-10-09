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

const int MAXN = 4123, INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN][MAXN], c[MAXN][MAXN];
int dp[MAXN][MAXN], opt[MAXN][MAXN];

int cus(int i, int j){
	// i > j
	return c[i][i] - c[i][j-1] - c[j-1][i] + c[j-1][j-1];
}

void solve(int i, int j, int opti, int optj, int kk){
	if(i > j) return;
	int m = (i+j)/2;
	for(int a=opti;a<=min(m-1, optj);a++){
		if(dp[m][kk] > dp[a][kk-1] + cus(m, a+1)){
			dp[m][kk] = dp[a][kk-1] + cus(m, a+1);
			opt[m][kk] = a;
		}
	}
//	printf("dp[%d][%d] %d\nopt[%d][%d] %d\n\n", m, kk, dp[m][kk], m, kk, opt[m][kk]);
	solve(i, m-1, opti, opt[m][kk], kk);
	solve(m+1, j, opt[m][kk], optj, kk);
}

int main (){
	scanf("%d%d\n", &n, &k);
	k--;
	memset(dp, INF, sizeof(dp));
	for(int a=1;a<=n;a++){
		for(int b=1;b<=n;b++){
			char ch;
			ch = getchar();
			getchar();
			s[a][b] = ch-'0';
			c[a][b] = s[a][b] + c[a-1][b] + c[a][b-1] - c[a-1][b-1];
		}
	}
	for(int a=0;a<=n;a++){
		dp[a][0] = c[a][a];
	}
	for(int kk = 1;kk <= k;kk++){
		solve(1, n, 0, n, kk);
	}
	printf("%d\n", dp[n][k]/2);
}
