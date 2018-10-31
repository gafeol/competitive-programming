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

const int MAXN = 1123456;
const int INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];

int dp[MAXN][3];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int cus[MAXN][2];

int go(int i, int p){
	int &r = dp[i][p];
	if(r != -1) return r;
	r = INF;
	if(i == k) {
		if(p == 0)
			r = 0;
		return r;
	}
	r = min(r, min(go(i+1, p) + cus[i][0], go(i+1, (p^1)) + cus[i][1]));
	return r;
}

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		s[a] = (s[a]&1);
		cus[a%k][0] += s[a];
		cus[a%k][1] += (!s[a]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0, 0));
}

