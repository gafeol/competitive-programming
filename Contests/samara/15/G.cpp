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
inline ll mod(ll x) { return x % modn; };

const int MAXN = 212345;
const ll INF = 9000000000000000LL;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}


vector<pil> adj[MAXN];

set<pli> q;

ll d[MAXN];
int sp[MAXN];
ll res;
int resu, resv;
int ult[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%d", sp+a);
		if(sp[a]){
			d[a] = 0;
			q.insert(pli(0, a));
		}
		else
			d[a] = INF;
		ult[a] = a;
	}
	for(int a=0;a<m;a++){
		int i, j;
		ll c;
		scanf("%d %d %lld", &i, &j, &c);
		i--;j--;
		adj[i].pb(pil(j, c));
		adj[j].pb(pil(i, c));
	}
	res = LLONG_MAX;
	while(!q.empty()){
		pli top = *q.begin();	
		q.erase(q.begin());
		int u = top.snd;
		for(pil ar: adj[u]){
			int nxt = ar.fst;
			ll cus = ar.snd;
			if(d[nxt] > d[u] + cus){
				if(d[nxt] != INF)
					q.erase(pli(d[nxt], nxt));
				d[nxt] = d[u] + cus;
				q.insert(pli(d[nxt], nxt));
				ult[nxt] = ult[u];
			}
		}
	}
	for(int a=0;a<n;a++){
		for(pil ar: adj[a]){
			int b = ar.fst;
			if(ult[a] != ult[b] && res > d[a] + d[b] + ar.snd){
				res = d[a] + d[b] + ar.snd;
				resu = ult[a];
				resv = ult[b];
			}
		}
	}
	if(res >= INF){
		puts("No luck at all");
	}
	else{
		printf("%lld\n", res);
		printf("%d %d\n", resu+1, 1+resv);
	}
}


