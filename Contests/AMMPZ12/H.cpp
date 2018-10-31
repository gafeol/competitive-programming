#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
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
const ll INF = 300000000000000LL;

int n, m, k;
int s[MAXN];
ll z[MAXN], u[MAXN];

vector<int> adj[MAXN], inv[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int ind[MAXN];

ll d[MAXN], nf[MAXN], df[MAXN], res[MAXN];

set<pli> q;

bool cmp(int a, int b){
	return z[a] < z[b];
}

void add(int a){
	q.insert(pli(min(d[a], df[a]), a));
}

void rmv(int a){
	q.erase(pli(min(d[a], df[a]), a));
}

int jafoi[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int sz;
		scanf("%lld%lld%d", u+a, z+a, &sz);
		while(sz--){
			int x;
			scanf("%d", &x);
			x--;
			adj[a].pb(x);
			inv[x].pb(a);
		}
	}
	for(int a=0;a<n;a++){
		df[a] = u[a];
		for(int nxt: adj[a])
			df[a] += z[nxt];

		d[a] = z[a];
		add(a);
	}
	while(!q.empty()){
		int a = q.begin()->snd;
		q.erase(q.begin());
		if(jafoi[a]) continue;
		jafoi[a] = 1;
		res[a] = min(d[a], df[a]);
		for(int bef: inv[a]){
			if(jafoi[bef]) continue;
			df[bef]	-= z[a];	 
			df[bef] += res[a];
			add(bef);
		}
	}
	printf("%lld\n", res[0]);
}

