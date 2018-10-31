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

const int MAXN = 1123;

int n, m, k;
ll s[MAXN];
ll A[MAXN], B[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

vector<ll> pos[MAXN];

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		ll res = 0;
		for(int a=0;a<=n;a++){
			scanf("%lld", s+a);
			res += s[a];
		}
		ll mx = 0;
		for(int a=0;a<n;a++){
			scanf("%lld %lld", A+a, B+a);	
			mx = max(mx, B[a]);
		}
		res += mx;
		double ans = res;
		printf("Case #%d: %.10f\n", tt, ans);
	}
}

