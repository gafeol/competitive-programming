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

const int MAXN = 2123456;

ll n, m, k;

ll expo(ll base, ll e){
	if(e == 0) return 1;
	ll ans = expo(base, e/2ll);
	ans = mod(ans*ans);
	if(e&1)
		ans = mod(ans*base);

	return ans;
}

ll inv(ll x){
	return expo(x, modn-2);
}

ll f[MAXN], invf[MAXN];

int main (){
	scanf("%lld", &n);

	f[1] = 1;
	invf[1] = 1;
	for(ll a=2;a<=n;a++){
		f[a] = mod(f[a-1]*a);	
		invf[a] = inv(f[a]);
	}
	ll res = f[n];
	for(ll a=2;a<n;a++){
		res = mod(res + (n-a)*mod(mod(f[n]*invf[a])*(a-1)));
	}
	printf("%lld\n", res);
}

