#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<pii, pii> ppp;
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

int n, m, k;
pii s[MAXN];

ppp mk(ll x, ll y, ll ix, ll iy){
	return ppp(pii(x, y), pii(ix, iy));
}

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

map<pii, ll> cnt;
map<ppp, ll> cnt2;

int main (){
	//MULTIPLOS TESTS?
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		ll x, y;
		scanf("%lld %lld", &x, &y);	
		x*=2;
		y*=2;
		s[a] = pii(x, y);
	}
	ll res = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ll mx = (s[i].fst + s[j].fst)/2ll;
			ll my = (s[i].snd + s[j].snd)/2ll;
			ll dx = s[i].fst - s[j].fst;
			ll dy = s[i].snd - s[j].snd;
			ll ix = dx/gcd(dx, dy);
			ll iy = dy/gcd(dx, dy);
			res += cnt[pii(mx, my)] - cnt2[mk(mx, my, ix, iy)];
			cnt[pii(mx, my)]++;
			cnt2[mk(mx, my, ix, iy)]++;
		}
	}
	printf("%lld\n", res);
}

