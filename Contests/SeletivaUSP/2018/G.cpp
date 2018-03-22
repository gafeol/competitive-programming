#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, pii> plp;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 11234, MAXK = 112;
const ll  INF = LLONG_MAX;

int n, k;

ll x[MAXN], c[MAXN], r[MAXN], p[MAXN];
ll d[MAXN][MAXK];

int fst[MAXN], lst[MAXN];

inline int bb(int i, int j, ll val){
	while(i < j){
		int m = (i+j)/2;
		if(x[m] >= val)
			j = m;
		else
			i = m+1;
	}
	return i;
}

vector<pil> adj[MAXN];
set<plp> q;

plp mk(ll x, int a, int b){
	return plp(x, pii(a, b));
}

void rel(int u, int g, ll x){
	if(d[u][g] > x){
		if(d[u][g] != INF)
			q.erase(mk(d[u][g], u, g));
		d[u][g] = x;
		q.insert(mk(d[u][g], u, g));
	}
}

int main (){
	int deg = 1;
	while(scanf("%d%d", &n, &k) != EOF && n + k > 0){
		int tot = 0;
		for(int a=2;a<=n;a++)
			scanf("%lld", x+a);
		for(int a=1;a<=n;a++)
			scanf("%lld", c+a);
		for(int a=1;a<=n;a++)
			scanf("%lld", r+a);
		for(int a=1;a<=n;a++)
			scanf("%lld", p+a);

		x[n+1] = INF;
		for(int a=1;a<=n;a++)
			adj[a].clear();
		for(int a=n;a>=1;a--){
			fst[a] = bb(1, a, x[a]-r[a]);
			lst[a] = bb(a, n+1, x[a]+r[a]+1)-1;
			adj[fst[a]].pb(pil(lst[a]+1, c[a]));
		}

		for(int a=1;a<=n+1;a++)
			for(int b=0;b<=k;b++)
				d[a][b] = INF;

		d[1][0] = 0;
		q.insert(mk(0, 1, 0));
		while(!q.empty()){
			plp top = *q.begin();
			q.erase(top);
			int u = top.snd.fst;
			int g = top.snd.snd;
			if(g < k)
				rel(u, g+1, d[u][g]);
			if(u <= n)
				rel(u+1, g, d[u][g] + p[u]);
			if(u > 0)
				rel(u-1, g, d[u][g]);
			for(pil ar: adj[u]){
				int nxt = ar.fst;
				ll cus = ar.snd;
				rel(nxt, g+1, d[u][g] + cus);
			}
		}
		printf("Case %d: %lld\n", deg++, d[n+1][k]);
	}
}
