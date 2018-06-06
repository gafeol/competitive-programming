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
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXM = 512345;
const int MAXN = 212345;

int n, m, k;
int s[MAXN];

int out[MAXN];
int ind[MAXN], oud[MAXN];


vector<int> adj[MAXN], inv[MAXN];

int nc, visc;
int cy[MAXN], vis[MAXN], mn[MAXN], id[MAXN];
stack<int> q;

void reset(int nn=n){
	while(!q.empty()) q.pop();
	nc = visc = 0;
	for(int a=0;a<=n;a++){
		adj[a].clear();
		cy[a] = -1;
		vis[a] = 0;
	}
}


int tarjan(int u){
	q.push(u);
	vis[u] = 1;
	id[u] = visc++;
	mn[u] = id[u];
	for(int nxt: adj[u]){
		if(out[nxt]) continue;
		if(!vis[nxt])
			mn[u] = min(mn[u], tarjan(nxt));
		else if(cy[nxt] == cy[u])
			mn[u] = min(mn[u], id[nxt]);
	}
	if(mn[u] == id[u]){
		cy[u] = nc++;
		while(q.top() != u){
			cy[q.top()] = cy[u];
			q.pop();
		}
		q.pop();
	}
	return mn[u];
}

void scc(){
	// nodes 0..n-1
	for(int a=1;a<=n;a++)
		if(!vis[a] && !out[a])
			tarjan(a);
}


int res;
bool used[MAXN];
int timer, tin[MAXN], fup[MAXN];

void dfs (int v, int p = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	int children = 0;
	for(int to: adj[v]){
		if (used[to])
			fup[v] = min (fup[v], tin[to]);
		else {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] >= tin[v] && p != -1)
				res = v;
			++children;
		}
	}
	if (p == -1 && children > 1)
		res = v;
}

int timee, cnt[MAXN], see[MAXN];

void rgo(int u){
	if(see[u] == timee) return ;
	see[u] = timee;
	cnt[u]++;
	int rd = rand()%(adj[u].size());
	while(out[adj[u][rd]])
		rd = rand()%(adj[u].size());
	rgo(adj[u][rd]);
}

int main (){
	clock_t clk = clock();
	srand(time(NULL));
	scanf("%d%d", &n, &m);
	reset();
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		adj[i].pb(j);
		inv[j].pb(i);
		ind[j]++;
		oud[i]++;
	}
	queue<int> qu;
	for(int a=1;a<=n;a++){
		if(ind[a] == 0 || oud[a] == 0)
			qu.push(a);
	}
	while(!qu.empty()){
		int u = qu.front();
		out[u] = 1;
		qu.pop();
		for(int nxt: adj[u]){
			ind[nxt]--;
			if(ind[nxt] == 0 && oud[nxt] > 0)
				qu.push(nxt);
		}
		for(int ant: inv[u]){
			oud[ant]--;
			if(oud[ant] == 0 && ind[ant] > 0)
				qu.push(ant);
		}
	}
	scc();
	if(nc > 1 || nc == 0){
		puts("-1");
		return 0;
	}
	res = -1;
	for(int a=1;a<=n;a++){
		if(cy[a] == nc-1){
			dfs(a);
			break;
		}
	}
	if(res != -1){
		printf("%d\n", res);
		return 0;
	}
	while(((double)clock() - clk)/(CLOCKS_PER_SEC) < 0.95){
		int u = rand()%n+1;	
		if(out[u]) continue;
		timee++;
		rgo(u);
	}
	for(int a=1;a<=n;a++){
		if(cnt[a] == timee){
			printf("%d\n", a);
			return 0;
		}
	}
	puts("-1");
}
