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

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main (){
	scanf("%d", &n);
	ll resp1 = 0, resp2 = 0;
	ll v = 0;
	vector<pair<ll, ll> > p;
	for(int i=0;i<n;i++) {
		ll a, t; scanf("%lld %lld", &a, &t);
		resp1 += 2ll*v*t + a*t*t;
		v += a*t;
		p.push_back(make_pair(-a, t));
	}
	v = 0;
	sort(p.begin(), p.end());
	for (int i=0;i<n;i++) {
		ll a = -p[i].first;
		ll t = p[i].second;
		resp2 += 2ll*v*t + a*t*t;
		v += a*t;
	}
	ll resp = resp2 - resp1;
	printf("%lld.%d\n", resp/2ll, resp % 2 == 0 ? 0 : 5);
}

