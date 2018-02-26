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

int s[MAXN];
ll k, d, t;

ll bl = 0;

int go(ll n){
	ll tt = t;
	tt -= n;
	if(tt < 0) return 1;
	if((n/bl) > 0 && log(k) + log((n/bl)) > log(4e18+10LL))
		return 1;
	tt -= k*(n/bl);
	tt -= min((n%bl), k);
	if(tt > 0) return 0;
	return 1;
}

int main (){
	scanf("%lld %lld %lld", &k, &d, &t);
	t = t*4ll;
	k *= 2ll;
	d *= 2ll;
	if(d >= k)
		bl = d;
	else
		bl = ((k/d) + (k%d != 0))*d;
	
	ll i = 0, j = 4500000000000000000LL;
	while(i < j){
		ll m = (i+j)/2;
		if(go(m))
			j = m;
		else
			i = m+1;
	}
	printf("%lld", i/2ll);
	if((i&1))
		printf(".5\n");
	else
		printf(".0\n");
}

