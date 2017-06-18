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

const int MAXN = 212345;

int n, m, k;

vector<int> adj[MAXN], inv[MAXN], invC[MAXN];

map<int, int> ind;

int dp[MAXN], deg[MAXN];
int sz[MAXN];

int pai[MAXN];

int raiz(int i){
	if(pai[i] == i)
		return i;
	return pai[i] = raiz(pai[i]);
}

void join(int i, int j){
	i = raiz(i);
	j = raiz(j);

	if(i == j) return;

	if(sz[i] > sz[j])
		swap(i, j);

	pai[i] = j;
	dp[j] = max(dp[j], dp[i]);
	sz[j] += sz[i];
}

int mrk[MAXN];
int vis[MAXN];
int vis2[MAXN];

stack<int> cic;

void DFSUtil(int v)
{
	vis2[v] = true;
	cic.push(v);
	for (int u: inv[v]){
		if (!vis2[u])
			DFSUtil(u);
	}
}

stack<int> st;

void fillOrder(int v)
{
	vis[v] = true;
	for(int u: adj[v])
		if(!vis[u])
			fillOrder(u);
	st.push(v);
}

void SCCs(){
	for(int i = 1; i <= n; i++)
		vis[i] = false;

	// Fill vertices in stack according to their finishing times
	for(int i = 1; i <= n; i++)
		if(vis[i] == false)
			fillOrder(i);

	// Mark all the vertices as not visited (For second DFS)
	for(int i = 1; i <= n; i++)
		vis2[i] = false;

	while (!st.empty()){
		int v = st.top();
		st.pop();

		if (vis2[v] == false){
			DFSUtil(v);
			int u = cic.top();
			cic.pop();
			while(!cic.empty()){
				join(u, cic.top());
				cic.pop();
			}
		}
	}
}

void go(int u){
	mrk[u] = 1;
	for(int nxt: adj[u]){
		if(mrk[nxt]) continue;
		join(u, nxt);
		go(nxt);
	}
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n;a++){
		pai[a] = a;
		sz[a] = 1;
		deg[a] = 0;
		dp[a] = 0;
	}
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		if(i == j) continue;
		adj[i].pb(j);
		inv[j].pb(i);
	}

	SCCs();

	for(int u=1;u<=n;u++){
		int ru = raiz(u);
		for(int i=0;i < inv[u].size();i++){
			int v = inv[u][i];
			if(raiz(v) == ru) continue;
			invC[ru].pb(raiz(v));
		}
	}


	for(int a=1;a<=n;a++){
		int ra = raiz(a);
		debug("inv[%d]: ", ra);
		for(int i=0;i<invC[ra].size();i++){
			debug("%d ", invC[ra][i]);
		}
		debug("\n");
	}

	queue<int> q;

	for(int aa=1;aa<=n;aa++){
		int a = raiz(aa);
		for(int nxt:invC[a]){
			deg[nxt]++;
		}
	}

	for(int aa=1;aa<=n;aa++){
		int a = raiz(aa);
		if(deg[a] == 0)
			q.push(a);
	}

	while(!q.empty()){
		int u = q.front();
		q.pop();
		mrk[u] = 1;
		for(int b: invC[u]){
			int nxt = raiz(b);
			if(nxt == u) continue;
			debug("dp[%d] = max(%d, dp[%d] %d + sz[u] %d\n", nxt, dp[nxt], u, dp[u], sz[u]);
			dp[nxt] = max(dp[nxt], dp[u] + sz[u]);
			deg[nxt]--;
			if(deg[nxt] == 0)
				q.push(nxt);
		}
	}
	for(int a=1;a<=n;a++){
		int ra = raiz(a);
		dp[ra] = max(dp[a], dp[ra]);
	}

	int res = 0, cnt = 0;
	for(int a=1;a<=n;a++){
		int ra = raiz(a);
		debug("cara %d raiz %d dp %d sz %d\n", a, ra, dp[ra], sz[ra]);
		if(res < dp[ra] + sz[ra])
			res = dp[ra] + sz[ra];

	}
	for(int a=1;a<=n;a++){
		int ra = raiz(a);
		if(res == dp[ra] + sz[ra])
			cnt++;
	}
	printf("%d %d\n", res, cnt);
}
