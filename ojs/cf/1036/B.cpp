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

ll n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

ll solve(ll i, ll j, ll k){
	ll mnd = max(i, j);
	if(mnd > k){
		return -1;
	}
	ll ans = k;
	if((k - mnd)&1ll)
		ans -= 2ll;
	return ans;
}

int main (){
	for_tests(t, tt){
		scanf("%lld%lld%lld", &n, &m, &k);
		ll ans = -1;
		if(((n+m)&1)){
			ans = max(ans, solve(n+1, m, k-1));
			ans = max(ans, solve(n-1, m, k-1));
			ans = max(ans, solve(n, m+1, k-1));
			ans = max(ans, solve(n, m-1, k-1));	
		}
		else
			ans = solve(n, m, k);
		printf("%lld\n", ans);
	}
}

