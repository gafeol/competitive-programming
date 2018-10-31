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

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

struct ship {
	ll tme, s;
	int id, c;
	bool operator< (const ship &a) const {
		return make_pair(tme, id) < make_pair(a.tme, a.id);
	}
};

struct crane {
	ll tme, v;
	int id;
	vector<int> c;
	bool operator< (const crane &a) const {
		return make_pair(tme, id) < make_pair(a.tme, a.id);
	}
};

ll get(ll s, ll v) {
	return (s + v - 1ll) / v;
}

set<crane> disp[20];
vector<ship> sh;

int main (){
	freopen("seaport.in", "r", stdin);
	freopen("seaport.out", "w", stdout);
	scanf("%d %d %*d", &n, &m);
	for (int i=0;i<n;i++) {
		ll tme, s; int c; scanf("%lld %d %lld", &tme, &c, &s);
		sh.pb({tme, s, i+1, c});
	}
	sort(sh.begin(), sh.end());
	for (int i=0;i<m;i++) {
		ll v; int c; scanf("%lld %d", &v, &c);
		vector<int> temp(c);
		while (c--) {
			scanf("%d", &temp[c]);
		}
		crane cr = {0ll, v, i+1, temp};
		for (auto a: temp) {
			disp[a].insert(cr);
		}
	}
	for (auto s: sh) {
		crane c = *disp[s.c].begin();
		crane nc = c;
		nc.tme = max(s.tme, c.tme) + get(s.s, c.v);
		for (auto a: c.c) {
			disp[a].erase(c);
			disp[a].insert(nc);
		}
		printf("%d\n", c.id);
	}
}

