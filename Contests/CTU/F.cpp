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

const int MAXN = 5005;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int v[MAXN];
int dp[MAXN][MAXN];

int main (){
	while (scanf("%d", &n) != EOF) {
		for (int i=0;i<n;i++) {
			scanf("%d", &v[i]);
			dp[i][i] = 0;
		}
		int resp = 0;
		for (int i=1;i<n;i++) {
			for (int j=0;j+i<n;j++) {
				int mid = (i == 1) ? 0 : dp[j+1][j+i-1];
				dp[j][j+i] = mid + ((v[j] == v[j+i]) ? 1 : 0);
				dp[j][j+i] = max(dp[j][j+i], max(dp[j+1][j+i], dp[j][j+i-1]));
				resp = max(resp, dp[j][j+i]);
				//printf("dp[%d][%d] = %d, mid = %d\n", j, j+i, dp[j][j+i], mid);
			}
		}
		printf("%d\n", resp);
	}
}

