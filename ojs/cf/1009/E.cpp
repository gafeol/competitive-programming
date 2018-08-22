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
const ll modn = 998244353;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1123456;
int n, m, k;
ll s[MAXN], dp[MAXN], val[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
	}
	ll sum = 0;
	for(int a=0;a<n;a++){
		if(a > 0)
			val[a] = mod(2ll*val[a-1]);
		val[a] = mod(val[a] + s[a]);
		//debug("%lld ", val[a]);
	}
	ll sumd = 0;
	for(int a=n-1;a>=0;a--){
		dp[a] =  mod(sumd + val[n-1 - a]);
		sumd = mod(sumd + dp[a]);
	}
	printf("%lld\n", dp[0]);
}

