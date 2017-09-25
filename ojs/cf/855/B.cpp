
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
const ll INF = 3e18 + 100;

int n, m;
ll s[MAXN];
int ind[10];
ll c[4];

ll dp[MAXN][5];

ll go(int i, int j){
	if(j == 3) return 0;
	if(i == n) return -INF-10;
	if(dp[i][j] != -INF) return dp[i][j];
	dp[i][j] = max(go(i+1, j), go(i, j+1) + c[j]*s[i]);
	return dp[i][j];
}

int main (){
	ll A, B, C;
	scanf("%d%lld%lld%lld", &n, &c[0], &c[1], &c[2]);
	for(int a=0;a<=n;a++){
		for(int b=0;b<=3;b++){
			dp[a][b] = -INF;
		}
	}
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
	}
	printf("%lld\n", go(0, 0));
}

