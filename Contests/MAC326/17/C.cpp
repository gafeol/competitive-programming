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

const int MAXN = 11234;
const ll INF = LLONG_MAX;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

ll d[MAXN];
vector<pil> adj[MAXN];

ll dij(ll x){
	for(int a=0;a<=n;a++)
		d[a] = INF;
	d[1] = 0;
	set<pli> q;
	q.insert({0, 1});
	while(!q.empty()){
		pli t = *q.begin();
		q.erase(q.begin());
		int u = t.snd;
		for(pil ar: adj[u]){
			int nxt = ar.fst;
			ll cus = ar.snd;
			if(cus > x) continue;
			if(d[nxt] > d[u] + cus){
				if(d[nxt] != INF)
					q.erase({d[nxt], nxt});
				d[nxt] = d[u] + cus;
				q.insert({d[nxt], nxt});
			}
		}
	}
	return d[n];
}

ll mx;

bool go(ll m){
	return dij(m) <= mx;
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
	for(int a=0;a<m;a++){
		int i, j;
		ll c;
		scanf("%d%d%lld", &i, &j, &c);
		adj[i].pb({j, c});
		adj[j].pb({i, c});
	}
	ll sh = dij(LLONG_MAX);

	mx = (sh*(100+k))/100;
	ll i = 0, j = 1000000000;
	while(i < j){
		ll mid = (i + j)/2ll;
		if(go(mid))
			j = mid;					
		else
			i = mid+1;
	}
	printf("%lld\n", i);
}

