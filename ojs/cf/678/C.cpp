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

ll n, m, k, a, b, p, q;

ll mdc(ll i, ll j){
	if(j == 0) return i;
	return mdc(j, i%j);	
}

ll mmc(ll i, ll j){
	return (i*j)/mdc(i, j);
}

int main (){
	scanf("%lld%lld%lld%lld%lld", &n, &a, &b, &p, &q);
	if(p < q){
		swap(p, q);
		swap(a, b);
	}
	ll res = ll(n/a)*p + ll(n/b)*q -ll(n/mmc(a, b))*q;
	printf("%lld\n", res);
}
