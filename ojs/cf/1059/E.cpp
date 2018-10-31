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

int l, n, m;
ll k;
ll s[MAXN];
vector<int> adj[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}
int prox[MAXN];
int qtd;
int ate[MAXN];
int h[MAXN];
ll S[MAXN];
int pai[MAXN], mn[MAXN], sz[MAXN];
ll sum;

int p[MAXN];

set<pii> q;

void go(int u, int r){
	h[u] = h[p[u]]+1;
	S[u] = S[p[u]] + s[u];
	sum = S[u] - S[r] + s[r];
	qtd = h[u] - h[r] + 1;
	while(qtd > l || sum > k){
		sum -= s[r];
		qtd--;
		r = prox[r];
	}
	ate[u] = r;
	//printf("u %d ate %d\n", u, ate[u]);
	for(int nxt: adj[u]){
		prox[u] = nxt;
		go(nxt, r);	
	}
	q.insert(pii(h[u], u));
}

int raiz(int u){
	if(pai[u] == u) return u;
	return pai[u] = raiz(pai[u]);
}

void join(int u, int v){
	u = raiz(u);
	v = raiz(v);
	
	if(u == v) return ;

	if(sz[u] < sz[v])
		swap(u, v);

	pai[v] = u;
	sz[u] += sz[v];
	if(h[mn[u]] > h[mn[v]])
		mn[u] = mn[v];
}

int main (){
	scanf("%d%d%lld", &n, &l, &k);
	for(int a=1;a<=n;a++){
		scanf("%lld", s+a);
		if(s[a] > k){
			puts("-1");
			return 0;
		}
	}
	p[1] = 1;
	for(int a=2;a<=n;a++){
		scanf("%d", p+a);
		adj[p[a]].pb(a);
	}
	go(1, 1);
	int res = 0;
	for(int a=1;a<=n;a++){
		pai[a] = a;
		sz[a] = 1;
		mn[a] = a;
	}
	while(!q.empty()){
		int u = q.rbegin()->snd;
		q.erase(*q.rbegin());
		if(sz[raiz(u)] > 1) continue;
		int at = ate[u];
		
		while(h[mn[(raiz(u))]] > h[at]){
			join(u, p[mn[raiz(u)]]);
		}
		res++;		
	}
	printf("%d\n", res);
}

