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

ll expo(ll base, ll e){
	if(e == 0) return 1ll;
	ll aux = expo(base, e/2ll);
	aux = mod(aux*aux);

	if((e&1))
		aux = mod(aux*base);
	return aux;
}

ll inv(ll x){
	return expo(x, modn-2);
}

int main (){
	for_tests(t, tt){
		printf("Case #%d: ", tt); 
		scanf("%lld%lld", &n, &k);
		if(k > n) {
			puts("0");
			continue;
		}


		ll res = expo(2ll, n);
		ll mul = 1;
		ll sob = 1; 
		for(ll a=0;a<k;a++){
			res = mod(res - mod(mul*inv(sob)));
			mul = mod(mul*(n-a));
			sob = mod(sob*(a+1));
		}
		printf("%lld\n", mod(modn+res));
	}
}

