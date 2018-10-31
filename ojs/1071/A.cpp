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

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main (){
	scanf("%lld%lld", &n, &m);
	ll c = 1;
	while(((c+2)*(c+1))/2ll <= n+m)
		c++;
	
	vector<ll> ans;
	ll tot = n+m;
	for(ll a=1;a<=c;a++){
		tot -= a;
	}
	ll mx = tot;
	if(mx <= c) mx = 0;
	ll sum = 0;
	map<int, bool> mrk;
	if(mx > 0 && mx <= n){
		sum = mx;
		mrk[mx] = 1;
		ans.pb(mx);
		mx = 0;
	}
	for(ll a=c;a>=1;a--){
		if(sum+a <= n){
			sum += a;
			ans.pb(a);
		}
	}
	printf("%d\n", (int)ans.size());
	for(ll x: ans){
		printf("%lld ", x);
		mrk[x] = 1;
	}
	ans.clear();
	sum = 0;
	if(mx > 0 && !mrk[mx]){
		sum += mx;		
		ans.pb(mx);
		mrk[mx] = 1;
	}
	for(int a=1;a<=c;a++){
		if(sum + a <= m && !mrk[a]){
			sum += a;
			ans.pb(a);
		}
	}
	puts("");
	printf("%d\n", (int)ans.size());
	for(ll x: ans){
		printf("%lld ", x);
		mrk[x] = 1;
	}
}

