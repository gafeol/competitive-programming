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

const int MAXN = 2123;

int n, m, k;
int s[MAXN];

vector<int> adj[MAXN], inv[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int mrk[MAXN];
int vis;
int tempo;

void go(int u){
	mrk[u] = tempo;
	vis++;
	for(int nxt: adj[u]){
		if(mrk[nxt] == tempo) continue;
		go(nxt);
	}
}

void igo(int u){
	mrk[u] = tempo;
	vis++;
	for(int nxt: inv[u]){
		if(mrk[nxt] == tempo) continue;
		igo(nxt);
	}
}

int main (){
	while(scanf("%d%d", &n, &m) && n+m){
		for(int a=0;a<n;a++){
			adj[a].clear();
			inv[a].clear();
		}
		for(int a=0;a<m;a++){
			int i, j, t;
			scanf("%d %d %d", &i, &j, &t);
			i--;j--;
			adj[i].pb(j);
			inv[j].pb(i);
			if(t-1){
				adj[j].pb(i);
				inv[i].pb(j);
			}
		}
		tempo++;
		vis = 0;
		go(0);
		if(vis != n){
			puts("0");
			continue;
		}
		tempo++;
		vis = 0;
		igo(0);
		if(vis == n)
			puts("1");
		else
			puts("0");
	}
}

