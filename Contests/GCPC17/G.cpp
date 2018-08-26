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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
pii s[MAXN];

inline ll gcd(ll a, ll b){
	if(a == 0) return b;
	return gcd(b%a, a);
}


ll cross(pii a, pii b){
	return a.fst*b.snd - a.snd*b.fst;
}

int main (){
	scanf("%d", &n);
	ll e = 0;
	for(int a=0;a<n;a++){
		debug("e: %lld\n", e);
		int i, j;
		scanf("%d %d", &i, &j);
		s[a] = pii(i, j);
		if(a > 0){
			debug("de a %d a+1: e %lld\n", a, e);
			ll dx = abs(s[a].fst - s[a-1].fst);
			ll dy = abs(s[a].snd - s[a-1].snd);
			if(dx == 0){
				e += dy;
				continue;
			}
			if(dy == 0){
				e += dx;
				continue;
			}
			ll gc = gcd(dx, dy);
			e += gc;
		}
	}
	debug("e: %lld\n", e);
	ll dx = abs(s[0].fst - s[n-1].fst);
	ll dy = abs(s[0].snd - s[n-1].snd);
	if(dx == 0){
		e += dy;
	}
	else if(dy == 0){
		e += dx;
	}
	else{
		ll gc = gcd(dx, dy);
		debug("gc %lld\n", gc); 
		debug("dx %lld dy %lld\n", dx, dy);
		e += gc;
	}

	ll ar = 0;
	for(int a=0;a<n;a++){
		int aa = (a + 1)%n;
		ar += cross(s[a], s[aa]);
	}
	ar = abs(ar);
	debug("2*ar %lld e %lld\n", ar, e);

	printf("%lld\n", (ar + 2 - e)/2); 
}

