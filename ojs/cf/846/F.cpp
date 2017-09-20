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

const int MAXN = 1123456;

ll n, m, k;
ll s[MAXN];

ll ult[MAXN];

int main (){
	scanf("%lld", &n);
	ll ans = 0;
	memset(ult, 0, sizeof(ult));
	for(int a=1;a<=n;a++){
		scanf("%lld", s+a);
		ans += 2*((n - a + 1)*(a - ult[s[a]]) - 1) + 1;
		ult[s[a]] = a;
	}
	printf("%.10f\n", ((double)ans)/(n*n));
	debug("%lld %lld\n", ans, n*n);
}

