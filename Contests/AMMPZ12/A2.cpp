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

const int MAXN = 45, MAXK = 64002;
const int INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN], q[MAXN];

int dp[MAXN][MAXK];

int val[MAXN][MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++)
		scanf("%d", s+a);
	for(int a=0;a<n;a++)
		scanf("%d", q+a);
	for(int ja = 0;ja <= 42;ja++){
		int sum = 0;
		for(int a=0;a<n;a++){
			sum += s[a]*(q[a] > ja);
			val[a][ja] = sum;
			//printf("val %d %d %d\n", a, ja, val[a][ja]);
		}
	}
	int res = 0;
	for(int a=n-1;a>=0;a--){
		for(int ja=0;ja<q[a];ja++){
			for(int x=s[a];x<=k;x++){
				dp[ja+1][x-s[a]] = max(dp[ja+1][x-s[a]], dp[ja][x] + val[a][ja]);
				int sum = 0;
				for(int y=1;y<=ja;y++){
					sum += val[a][ja-y+1];
					dp[ja+1][x-s[a]] = max(dp[ja+1][x-s[a]], dp[ja][x] + sum - y*s[a]);

				}
				res = max(res, dp[ja+1][x-s[a]]);
			}
		}
	}
	printf("%d\n", res);
}

