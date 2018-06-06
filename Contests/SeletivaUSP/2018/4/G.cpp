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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1023;

int n, m, k, r;
int s[MAXN];

vector<int> adj[MAXN];

int pai[MAXN];
int sz[MAXN], p[MAXN], sum[MAXN];
int lst[MAXN], fst[MAXN];

int prox[MAXN];

int raiz(int u){
	if(p[u] == u) return u;
	return p[u] = raiz(p[u]);
}

struct cj{
	pii f;
	int id;
	bool operator < (const cj o) const {
		return (((ll)f.fst * o.f.snd > (ll)f.snd * o.f.fst) || (((ll)f.fst * o.f.snd == (ll)f.snd * o.f.fst) && id < o.id));
	}
};

set<cj> q;

void join(int u, int v){
	u = raiz(u);
	v = raiz(v);


	debug("prox %d: %d\n", lst[v], fst[u]);
	prox[lst[v]] = fst[u];

	fst[u] = fst[v];
	lst[v] = lst[u];

	if(sz[u] < sz[v])
		swap(u, v);
	p[v] = u;
	sz[u] += sz[v];
	sum[u] += sum[v];
}

void dfs(int u, int p){
	pai[u] = p;

	q.insert({{s[u], 1}, u}); 
	debug("insere %d %d %d\n", s[u], 1, u);
	for(int nxt: adj[u]){
		if(nxt == p) continue;
		dfs(nxt, u);
	}
} 
int main (){
	while(scanf("%d%d", &n, &r) != EOF && n + m != 0){
		for(int a=0;a<=n;a++){
			prox[a] = -1;
			adj[a].clear();
			p[a] = a;
			sz[a] = 1;
			fst[a] = a;
			lst[a] = a;
		}
		for(int a=1;a<=n;a++){
			scanf("%d", s+a);	
			sum[a] = s[a];
		}
		for(int a=0;a<n-1;a++){
			int i, j;
			scanf("%d %d", &i, &j);
			adj[i].pb(j);
			adj[j].pb(i);
		}
		dfs(r, r);
		while(!q.empty()){
			cj conj = *q.begin();
			q.erase(q.begin());
			int u = conj.id;
			assert(u == raiz(u));
			int pri = fst[u];
			assert(raiz(pri) == u);
			if(pai[pri] != pri){
				debug("liga pri %d (%d) com %d (%d)\n", pri,raiz(pri), pai[pri], raiz(pai[pri]));
				int rp = raiz(pai[pri]);
				debug("erase %d %d %d\n", sum[rp], sz[rp], rp);
				q.erase({{sum[rp], sz[rp]}, rp});
				join(pri, pai[pri]);	
				int r = raiz(pri);
				debug("insere %d %d %d\n", sum[r], sz[r], r); 
				q.insert({{sum[r], sz[r]}, r});
			}
		}
		int u = r;
		int t = 1;
		int res = 0;
		while(u != -1){
			res += t*s[u];
			t++;
			u = prox[u];
		}
		printf("%d\n", res);
	}
}
