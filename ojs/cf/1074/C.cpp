#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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

const int MAXN = 312345;

int n, m, k;

vector<pll> s;

const int INF = 1000000000;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

pll p[4];

void add(pll pt){
	if(pt.fst > p[0].fst)
		p[0] = pt;
	if(pt.fst < p[1].fst)
		p[1] = pt;
	if(pt.snd > p[2].snd)
		p[2] = pt;
	if(pt.snd < p[3].snd)
		p[3] = pt;
}

ll test(pll a, pll b, pll c){
	ll dx = max(abs(a.fst - c.fst), max(abs(a.fst - b.fst), abs(b.fst - c.fst)));
	ll dy = max(abs(a.snd - c.snd), max(abs(a.snd - b.snd), abs(b.snd - c.snd)));
	return 2ll*dx + 2ll*dy;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		ll i, j;
		scanf("%lld%lld", &i, &j);
		s.pb({i, j});
	}
	for(int a=0;a<4;a++)
		p[a] = s[0];
	for(int a=0;a<n;a++)
		add(s[a]);
	
	ll ans = 0;
	for(int a=0;a<n;a++){
		for(int b=0;b<4;b++){
			for(int c=0;c<4;c++){
				ans = max(ans, test(s[a], p[b], p[c]));			
			}
		}
	}
	printf("%lld ", ans);

	for(int a=4;a<=n;a++)
		printf("%lld ", 2ll*abs(p[0].fst - p[1].fst) + 2ll*abs(p[2].snd - p[3].snd));
}

