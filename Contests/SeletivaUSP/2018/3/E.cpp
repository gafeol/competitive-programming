#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...)// fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 312345, LOGN = 20;

int n, m, k;
int s[MAXN];

int p[MAXN][LOGN];
int mn[MAXN][LOGN];
int mx[MAXN][LOGN];
int tot[MAXN][LOGN];

int h[MAXN];

vector<int> adj[MAXN];

void go(int u, int pai){
	p[u][0] = pai;
	mn[u][0] = s[u];
	mx[u][0] = s[u];
	tot[u][0] = s[u];
	h[u] = h[pai] + 1;
	for(int i = 1;i<LOGN;i++){
		p[u][i] = p[p[u][i-1]][i-1];
		tot[u][i] = tot[u][i-1] + tot[p[u][i-1]][i-1];
		mn[u][i] = min(mn[u][i-1], tot[u][i-1] + mn[p[u][i-1]][i-1]);
		mx[u][i] = max(mx[u][i-1], tot[u][i-1] + mx[p[u][i-1]][i-1]);
	}
	for(int nxt: adj[u]){
		if(nxt == pai) continue;
		go(nxt, u);
	}
}

int lca(int u, int v){
	if(h[u] != h[v]){
		if(h[u] < h[v]) swap(u, v);
		for(int i=LOGN-1;i>=0;i--){
			if(h[p[u][i]] > h[v]){
				u = p[u][i];
			}
		}
		u = p[u][0];
	}
	if(u == v) return u;
	for(int i=LOGN-1;i>=0;i--){
		if(p[u][i] != p[v][i]){
			u = p[u][i];
			v = p[v][i];
		}
	}
	return p[u][0];
}

int ok;

int qryy(int u, int v, int t){
	int c = 0;
	if(u == v) return c;
	for(int i=LOGN-1;i>=0;i--){
		if(h[p[u][i]] > h[v]){
			if(!t){
				if(c + mn[u][i] < 0){
					debug("c %d + mn[%d][%d] %d < 0\n", c, u, i, mn[u][i]);
					ok = 0;
				}
			}
			else{
				if(c + mx[u][i] > 0){
					debug("c %d + mx[%d][%d] %d > 0\n", c, u, i, mx[u][i]);
					ok = 0;
				}
			}
			c += tot[u][i];
			u = p[u][i];
		}
	}
	c += tot[u][0];
	if(!t){
		if(c < 0){
			//debug("tot %d %d %d - c %d < 0\n", u, v, t, c);
			ok = 0;
		}
	}
	else{
		if(c > 0){
			//debug("tot %d %d %d - c %d > 0\n", u, v, t, c);
			ok = 0;
		}
	}
	return c;
}

int qry(int u, int v){
	int lc = lca(u, v);
	debug("u %d v %d lc %d\n", u, v, lc);
	ok = 1;
	int tot = qryy(u, lc, 0) + qryy(v, lc, 1) + s[lc];
	return (ok && !tot);
}

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &m);
		for(int a=0;a<=n;a++){
			adj[a].clear();
		}
		for(int a=0;a<n;a++){
			int i, j;
			scanf("%d %d", &i, &j);
			adj[i].pb(j);
			adj[j].pb(i);
		}
		for(int a=1;a<=n;a++){
			char c;
			scanf(" %c", &c);
			s[a] = (c == '(')*2 - 1;
		}
		h[1] = 0;
		go(1, 1);
		for(int a=0;a<m;a++){
			int i, j;
			scanf("%d%d", &i, &j);
			if(qry(i, j))
				puts("Yes");
			else
				puts("No");
		}
	}
}

