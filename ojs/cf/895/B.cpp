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
#define debug(args...)// fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n; 
ll x, m, k;
ll s[MAXN];

vector<ll> v;

ll ceil(ll a, ll b){
	return a/b + (a%b != 0);
}

ll qry(ll val){
	return (ll)v.size() - (lower_bound(v.begin(), v.end(), val) - v.begin());
}

ll ans;

int main (){
	scanf("%d%lld%lld", &n, &x, &k);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
		v.pb(s[a]);
	}
	sort(v.begin(), v.end());
	for(int a=0;a<n;a++){
		ll div = ceil(s[a], x);
		div += k - 1;
		debug("div %d\n", div);
		ll lo = max(x*div, s[a]);
		lo += (k == 0 && lo%x == 0);
		ll res = qry(lo);
		debug("qry %lld %lld\n", lo, res);
		div++;
		ll up = max(x*div, lo);
		res -= qry(up);
		debug("qry %lld %lld\n", up, qry(up));
		ans += res;
	}
	printf("%lld\n", ans);
}

