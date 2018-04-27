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

ll nd, n, mx;
int t;

int main (){
	scanf("%lld%lld%lld%d", &nd, &n, &mx, &t);
	ll nvv = nd/(mx*n);
	ll sobb  = nd%(mx*n);
	ll res = nvv*mx + (sobb >= mx)*mx;
	for(ll nv=1;nv<=t;nv++){
		ll x = nd/(nv*n);
		if(x == 0) break;
		if(x <= mx){
			ll sob = nd - nv*n*x;
			debug("nv %lld x %lld sob %lld res %lld\n", nv, x, sob, nv*x + (sob >= x)*x);
			if(nv == t) sob = 0;
			res = max(res, nv*x + (sob >= x)*x);
		}
		x = nd/(1 + nv*n);
		if(x <= mx){
			ll sob = nd - n*nv*x;
			if(nv == t) sob = 0;
			debug("nv %lld x %lld sob %lld res %lld\n", nv, x, sob, nv*x + (sob >= x)*x);
			res = max(res, nv*x + (sob >= x)*x);
		}

	}
	printf("%lld\n", res);
}

