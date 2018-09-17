#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
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

const int MAXN = 512345, LOGN  = 21;

int n, m, k;
ll s[MAXN];
vector<pil> adj[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int p[MAXN][LOGN];
ll cus[MAXN][LOGN];

int acu[MAXN];

void dfs(int u, int pai, ll w){
	p[u][0] = pai;
	cus[u][0] = w;
	for(int i = 1;i < LOGN;i++){
		p[u][i] = p[p[u][i-1]][i-1];
		cus[u][i] = cus[u][i-1] + cus[p[u][i-1]][i-1];
	}
	
	acu[pai]++;
	int anc = u;
	ll val = 0;
	for(int i=LOGN-1;i>=0;i--){
		if(val + cus[anc][i] <= s[u]){
			val += cus[anc][i];
			anc = p[anc][i];
		}
	}
	anc = p[anc][0];
	acu[anc]--;

	for(pil ar: adj[u]){
		int nxt = ar.fst;
		if(nxt == pai) continue;
		dfs(ar.fst, u, ar.snd);
		acu[u] += acu[ar.fst];
	}
}

int main (){
	freopen("car.in", "r", stdin);
	for_tests(t, tt){
		scanf("%d", &n);

		for(int a=1;a<=n;a++){
			adj[a].clear();
			scanf("%lld", &s[a]);
			acu[a] = 0;
		}
		for(int a=0;a<n-1;a++){
			int i, j;
			ll c;
			scanf("%d %d %lld", &i, &j, &c);
			adj[i].pb(pil(j, c));
			adj[j].pb(pil(i, c));
		}
		const ll inf = 1e9 + 1ll;
		dfs(1, 0,inf);
		for(int a=1;a<=n;a++){
			printf("%d ", acu[a]);
		}
		puts("");
	}
}

