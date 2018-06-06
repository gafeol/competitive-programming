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

ll n, h;

ll f(ll x){
	return (x*(x+1))/2ll;
}

int main (){
	scanf("%lld %lld", &n, &h);
	ll i = 1, j = (ll)2e9;
	while(i < j){
		ll m = (i+j)/2ll;
		if((m*(m+1))/2ll >= n)
			j = m;
		else
			i = m + 1;
	}
	ll larg = i;
	ll sob = (i*(i+1))/2ll - n;
	i = 0, j = (ll)2e9;
	while(i < j){
		ll m = (i+j+1)/2ll;
		if((m*(m+1))/2ll <= sob)
			i = m;
		else
			j = m-1;
	}
	ll cut = i;
	if(larg-cut <= h){
		printf("%lld\n", larg); 
		return 0;
	}
	ll move = n - (f(larg) - f(larg-h));
	debug("move %lld\n", move);
	assert(move > 0);
	ll ans2 = h;
	ans2 += (n - f(h) + h-1)/h;
	ll ans = larg + (move+h-1)/h;
	assert(ans2 == ans);
	printf("%lld\n", min(ans2, ans));
}
