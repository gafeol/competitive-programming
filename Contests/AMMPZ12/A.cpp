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

const int MAXN = 45, MAXK = 1602;
const int INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN], q[MAXN];

int dp[MAXN][MAXN][MAXK];

int val[MAXN][MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int go(int i, int j, int k){
	if(k < 0) return -INF;
	int &r = dp[i][j][k];
	if(r != -1) return r;
	r = -INF;

	if(i == n)
		return r = (j == 0 ? 0 : -INF);

	for(int a=0;a<=min(j, q[i]);a++)
		r = max(r, go(i+1, j-a, k - s[i]*a) + s[i]*min(q[i], j));
	return r;
}

int main (){
	scanf("%d%d", &n, &k);
	k = min(k, 1600);
	for(int a=0;a<n;a++)
		scanf("%d", s+a);
	for(int a=0;a<n;a++)
		scanf("%d", q+a);

	memset(dp, -1, sizeof(dp));
	int res = 0;
	for(int j=0;j<=40;j++){
		res = max(res, go(0, j, k));
		//printf("go %d %d %d: %d\n", 0, j, k, dp[0][j][k]);
	}

	printf("%d\n", res);
}

