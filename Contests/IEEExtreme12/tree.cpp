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

const int MAXN = 212345, LOGN = 23;

int n, m, k;
int s[MAXN];
int p[MAXN][LOGN];
int h[MAXN];

vector<int> adj[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

void dfs(int u, int pai){
	p[u][0] = pai;
	h[u] = h[pai] + 1;
	for(int i=1;i<LOGN;i++){
		p[u][i] = p[p[u][i-1]][i-1];
	}
	for(int nxt: adj[u]){
		if(nxt != pai){
			dfs(nxt, u);
		}
	}
}

int lca(int u, int v){
	//printf("lca %d %d\n", u, v);
	if(h[u] != h[v]){
		if(h[u] < h[v])
			swap(u, v);
		for(int i=LOGN-1;i>=0;i--){
			if(h[p[u][i]] > h[v]){
				u = p[u][i];
			}
		}
		u = p[u][0];
	}
	if(u == v) return u;
	for(int i=LOGN-1;i>=0;i--){
		if(p[u][i] != p[v][i]){
			u = p[u][i];
			v = p[v][i];
		}
	}
	return p[u][0];
}

int mx;

int go(int u, int pai){
	for(int nxt: adj[u]){
		if(nxt == pai) continue;
		s[u] += go(nxt, u);
	}
	mx = max(mx, s[u]);
	return s[u];
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=1;a<n;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	dfs(0, 0);
	for(int a=0;a<m;a++){
		int i, j, c;
		scanf("%d%d%d", &i, &j, &c);
		s[i] += c;
		s[j] += c;
		int lc = lca(i, j);
		
		
		
		s[lca(i,j)] -= c;
		if(p[lc][0] != lc)
			s[p[lc][0]] -= c;
	}
	mx = INT_MIN;
	go(0, 0);
	printf("%d\n", mx);
}
