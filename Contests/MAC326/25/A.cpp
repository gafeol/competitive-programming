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

ll n, k;

ll go(ll v, ll d){
	if(v/d == 0) return 0;
	return v/d + go(v, d*k);
}

int main (){
	scanf("%lld%lld", &n, &k);
	ll i = 0, j = 100000000000LL;
	while(i < j){
		ll m = (i + j)/2ll;
		if(m + go(m, k) >= n)
			j = m;
		else
			i = m+1;
	}
	printf("%lld\n", i);
}

