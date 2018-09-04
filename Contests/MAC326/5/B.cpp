#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
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

const int MAXN = 212345;

int n, m, k;
ll s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

ll d[MAXN];
set<pli> q;

vector<pil> adj[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
		int i, j;
		ll c;
		scanf("%d%d%lld", &i, &j, &c);
		i--;
		j--;
		adj[i].pb(pil(j, 2ll*c));
		adj[j].pb(pil(i, 2ll*c));
	}
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
		q.insert(pli(s[a], a));
		d[a] = s[a];
	}

	while(!q.empty()){
		pli top = *q.begin();
		q.erase(q.begin());
		int u = top.snd;
		for(pil ar: adj[u]){
			int nxt = ar.fst;
			ll c = ar.snd;
			if(d[nxt] > d[u] + c){
				q.erase(pli(d[nxt], nxt));
				d[nxt] = d[u] + c;
				q.insert(pli(d[nxt], nxt));
			}
		}
	}
	for(int a=0;a<n;a++){
		printf("%lld%c", d[a], " \n"[a == n-1]);
	}
}

