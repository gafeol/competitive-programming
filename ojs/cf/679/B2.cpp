

#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
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

ll s[MAXN];
ll n, k;
map<ll, pii> dp;

template <typename a, typename b>
std::pair<a, b> operator+(const std::pair<a,b> & l, const std::pair<a,b> & r) {
	return {l.fst+r.fst, l.snd+r.snd};
}

ll cubo(ll x){
	return x*x*x;
}

pii go(ll x){
	if(dp.find(x) != dp.end())
		return dp[x];
	if(x < 0) return pii(LLONG_MIN, 0);
	if(x == 0) return dp[x] = pii(0, 0);
	dp[x] = pii(0,0);
	ll m = 0;
	while(cubo(m+1) <= x)
		m++;
	dp[x] = max(dp[x], go(x - cubo(m)) + pii(1, cubo(m)));
	debug("para cara %lld tenho %lld %lld\n", x, dp[x].fst, dp[x].snd);
	dp[x] = max(dp[x], go(cubo(m)-1 - cubo(m-1)) + pii(1, cubo(m-1)));
	debug("para cara %lld tenho %lld %lld\n", x, dp[x].fst, dp[x].snd);
	return dp[x];
}

int main (){
	scanf("%lld", &n);
	printf("%lld %lld\n", go(n).fst, go(n).snd); 
}
