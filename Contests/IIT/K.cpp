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
const ll INF = 11234567890123456LL;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

set<pli> q;

ll d[MAXN], ate[MAXN];
int S, T, nb, bst[MAXN];

void zera(){
	for(int a=0;a<n;a++){
		d[a] = INF;
	}
}

vector<pil> adj[MAXN];
int np, p[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		d[a] = INF;
		ate[a] = INF;
	}
	for(int a=0;a<m;a++){
		int i, j;
		ll c;
		scanf("%d %d %lld", &i, &j, &c);
		adj[i].pb(pil(j, c));
		adj[j].pb(pil(i, c));
	}

	scanf("%d", &np);
	for(int a=0;a<np;a++){
		scanf("%d", p+a);
	}

	scanf("%d", &nb);
	for(int a=0;a<nb;a++){
		int x;
		scanf("%d", &x);
		bst[x] = 1;
	}
	scanf("%d%d", &S, &T);

	zera();
	d[T] = 0;
	ate[T] = 0;
	q.insert(pil(0, T));
	while(!q.empty()){
		pli top = *q.begin();
		q.erase(q.begin());
		int u = top.snd;
		for(pil ar: adj[u]){
			int nxt = ar.fst;
			ll cus = ar.snd;
			//debug("nxt", nxt, cus);
			//debug(d[nxt], d[u], cus);
			if(d[nxt] > d[u] + cus){
				if(d[nxt] != INF)
					q.erase(pli(d[nxt], nxt));
				d[nxt] = d[u] + cus;
				q.insert(pli(d[nxt], nxt));
			}
		}
	}
	ll lt = d[S];
	for(int a=0;a<n;a++)
		ate[a] = (bst[a] ? (d[a]+1)/2 : d[a]); 
	
	zera();
	for(int a=0;a<np;a++){
		d[p[a]] = 0;
		q.insert(pli(0, p[a]));
	}
	ll res = LLONG_MAX;
	while(!q.empty()){
		pli top = *q.begin();
		q.erase(q.begin());
		int u = top.snd;
		res = min(res, top.fst + ate[u]);
		for(pil ar: adj[u]){
			int nxt = ar.fst;
			ll cus = ar.snd;
			if(d[nxt] > d[u] + cus){
				if(d[nxt] != INF)
					q.erase(pli(d[nxt], nxt));
				d[nxt] = d[u] + cus;
				q.insert(pli(d[nxt], nxt));
			}
		}
	}
	//debug("lt", lt, "res", res);
	if(res <= lt)
		puts("-1");
	else
		printf("%lld\n", lt);
}

