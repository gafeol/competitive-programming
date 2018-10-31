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

const int MAXN = 2123, MAXM = 1000056;
const int LOGN = 13;

int n, m, k;
int s[MAXN], p[MAXN];
int sz[MAXN], h[MAXN];
vector<pii> adj[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int raiz(int u){
	if(p[u] == u) return u;
	return p[u] = raiz(p[u]);
}

bool join(int a, int b, int c){
	int ra = raiz(a);
	int rb = raiz(b);
	if(ra == rb) return false;

	//printf("%d -> %d %d\n", a, b, c);
	adj[a].pb(pii(b, c));
	adj[b].pb(pii(a, c));
	if(sz[ra] < sz[rb])
		swap(ra, rb);
	p[rb] = ra;
	sz[ra] += sz[rb];
	return true;
}

tuple<int, int, int> ar[MAXM];

int mx[MAXN][LOGN], pai[MAXN][LOGN];

void go(int u, int p, int cs){
	//printf("u %d p %d cs %d\n", u, p, cs);
	h[u] = h[p] + 1;
	pai[u][0] = p;
	mx[u][0] = cs;
	for(int i=1;i<LOGN;i++){
		pai[u][i] = pai[pai[u][i-1]][i-1];
		mx[u][i] = max(mx[u][i-1], mx[pai[u][i-1]][i-1]);
	}
	for(pii ar: adj[u]){
		int nxt = ar.fst;
		int cus = ar.snd;
		if(nxt == p) continue;
		go(nxt, u, cus);
	}
}

int qry(int u, int v){
	int mx = INT_MIN;
	if(h[u] != h[v]){
		if(h[u] < h[v])
			swap(u, v);

		for(int i=LOGN-1;i>=0;i--){
			if(h[pai[u][i]] > h[v]){
				mx = max(mx, ::mx[u][i]);
				u = pai[u][i];
			}
		}
		mx = max(mx, ::mx[u][0]);
		u = pai[u][0];
	}
	if(u == v) return mx;

	for(int i=LOGN-1;i>=0;i--){
		if(pai[u][i] != pai[v][i]){
			mx = max(mx, max(::mx[u][i], ::mx[v][i]));
			u = pai[u][i];
			v = pai[v][i];
		}
	}
	mx = max(mx, max(::mx[u][0], ::mx[v][0]));
	return mx;
}

int main (){
	while(scanf("%d%d", &n, &m) != EOF){
		for(int a=1;a<=n;a++){
			p[a] = a;
			sz[a] = 1;
			h[a] = 0;
			adj[a].clear();
		}
		int sum = 0;
		for(int a=0;a<m;a++){
			int i, j, c;
			scanf("%d%d%d", &i, &j, &c);
			ar[a] = {c, i, j};
		}
		sort(ar, ar+m);
		int cnt = n;
		for(int a=0;a<m;a++){
			int i, j, c;
			tie(c, i, j) = ar[a];
			if(join(i, j, c)){
				sum += c;
				cnt--;
			}
		}
		if(cnt > 1){
			puts("disconnected");
		}
		else{
			int res = INT_MAX;
			go(1, 1, 0);
			for(int a=0;a<m;a++){
				int i, j, c;
				tie(c, i, j) = ar[a];
				//printf("try %d %d %d\n", i, j, c);
				res = min(res, sum - qry(i, j) - c);	
				//printf("	%d - %d - %d\n", sum, qry(i, j), c);
			}
			printf("%d\n", res);
		}
	}
}

