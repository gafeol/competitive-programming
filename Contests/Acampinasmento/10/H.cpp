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
const ll modn2 = 1000000009;
inline ll mod(ll x) { return x % modn; }
inline ll mod2(ll x) { return x % modn2; }

const int MAXN = 2000056;

const float EPS = 1e-8;

ll n, m, k;
int s[MAXN];

float lg[MAXN], nl;

int ok = 0;

ll h[MAXN], h2[MAXN];

ll res, res2;

ll expo(ll base, ll e){
	if(e == 0) return 1;
	ll ans = expo(base, e/2);
	ans = mod(ans*ans);
	if((e&1))
		ans = mod(ans*base);
	return ans;	
}

ll expo2(ll base, ll e){
	if(e == 0) return 1;
	ll ans = expo2(base, e/2);
	ans = mod2(ans*ans);
	if((e&1))
		ans = mod2(ans*base);
	return ans;	
}

void go(int i, int sz, ll H, ll H2, double l, int mx){
	if(i > 0 && H == res && H2 == res2){
		ok = 1;
		return;
	}
	if(i > 6) return;
	for(int q=1;q<=min(sz, mx);q++){
		if(l + lg[sz] - lg[q] - lg[sz-q] - EPS > nl) break; 

		ll mh = mod(h[sz]*mod(expo(h[q], modn-2)*expo(h[sz-q], modn-2)));
		ll mh2 = mod2(h2[sz]*mod2(expo2(h2[q], modn2-2)*expo2(h2[sz-q], modn2-2)));
		go(i+1, sz - q, mod(H*mh), mod2(H2*mh2), l + lg[sz] - lg[q] - lg[sz-q], q);
		if(ok) return;
	}
}

vector<vector<int> > bin;

int main (){
	scanf("%lld", &n);
	nl = (double)log(n);
	res = mod(n);
	res2 = mod2(n);
	lg[0] = 0;
	h[0] = h2[0] = 1;
	for(ll i=1;i<MAXN;i++){
		lg[i] = lg[i-1] + (double)log(i);
		h[i] = mod(h[i-1]*i);
		h2[i] = mod2(h2[i-1]*i);
	}
	for(int i=1;i<=1000000;i++){
		vector<int> aux;

		bin.pb(aux);
	}
	for(ll sz=1;sz<=2*sqrt(n)+3;sz++){
		go(0, sz, 1, 1, 0, 10); 
		if(ok){
			printf("%lld\n", sz);
			return 0;
		}
	}
	printf("%lld\n", n);
}
