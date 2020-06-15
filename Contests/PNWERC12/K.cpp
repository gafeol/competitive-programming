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
const ll modn = 1000000000;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 2123;
const int MAXH = 40;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

ll dp[MAXN][MAXN];

void print(ll x){
	vector<ll> aux;
	aux.clear();
	int cnt = 9;
	while(cnt--){
		aux.pb(x%10);
		x /= 10;
	}
	for(int a=aux.size()-1;a>=0;a--)
		printf("%lld", aux[a]);
	puts("");
}

int main (){
	dp[0][0] = 1;
	dp[1][1] = 1;
	int mx = 1428;
	for(int n = 2;n <= mx;n++){
		for(int h = 1;h < MAXH; h++){
			for(int nn = 0; nn <= n-1 ; nn++){
				dp[n][h] = mod(dp[n][h] + mod(dp[nn][h-1]*dp[n-nn-1][h-1]));
				//printf(" +=  %lld\n", mod(dp[nn][h-1]*dp[n-nn-1][h-1]));
				dp[n][h] = mod(dp[n][h] + mod(dp[nn][h-1]*(h > 1 ? dp[n-nn-1][h-2] : 0)));
				//printf(" +=  %lld\n", mod((h > 1 ? dp[nn][h-2] : 0)*dp[n-nn-1][h-1]));
				dp[n][h] = mod(dp[n][h] + mod((h > 1 ? dp[nn][h-2] : 0)*dp[n-nn-1][h-1]));
				//printf(" +=  %lld\n",mod((h > 1 ? dp[nn][h-2] : 0)*dp[n-nn-1][h-1]));
			}
			//printf("%lld ", dp[n][h]);
		}
		//puts("");
	}
	while(scanf("%d", &n) != EOF){
		ll ans = 0;
		for(int a=1;a<MAXH;a++){
			ans = mod(ans + dp[n][a]);
		}
		print(ans);
	}
}

