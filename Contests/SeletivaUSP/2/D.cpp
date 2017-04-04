#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
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

const int MAXN = 2123, INF = 0x3f3f3f3f;

int n, m, k, cp;
int s[MAXN], p[MAXN], c[MAXN], ind[MAXN], dp[MAXN][123];

vector<pii> adj[MAXN];
set<pip> q;

inline pip mk(int x, int i, int j){
	return pip(x, pii(i, j));
}

int main (){
	for_tests(t, tt){
		scanf("%d%d%d", &n, &m, &k);
		for(int a=0;a<=n;a++){
			adj[a].clear();
		}
		scanf("%d", &cp);
		for(int a=0;a<m;a++){
			int i, j, cus;
			scanf("%d%d%d", &i, &j, &cus);
			adj[i].pb(pii(j, cus));
			adj[j].pb(pii(i, cus));
		}
		memset(c, INF, sizeof(c));
		memset(ind, -1, sizeof(ind));
		for(int a=0;a<k;a++){
			scanf("%d %d", &p[a], &c[a]);
			ind[p[a]] = a;
		}
		int beg, end;
		scanf("%d%d", &beg, &end);
		memset(dp, INF, sizeof(dp));
		dp[beg][ind[beg]] = 0;
		q.insert(mk(0, beg, ind[beg]));
		int res = INT_MAX;
		while(!q.empty()){
			pip top = *q.begin();
			q.erase(top);
			int u = top.snd.fst;
			int lst = top.snd.snd;
			debug("d[%d][%d (= %d)] -> %d\n", u, lst, p[lst], dp[u][lst]);
			if(u == end){
				res = min(res, dp[u][lst]);
			}
			if(ind[u] != -1 && ind[u] != lst && dp[u][ind[u]] > dp[u][lst]){
				if(dp[u][ind[u]] != INF)
					q.erase(mk(dp[u][ind[u]], u, ind[u]));
				dp[u][ind[u]] = dp[u][lst];
				q.insert(mk(dp[u][ind[u]], u, ind[u]));
			}
			for(pii ar: adj[u]){
				int nxt = ar.fst;
				int cus = ar.snd;
				if(cus + (dp[u][lst] - dp[p[lst]][lst])/c[lst] > cp){
					debug("nao deu a gas pra fazer (%d, %d) -> (%d, %d) -> (%d %d)\n", p[lst], lst, u, lst, nxt, lst);
					continue;
				}
				if(dp[nxt][lst] > dp[u][lst] + cus*c[lst]){
					if(dp[nxt][lst] != INF)
						q.erase(mk(dp[nxt][lst], nxt, lst));
					dp[nxt][lst] = dp[u][lst] + cus*c[lst];
					q.insert(mk(dp[nxt][lst], nxt, lst));
					debug("u %d %d -> %d %d cus %d dp[%d][%d] %d\n", u, lst, nxt, lst, cus*c[lst], nxt, lst, dp[nxt][lst]);
				}
			}
		}
		printf("%d\n", res);
	}
}
