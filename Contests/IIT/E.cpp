#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)

template <typename T> void write(ostream& out, T t) {
	out << t << "\n";
}
template <typename T, typename... Args>
void write(ostream& out, T t, Args... args) {
	out << t << ' ';
	write(out, args...);
}

template <typename... Args>
void debug(Args... args) {
	#ifdef LOCAL
		write(cerr, args...);
	#endif
}


template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

ll n, h;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

inline ll posmn(ll a) {
	if (a > 62ll) return n;
	return min((1ll << a), n);
}

inline ll l2(ll a) {
	return 63ll - __builtin_clzll(a) + 1ll;
}

inline ll bg(ll x) {
	ll h1 = l2(x);
	ll g = (1ll << (h - h1));
	ll mn = x*g;
	ll mx = mn + g - 1ll;
	if (mx <= n) return 2ll*g - 2ll;
	if (mn > n) return g - 2ll;
	return g - 1ll + (n - mn);
}

inline pair<ll, ll> calc(ll a) {
	ll mn = l2(a);
	ll mx = n - bg(a);
	return make_pair(mn, mx);
}

inline ll posmx(ll a) {
	ll l = 1, r = n;
	while (l < r) {
		ll m = (l+r)/2ll;
		ll b = n - bg(m);
		if (b <= a) l = m+1ll;
		else r = m;
	}
	return l;
}

int main (){
	int t; scanf("%d", &t);
	for(int a=0;a<t;a++){
		scanf("%lld", &n);
		ll resp = 1, pos = 1;
		pair<ll, ll> p = make_pair(1ll, 1ll);
		h = l2(n);
		vector<ll> ps;
		pos = 1;
		while (true) {
			pair<ll, ll> pn = calc(pos);
			if (np == p) break;

			p = np;
		}
		while (true) {
			//printf("p = (%lld, %lld)\n", p.first, p.second);
			ll pos = min(posmn(p.first), posmx(p.second));
			//printf("newpos = %lld\n", pos);
			pair<ll, ll> np = calc(pos);
			if (np == p) break;
			p = np;
			resp++;
		}
		printf("%lld\n", resp);
	}
}

