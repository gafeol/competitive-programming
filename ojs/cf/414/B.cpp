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

const int MAXN = 2123;

int n, m, k;
int s[MAXN];

ll dp[MAXN][MAXN];

ll go(int i, int d){
	ll &r = dp[i][d];
	if(r != -1) return r;
	if(i == n) return r = 1;
	r = 0;
	for(int a=1;a*d <= k;a++){
		r = mod(r + go(i+1, d*a));
	}
	return r;
}

int main (){
	scanf("%d%d", &k, &n);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(0, 1));
}

