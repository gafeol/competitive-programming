

#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<pii, ll> ppi;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

ll n, m, k;

map <ll, ll> mrk[MAXN], d[MAXN];

vector<pii> adj[MAXN];

set<pair<pii, ll> > q;

vector<ll> res;

int main (){
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int a=0;a<m;a++){
		ll i, j, c;
		scanf("%lld%lld%lld", &i, &j, &c);
		adj[i].pb(pii(j, c));
	}
	q.insert(ppi(pii(1ll, 0ll), 1ll));
	mrk[1][1] = 0;
	ll mxc = -1;
	while(!q.empty()){
		ppi t = *q.begin();
		q.erase(t);
		ll u = t.snd;
		ll dis = t.fst.snd;
		ll nc = t.fst.fst;
		for(pii nxt: adj[u]){
			ll v = nxt.fst;
			ll pa = nxt.snd;
			if(!d[v].count(nc+1) || (d[v].count(nc+1) && d[v][nc+1] > dis + pa)){
				if(d[v].count(nc+1))
					q.erase(ppi(pii(nc+1, d[v][nc+1]), v));
				d[v][nc+1] = dis + pa;
				mrk[v][nc+1] = u;
				q.insert(ppi(pii(nc+1, d[v][nc+1]), v));
				if(v == n && d[v][nc+1] <= k)
					mxc = nc+1;
			}
		}
	}
	printf("%lld\n", mxc);
	ll v = n;
	ll nc = mxc;
	while(v != 0){
		res.pb(v);
		v = mrk[v][nc];
		nc--;
	}
	for(int a=res.size()-1;a>=0;a--){
		printf("%lld ", res[a]);
	}
}
