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

const int N = 2505;
const int K = 2505;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

ll dp[N];
ll d[K], f[K], es[K][K], resp[K];
vector<int> adj[N];

void dfs(int v, int k) {
	ll sum = 1;
	for (auto u: adj[v]) {
		dfs(u, k);
		sum *= (dp[u] * (k - 1ll)) % modn;
		sum %= modn;
	}
	dp[v] = sum;
}

int main (){
	int n, k;
	scanf("%d %d", &n, &k);
	es[0][0] = 1ll;
	for (int i=1;i<=k;i++) {
		es[i][0] = 1ll;
		for (int j=1;j<=i;j++) {
			es[i][j] = (es[i-1][j-1] + es[i-1][j])%modn;
		}
	}
	for(int a=1;a<n;a++){
		int p; scanf("%d", &p);
		adj[p].pb(a);
	}
	for (int i=1;i<=k;i++) {
		dfs(0, i);
		d[i] = dp[0] * i;
		//printf("d[%d] = %lld\n", i, d[i]);
	}
	resp[0] = 0;
	for (int i=1;i<=k;i++) {
		resp[i] = d[i];
		for (int j = i-1; j >= 1; j--) {
			resp[i] -= (es[i][j] * resp[j]) % modn;
			resp[i] += modn;
			resp[i] %= modn;
		}
	}
	printf("%lld\n", resp[k]);
}

