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

const int MAXN = 112345;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

vector<int> adj[MAXN];


ll val[SQRT][MAXN];

ll h[MAXN];

ll re(int u, int p, int prof int sq){
	for(int nxt: adj[u]){
		if(nxt == p) continue;
		val[sq][u] += re(nxt, u, prof+1, sq);
	}
	val[sq][u] += h[prof];
	return val[sq][u];
}

void refresh(int sq){
	re(0, 0, sq);
	for(int a=0;a<=n;a++)
		h[a] = 0;
}

struct qry {
	int t, x, d;
} q[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n-1;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		i--;j--;
		adj[i].pb(j);
		adj[j].pb(i);
	}
	for(int a=0;a<m;a++){
		scanf("%d", &t);
		if(t == 1){
			scanf("%d %d", &d, &val);
			q[a] = {t, val, d};
		}
		else{
			int x;
			scanf("%d", &x);
			q[a] = {t, x, 0};
		}
	}
	int sq = sqrt(m);
	for(int a=0;a<m;a++){
		if(a > 0 && (a-1)/sq != a/sq)
			refresh((a-1)/sq);
	}
}

