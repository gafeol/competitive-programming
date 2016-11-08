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

const int MAXN = 1001;

int n, m, k;
int dp[MAXN][MAXN][11];
char s[MAXN][2];

int go(int i, int j, int kk){
	if(dp[i][j][kk] != -1) return dp[i][j][kk];
	if(kk == k || i == n || j == m)
		return dp[i][j][kk] = 0;
	int ans = 0;
	int ii = i;
	int jj = j;
	while(ii < n && jj < m && s[ii][0] == s[jj][1]){
		ii++;
		jj++;
	}
	ans = max(ans, go(ii, jj, kk+1) + ii - i);
	ans = max(ans, go(i+1, j, kk));
	ans = max(ans, go(i, j+1, kk));
	return dp[i][j][kk] = ans;
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf("%d%d%d", &n, &m, &k);
	for(int a=0;a<n;a++){
		scanf(" %c", &s[a][0]);
	}
	for(int a=0;a<m;a++){
		scanf(" %c", &s[a][1]);
	}
	printf("%d\n", go(0, 0, 0));
}
