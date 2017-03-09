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

const int MAXN = 4002;

int n, m, k;
ll dp[MAXN][MAXN][2];

ll go(int i, int gr, int foi){
	ll &r = dp[i][gr][foi];
	if(r != -1)
		return r;
	
	if(i == n)
		return r = foi;	
	
	r = go(i+1, gr, 1);
	if(gr != 0) r = mod(r + gr*go(i+1, gr, foi)); 
	r = mod(r + go(i+1, gr+1, foi));
	
	return r;
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	printf("%lld\n", go(0, 0, 0));
}
