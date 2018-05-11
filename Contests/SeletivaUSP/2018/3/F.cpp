#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
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

const int MAXN = 212345, LOGN = 20;

int n, m;
int s[MAXN], p[MAXN];
int ant[MAXN][LOGN];
int mrk[MAXN];

vector<ll> add[MAXN], rmv[MAXN];

vector<int> adj[MAXN];
vector<plp> ares;

multiset<ll> pes[MAXN];
int indp[MAXN];

int h[MAXN], sz[MAXN];
ll mn[MAXN];

bool cmp(int a, int b){
	return ares[a].fst < ares[b].fst;
}

int raiz(int u){
	if(p[u] == u) return u;
	return p[u] = raiz(p[u]);
}

int join(int i, int j){
	i = raiz(i);
	j = raiz(j);
	if(i == j) return 0;
	if(sz[i] > sz[j])
		swap(i, j);
	p[i] = j;
	sz[j] += sz[i];
	return 1;
}

void go(int u, int pai){
	h[u] = h[pai] + 1;
	ant[u][0] = pai;
	for(int i=1;i<LOGN;i++)
		ant[u][i] = ant[ant[u][i-1]][i-1];
	for(int in: adj[u]){
		plp ar = ares[in];
		int nxt = (ar.snd.fst == u ? ar.snd.snd : ar.snd.fst);
		if(nxt == pai) continue;
		go(nxt, u);
	}
}

void set_join(int uu, int vv){
	int u = indp[uu];
	int v = indp[vv];
	if(pes[v].empty())
		return ;
	if(pes[u].empty()){
		indp[uu] = v;
		return ;
	}
	if(pes[u].size() >= pes[v].size()){
		for(auto it: pes[v])
			pes[u].insert(it);
	}
	else{
		for(auto it: pes[u])
			pes[v].insert(it);
		indp[uu] = v;
	}
}

void dfs(int u, int pai){
	for(int in: adj[u]){
		plp ar = ares[in];
		int nxt = (ar.snd.fst == u ? ar.snd.snd : ar.snd.fst);
		if(nxt == pai) continue;
		dfs(nxt, u);
		if(pes[indp[nxt]].empty())
			mn[in] = -1;
		else
			mn[in] = *pes[indp[nxt]].begin();
		set_join(u, nxt);
	}
	for(ll a: add[u]){
		debug("add %lld\n", a);
		pes[indp[u]].insert(a);
	}
	for(ll a: rmv[u]){
		debug("rmv %lld\n", a);
		pes[indp[u]].erase(pes[indp[u]].find(a));
	}
	/*
	printf("u %d\n	", u);
	for(auto it: pes[indp[u]]){
		printf("%lld ", it);
	}
	puts("");
	*/
}

int lca(int u, int v){
	if(h[u] != h[v]){
		if(h[u] < h[v])
			swap(u, v);
		for(int i=LOGN-1;i>=0;i--){
			if(h[ant[u][i]] > h[v])
				u = ant[u][i];
		}
		u = ant[u][0];
	}
	if(u == v) return u;
	for(int i=LOGN-1;i>=0;i--){
		if(ant[u][i] != ant[v][i]){
			u = ant[u][i];
			v = ant[v][i];
		}
	}
	return ant[u][0];
}

int ind[MAXN];

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &m);
		ares.clear();
		for(int a=0;a<=n;a++){
			pes[a].clear();
			p[a] = a;
			sz[a] = 1;
			indp[a] = a;
			add[a].clear();
			rmv[a].clear();
			adj[a].clear();
		}
		for(int a=0;a<m;a++){
			ll k;
			int i, j;
			scanf("%d %d %lld", &i, &j, &k);
			ares.pb(plp(k, pii(i, j)));
			ind[a] = a;
			mrk[a] = 0;
		}
		sort(ind, ind+m, cmp);
		ll sum = 0;
		for(int aa=0;aa<m;aa++){
			int a = ind[aa];
			debug("a %d\n", a);
			if(join(ares[a].snd.fst, ares[a].snd.snd)){
				debug("join %d %d aresta %d\n", ares[a].snd.fst, ares[a].snd.snd, a);
				mrk[a] = 1;
				adj[ares[a].snd.fst].pb(a);
				adj[ares[a].snd.snd].pb(a);
				sum += ares[a].fst;
			}
		}
		int r = raiz(1);
		int fim = 0;
		for(int a=2;a<=n;a++){
			if(r != raiz(a)){
				for(int a=0;a<m;a++)
					puts("-1");
				fim = 1;
				break;
			}
			
		}
		if(fim) continue;
		go(1, 1);
		for(int a=0;a<m;a++){
			if(!mrk[a]){
				int u = ares[a].snd.fst;
				int v = ares[a].snd.snd;
				int lc = lca(u, v);
				add[u].pb(ares[a].fst);
				add[v].pb(ares[a].fst);
				rmv[lc].pb(ares[a].fst);
				rmv[lc].pb(ares[a].fst);
			}
		}
		dfs(1, 1);
		for(int a=0;a<m;a++){
			if(!mrk[a])
				printf("%lld\n", sum);
			else{
				if(mn[a] == -1)
					puts("-1");
				else
					printf("%lld\n", sum + mn[a] - ares[a].fst);
			}
		}
	}
}

