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

const int MAXN = 100004, MAXF = 1123, INF = 0x3f3f3f3f;

int n, m, k;
//int dp[MAXN][MAXF], t[MAXN][MAXF];
int dp[MAXN][MAXF];
int tempo;
int cus[MAXF]; 

int go(int l, int i){
	if(l < 0 || i < 0)
		return INF;
	if(dp[l][i] != -1)
		return dp[l][i];
	dp[l][i] = INF;
	dp[l][i] = min(dp[l][i], go(l-cus[i], i-1)+1);
	dp[l][i] = min(dp[l][i], go(l, i-1));

	return dp[l][i];
}

int main (){
	scanf("%d", &k); 
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		scanf("%d", &cus[a]);
	}
	if(go(k, n) >= INF)
		puts("N");
	else
		printf("S\n");
}
