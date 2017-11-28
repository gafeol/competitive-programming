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

ll n, m;
int k;

ll expo(ll e, ll base){
	if(e == 0) return 1ll;
	ll ans = expo(e/2ll, base);
	ans = mod(ans*ans);
	if(e&1ll)
		ans = mod(ans*base);
	return ans;
}

int main (){
	scanf("%lld %lld %d", &n, &m, &k);
	if(k == -1 && (n&1) != (m&1)) printf("0\n");
	else printf("%lld\n", expo(n-1, expo(m-1, 2)));
}

