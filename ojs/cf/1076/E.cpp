#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 312345;

int n, m, k;
ll res[MAXN];

map<ll, ll> som;

ll acc;

vector<pll> sp[MAXN];
vector<int> adj[MAXN];

void go(int u, int p, int h = 1){
	for(pll x : sp[u]){
		//printf("U %d sp %lld %lld\n", u, x.fst, x.snd);
		acc += x.fst;	
		som[h + x.snd+1] -= x.fst;
	}
	acc += som[h];
	//printf(" acc += %lld\n", som[h]);
	//printf("u %d acc %lld\n", u, acc);

	res[u] = acc;

	for(int nxt: adj[u]){
		if(nxt == p) continue;
		go(nxt, u, h+1);
	}

	acc -= som[h];
	for(pll x: sp[u]){
		acc -= x.fst;
		som[h + x.snd+1] += x.fst;
	}
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<n;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		int u;
		ll d, x;
		scanf("%d%lld%lld", &u, &d, &x);
		sp[u].pb(pll(x, d));
	}
	go(1, 1);
	for(int a=1;a<=n;a++){
		printf("%lld ", res[a]);
	}
}

