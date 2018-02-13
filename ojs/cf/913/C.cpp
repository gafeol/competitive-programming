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

const int MAXN = 41;

int n, m;
ll k;

ll q[MAXN];
ll s[MAXN];
ll ans = LLONG_MAX;

int main (){
	scanf("%d%lld", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
		if(a != 0)
			s[a] = min(s[a], 2ll*s[a-1]);
	}
	ll res = 0;
	for(ll a=n-1;a>=0;a--){
		ll pot = (1ll<<a);
		if(k >= pot){
			res += (k/pot)*s[a];
			k = k%pot;
		}
		ans = min(ans, res + s[a]);
	}
	ans = min(ans, res);
	printf("%lld\n", ans);
}

