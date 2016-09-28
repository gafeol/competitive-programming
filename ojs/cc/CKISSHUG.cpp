#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { if(x < 0){ return mod(x + modn); } else { return x % modn; } }

const int MAXN = 212345;


ll n, m, k;
int s[MAXN];

ll expo(ll e){
	if(!e)
		return 1;
	ll keep = 1, x = 2;
	while(e > 1){
		if(e&1)
			keep = mod(keep*x);
		x = mod(x*x);
		e >>= 1;
	}
	return mod(x*keep);
}

int main (){
	for_tests(t, tt){
		scanf("%lld", &n);
		ll ans = mod(expo(n/2ll +1) + expo((n+1)/2ll) - 2);

		printf("%lld\n", ans);
	}
}
