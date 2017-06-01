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

const int MAXN = 4123, INF = 0x3f3f3f3f;

int n, m, k;
int A, B, C;

int dp[MAXN];

int go(int i){
	if(i < 0)
		return -INF;
	if(dp[i] == -1)
		dp[i] = 1 + max(max(go(i - A), go(i - B)), go(i - C));
	return dp[i];
}

int main (){
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	scanf("%d %d %d %d", &n, &A, &B, &C);
	printf("%d\n", go(n));
}
