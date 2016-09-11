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

const int MAXN = 110;

const ll INF = 1e11 + 1;

int n, m, k, c[MAXN];

ll dp[MAXN][MAXN][MAXN], p[MAXN][MAXN];

ll go(int i, int uc, int kk){
	if(dp[i][uc][kk] != -1) return dp[i][uc][kk];
	if(kk > k) return dp[i][uc][kk] = INF;
	if(i == n){
		if(kk == k)
			return dp[i][uc][kk] = 0;
		else
			return dp[i][uc][kk] = INF;
	}
	dp[i][uc][kk] = INF;
	if(c[i] != 0)
		dp[i][uc][kk] = min(dp[i][uc][kk], go(i+1, c[i], kk+(uc != c[i])));
	else{
		for(int a=0;a<m;a++){
			dp[i][uc][kk] = min(dp[i][uc][kk], go(i+1, a+1, kk+(uc != a+1)) + p[i][a]);
		}
	}
	return dp[i][uc][kk];
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf("%d %d%d", &n, &m, &k);
	for(int a=0;a<n;a++){
		scanf("%d", &c[a]);
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			scanf("%lld", &p[a][b]);
		}
	}
	if(go(0, 0, 0) >= INF)
		puts("-1");
	else{
		printf("%lld", go(0, 0, 0));
	}
}
