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

const int LOGN = 60;

ll n, m, k;

ll ans[LOGN+3];

int main (){
	ans[0] = 1;
	for(ll i=1;i<LOGN;i++){
		ans[i] = ans[i-1] + (1ll<<i)*(i+1);
	}
	for_tests(t, tt){
		ll res = 0;
		scanf("%lld", &n);
		for(ll i=1;(1ll<<i) <= n;i++){
			ll qtd= n/(1ll<<i)- n/(1ll<<(i+1));
			res += qtd*ans[i-1];
		}
		printf("%lld\n", res);
	}
}

