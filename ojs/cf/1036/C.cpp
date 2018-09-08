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


ll l, r;

ll dp[22][5][3];

ll s[MAXN];

ll go(int i, int cnt, int lo){
	if(cnt > 3) return 0;
	if(i == 20) return r = 1;
	ll &r = dp[i][cnt][lo];
	if(r != -1) return r;
	r = 0;
	if(lo){
		r += 9ll*go(i+1, cnt+1, lo);
		r += go(i+1, cnt, lo);	
	}
	else{
		r += go(i+1, cnt, (s[i] > 0));
		if(s[i] > 1) 
			r += (s[i]-1ll)*go(i+1, cnt+1, 1);
		if(s[i] > 0)
			r += go(i+1, cnt+1, 0);
	}
	return r;
}

void cvt(ll x){
	for(int i=19;i>=0;i--){
		s[i] = (x%10);
		x /= 10ll;
	}
}

int main (){
	for_tests(t, tt){
		scanf("%lld%lld", &l, &r);
		cvt(r);
		memset(dp, -1, sizeof(dp));
		ll ans = go(0, 0, 0); 	
		cvt(l-1);
		memset(dp, -1, sizeof(dp));
		ans -= go(0, 0, 0);
		printf("%lld\n", ans);
	}
}

