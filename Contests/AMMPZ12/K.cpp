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

const int MAXN = 2123;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int val[MAXN];
int dp[MAXN][MAXN];
int v[MAXN];

int solve(int i, int k, int am) {
	if (i < 0) return 0;
	int nxt_am = 0, nxtnxt_am = 0;
	if (i) nxt_am = val[i-1];
	if (i > 1) nxtnxt_am = v[i-2];
	dp[i][k] = solve(i-1, k, nxt_am);
	if (k > 0) dp[i][k] = max(dp[i][k], solve(i-2, k-1, nxt_am + nxtnxt_am) + am);
	//printf("%d %d %d %d %d\n", i, k, am, nxt_am, nxtnxt_am);
	return dp[i][k];
}

int main (){
	scanf("%d %d", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%d", &v[a]);
	}
	int res = 0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			val[j] = 0;
		}
		int temp = v[i];
		for (int j=0;j<n-3;j++) {
			val[j] = v[(i+2+j)%n];
		}
		val[0] += v[(i+1)%n];
		val[n-4] += v[(i-1+n)%n];
	/*	for (int j=0;j<n-3;j++) {
			printf("%d ", val[j]);
		}
		printf("-> (%d)\n", i); */
		temp += solve(n-4, k-1, val[n-4]);
		res = max(res, temp);
	}
	printf("%d\n", res);
}

