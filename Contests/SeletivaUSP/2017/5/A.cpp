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

const int MAXN = 2123, MAXK = 23;
ll INF = 1000000000000ll;

int n, m, k;
ll s[MAXN];
ll sum[MAXN];

ll dp[MAXN][MAXN][MAXK];

ll aprox(int i, int j){
	ll val = 0;
	if(j == 0)
		val =  sum[i];
	else
		val = sum[i] - sum[j-1];
	if((val%10) < 5)
		val -= (val%10);
	else{
		val -= (val%10);
		val += 10ll;
	}
	return val;
}

ll go(int i, int bef, int d){
	if(d < 0)
		return INF;

	if(i == n){
		if(bef == n)
			return 0;
		return aprox(i-1, bef);
	}

	ll &r = dp[i][bef][d];

	if(r != -1)
		return r;

	r = min(go(i+1, bef, d), go(i+1, i+1, d-1) + aprox(i, bef));	

	return r;
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);	
		sum[a] = s[a];
		if(a != 0)
			sum[a] += sum[a-1];
	}
	printf("%lld\n", min(go(0, 0, k), aprox(n-1, 0)));
}
