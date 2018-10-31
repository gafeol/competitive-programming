#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tp;
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

const int MAXN = 351, MAXM = 351*351;
const int LOGM = 17;

int n, m, k;
int pai[MAXN], sz[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}
tuple<int, int, int> s[MAXM];

vector<tuple<int, int, int> > nxt[MAXM];
int mx[MAXM];
int prox[MAXM];

int raiz(int u){
	if(pai[u] == u) return u;
	return pai[u] = raiz(pai[u]);
}

int cnt;

inline bool join(int u, int v){
	//printf("join? %d %d\n", u, v);
	int ru = raiz(u);
	int rv = raiz(v);
	if(ru == rv) return false;
	if(sz[ru] < sz[rv]){
		swap(ru, rv);
		swap(u, v);
	}
	pai[rv] = ru;
	sz[ru] += sz[rv];
	cnt++;
	//puts("JOIN");
	return true;
}

inline void zera(){
	for(int a=0;a<n;a++){
		pai[a] = a;
		sz[a] = 1;
	}
	cnt = 1;
}

int main (){
	while(scanf("%d", &n) && n){
		scanf("%d", &m);
		for(int a=0;a<m;a++){
			int i, j, c;
			scanf("%d%d%d", &i, &j, &c);
			s[a] = {c, i, j};
			nxt[a].clear();
		}
		sort(s, s+m);
		int i=0;
		s[m] = {0, -1, -1};
		for(int j = 1;j<=m;j++){
			if(s[i] == s[j]) continue;	
			while(s[i] != s[j]){
				prox[i] = j;
				i++;
			}
		}
		for(int a=m-1;a>=0;a--){
			zera();
			int u, v, c;
			tie(c, u, v) = s[a];

			nxt[a].pb({s[a]});
			mx[a] = c;
			join(u, v);
			int an = prox[a];
			if(an == m) continue;
			for(tp ar: nxt[an]){
				tie(c, u, v) = ar;	
				if(join(u, v)){
					nxt[a].pb(ar);
					mx[a] = max(mx[a], c);
				}
			}
		}

		int res = INT_MAX;
		for(int a=0;a<m;a++){
			int u, v, c;
			tie(c, u, v) = s[a];

			if(nxt[a].size() == n-1)
				res = min(mx[a] - c, res);
		}
		printf("%d\n", res);
	}
}

