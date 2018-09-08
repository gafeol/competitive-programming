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

const int MAXN = 100003;
const int MAXK = 303;

int n, m, k;
int h[30];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}


char w[MAXK], s[MAXN];
int dp[MAXN][MAXK];

int main (){
	scanf("%d%d", &k, &n);
	for(int a=0;a<26;a++){
		scanf("%d", h+a);
	}
	scanf(" %s", w);
	w[k] = '$'; 
	scanf(" %s", s);
	dp[0][0] = 1;
	for(int i=0;i<n;i++){
		int cus = h[s[i]-'A']+1;
		for(int j=0;j<=k;j++){
			int t = (j&1);
			dp[i+1][j] = mod(dp[i][j] + dp[i+1][j]);
			if(s[i] == w[j])
				dp[min(n, i+cus)][j+1] = mod(dp[min(n, i+cus)][j+1] + dp[i][j]);
		}
	}
	printf("%d\n", dp[n][k]);
}

