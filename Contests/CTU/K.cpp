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
const int inf = 1791791791;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

vector<int> conn[MAXN];

stack<int> ts;
int tme = 0, ncomp = 0, low[MAXN], seen[MAXN];
int comp[MAXN];
int scc_dfs(int v) {
	seen[v] = low[v] = ++tme;
	ts.push(v);
	for (auto a : conn[v]) {
		if (seen[a] == 0) {
			scc_dfs(a);
		}
		low[v] = min(low[v], low[a]);
	}
	if (low[v] == seen[v]) {
		int node;
		do {
			node = ts.top(); ts.pop();
			comp[node] = ncomp;
			low[node] = inf;
		} while (v != node && ts.size());
		ncomp++;
	}
	return low[v];
}

int main() {
	while(scanf("%d %d", &n, &m) != EOF) {
		for (int i=0;i<m;i++) {
			int a, b; scanf("%d %d", &a, &b);
			conn[a].pb(b);
		}
		
	}
}

