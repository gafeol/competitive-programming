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

void go(int v, int 

set<pii> queue

int main (){
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int a=0;a<m;a++){
		ll i, j, c;
		scanf("%lld%lld%lld", &i, &j, &c);
		adj[i].pb(pii(j, c));
	}
	mrk[1][1] = 0;
	go(1, 0, 1);
	while(v != 0){
		res.pb(v);
		v = mrk[v][nc];
		nc--;
	}
	for(int a=res.size()-1;a>=0;a--){
		printf("%lld ", res[a]);
	}
}
