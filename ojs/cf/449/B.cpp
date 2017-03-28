#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
#define int ll
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<int, pii> pip;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)
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
pii d[MAXN];

vector<pip> adj[MAXN];

set<ppi> q;

main (){
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int a=0;a<m;a++){
		int i, j, c;
		scanf("%lld %lld %lld", &i, &j, &c);	
		adj[i].pb(pip(j, pii(c, 0)));
		adj[j].pb(pip(i, pii(c, 0)));
	}
	for(int a=0;a<k;a++){
		int b, c;
		scanf("%lld %lld", &b, &c);
		adj[1].pb(pip(b, pii(c, 1)));
		adj[b].pb(pip(1, pii(c, 1)));
	}
	for(int a=0;a<=n;a++){
		d[a].fst = LLONG_MAX;
	}
	d[1].fst = 0;
	int res = k;
	q.insert(ppi(pii(0, 0), 1));
	while(!q.empty()){
		ppi top = *q.begin();
		q.erase(top);
		int u = top.snd;
		res -= (top.fst.snd);
		for(pip nxt:adj[u]){
			int v = nxt.fst;
			pii cus = nxt.snd;
			if(d[v].fst > d[u].fst + cus.fst || (d[v].fst == d[u].fst + cus.fst && cus.snd == 0)){
				if(d[v].fst != LLONG_MAX) q.erase(ppi(d[v], v));
				d[v].fst = d[u].fst + cus.fst;
				d[v].snd = cus.snd;
				q.insert(ppi(d[v], v));
			}
		}
	}
	printf("%lld\n", res);
}
