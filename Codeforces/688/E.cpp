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

const int MAXN = 510;

int n, m, dp[2][MAXN][MAXN], s[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
	}
	dp[0][0][0] = 1;
	for(int i=1;i<=n;i++){
		int u = i&1;
		int v = 1 - u;
		for(int j = 0;j <= m;j++){
			for(int k=0;k<=m;k++){
				dp[u][j][k] = 0;
				dp[u][j][k] |= dp[v][j][k];
				if(j - s[i] >= 0){
					dp[u][j][k] |= dp[v][j-s[i]][k];
					if(k - s[i] >= 0)
						dp[u][j][k] |= dp[v][j-s[i]][k-s[i]];
				}
			}
		}
	}
	int cnt = 0;
	for(int j = 0;j <= m;j++){
		if(dp[n&1][m][j])
			cnt++;
	}
	printf("%d\n", cnt);
	for(int j = 0;j<=m;j++){
		if(dp[n&1][m][j])
			printf("%d ", j);
	}
}
