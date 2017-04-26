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

const int MAXN = 5123;

int n, m, kk;
int s[MAXN];
double dp[MAXN][MAXN];


double go(int i, int k){
	if(k == 0 || i == n) return dp[i][k] = 0;
	if(
}

int main (){
	scanf("%d%d", &n, &kk);
	memset(dp, -1, sizeof(dp));
	for(int a=0;a<n;a++){
		scanf("%d %d", &s[a], &t[a]);
	}
	printf("%.10f\n", go(0, kk));
}
