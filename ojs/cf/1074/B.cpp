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

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

vector<int> q;

int mrk[MAXN];
vector<int> adj[MAXN];

int go(int u, int p){
	if(mrk[u] == 1) return u;
	int mx = -1;
	for(int nxt: adj[u]){
		if(nxt == p) continue;
		mx = max(mx, go(nxt, u));
	}
	return mx;
}

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		for(int a=0;a<=n;a++){
			adj[a].clear();
			mrk[a] = 0;
		}
		for(int a=1;a<n;a++){
			int i, j;
			scanf("%d%d", &i, &j);
			adj[i].pb(j);
			adj[j].pb(i);
		}
		int n1;
		scanf("%d", &n1);
		for(int a=0;a<n1;a++){
			int x;
			scanf("%d", &x);
			mrk[x] = 1;
		}
		scanf("%d", &k);
		q.clear();
		for(int a=0;a<k;a++){
			int x;
			scanf("%d", &x);
			q.pb(x);
		}
		printf("B %d\n", q[0]);
		fflush(stdout);

		int x;
		scanf("%d", &x);
		int v = go(x, x);
		printf("A %d\n", v);
		fflush(stdout);

		int ov;
		scanf("%d", &ov);
		
		bool has = false;
		for(int x: q)
			if(x == ov)
				has = true;
		if(has)
			printf("C %d\n", v);
		else
			puts("C -1");
		fflush(stdout);
	}
}
