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

int n, m;
ll k;

int main (){
	scanf("%d%lld", &n, &k);
	ll ans = 0;
	int cnt = 0;
	for(int a=0;a<n;a++){
		char c;
		scanf(" %c", &c);
		ans = (ans*10ll + c - '0')%k;
		cnt += (ans == 0ll);
	}
	if(ans > 0){
		puts("0");
		return 0;
	}
	ll res = 1;
	for(int a=1;a<cnt;a++){
		res = mod(res * 2ll);
	}
	printf("%lld\n", res);
}

