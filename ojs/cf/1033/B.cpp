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

bool isp(ll x){
	for(ll a = 2; a <= sqrt(x);a++){
		if((x%a) == 0){
			return false;
		}
	}
	return true;
}

int main (){
	for_tests(t, tt){
		ll a, b;
		scanf("%lld%lld", &a, &b);

		ll l = a - b;
		ll r = a + b;
		if(l > r)
			swap(l, r);
		if(l > 1){
			puts("NO");
			continue;
		}
		if(isp(r))
			puts("YES");
		else
			puts("NO");
	}
}

