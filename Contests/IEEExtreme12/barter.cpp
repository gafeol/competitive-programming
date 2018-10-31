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
const ll modn = 998244353;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 21234;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

ll expo(ll base, ll e){
	if(e == 0) return 1ll;
	ll ans = expo(base, e/2ll);
	ans = mod(ans*ans);
	if((e&1))
		ans = mod(ans*base);
	return ans;
}


ll inv(ll x){
	return expo(x, modn-2);
}

bool join(int u, int v){
	if(raiz(u) == raiz(
}

int main (){
	scanf("%d", &n);
	int cnt = 0;
	for(int a=0;a<n;a++){
		char sa[100], sb[100];
		ll c;
		scanf(" %s %s %lld ", sa, sb, &c); 
		if(ind.find(sa) == ind.end())
			ind[sa] = cnt++;
		int ia = ind[sa];

		if(ind.find(sb) == ind.end())
			ind[sb] = cnt++;
		int ib = ind[sb];

		if(join(ia, ib)){
			adj[ia].pb(pil(ib, c));
			adj[ib].pb(pil(ia, inv(c)));
		}
	}
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		
	}
}

