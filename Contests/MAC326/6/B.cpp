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

ll s[5];


ll f(ll mn){
	ll ans = 0;
	ans = (s[0]+s[3])*(s[0]+s[3]);
	ans += s[1]*s[1];
	ans += s[2]*s[2];
	ans += (7ll)*mn;
	return ans;
}

bool cmp(int a, int b){
	return a > b;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		ll mn = LLONG_MAX;
		for(int b=0;b<4;b++){
			scanf("%lld", s+b);
			if(b < 3)
				mn = min(mn, s[b]);
		}
		sort(s, s+3, cmp);
		ll lim = mn + 10000;
		ll res = 0;
		while(mn < lim){
			for(int b=0;b<3;b++){
				if(s[b] < mn){
					s[b]++;
					s[3]--;
				}
			}
			if(s[3] < 0)
				break;
			res = max(res, f(mn));
			mn++;
		}
		printf("%lld\n", res);
	}
}
