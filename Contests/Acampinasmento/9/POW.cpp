
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back

const int MAXN = 500010;

int modn = 1e9 - 401;

inline ll mod(ll x){ return x%modn; }
inline ll mod2(ll x){ return x%(modn-1); }

ll n, m;

ll fat[MAXN];

ll expo2(ll base, ll e){
	if(e == 0) return 1;
	ll ans = expo2(base, e/2ll);
	ans = mod2(ans*ans);
	if((e&1))
		ans = mod2(ans*base);
	return ans;
}

ll expo(ll base, ll e){
	if(e == 0) return 1;
	ll ans = expo(base, e/2ll);
	ans = mod(ans*ans);
	if((e&1))
		ans = mod(ans*base);
	return ans;
}

ll f(ll x){
	if(x < 100000)
		return fat[x];
	return 0;
}

int main (){
	scanf("%lld %lld", &n, &m);
	fat[0] = 1;
	for(ll a=1;fat[a-1] != 0;a++){
		fat[a] = mod2(fat[a-1]*a);
	}
	ll ans = 1;
	ll res = 0;
	for(ll d=1;d<=sqrt(n);d++){
		if(n%d != 0) continue;
		res = 0;
		res = mod(res + expo(m, fat[n]));	
		printf("ras += %lld (%lld ** %lld)\n", expo(m, f(n)), m, f(n));
		res = mod(res - expo(m, expo2(f(d), n/d))); 
		printf("res -= %lld\n", expo(m, expo2(f(d), n/d)));
		res = mod(res - expo(m, f(n/d)));
		printf("ris -= %lld\n", expo(m, f(n/d)));
		ans = mod(ans*res);
	}
	printf("%lld\n", mod(ans+modn));
}
