#include<bits/stdc++.h>
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
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345, LOGN = 29;

int n, m, k;
int s[MAXN];

vector<int> adj[MAXN];

int r, f;
int deg[MAXN];

int mx, mxu;

void go(int u, int d, int p){
	if(mx < d){
		mx = d;
		mxu = u;
	}
	for(int nxt:adj[u]){
		if(nxt == p) continue;
		go(nxt, d+1, u);
	}
}

int h[MAXN], pai[MAXN][LOGN];

void dfs(int u, int p, int prof){
	debug("dfs %d %d %d\n", u, p, prof);
	h[u] = prof;
	pai[u][0] = p;
	for(int i=1;i<LOGN;i++){
		pai[u][i] = pai[pai[u][i-1]][i-1];
	}

	for(int nxt: adj[u]){
		if(nxt == p) continue;
		dfs(nxt, u, prof+1);
	}
}

vector<pii> ans;
ll res;


int dist(int i, int j){
	int u = i, v = j;
	if(h[i] < h[j])
		swap(i, j);
	debug("dist %d %d\n", i, j);
	if(h[i] != h[j]){
		for(int a=LOGN-1;a>=0;a--){
			if(h[pai[i][a]] > h[j])
				i = pai[i][a];
		}
		i = pai[i][0];
	}
	int lca;
	debug("nivelou %d %d\n", i, j);
	if(i == j)
		lca = i;
	else{
		for(int a=LOGN-1;a>=0;a--){
			if(pai[i][a] != pai[j][a]){
				i = pai[i][a];
				j = pai[j][a];
			}
		}
		lca = pai[i][0];
	}
	debug("achou %d\n", lca);
	debug("dist u %d v %d lca %d: %d\n", u, v, lca, h[u] + h[v] - 2*h[lca]);
	return h[u] + h[v] - 2*h[lca];
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n-1;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
		deg[i]++;
		deg[j]++;
	}
	mx = 0;
	go(1, 0, 1);
	r = mxu;
	mx = 0;
	go(r, 0, r);
	f = mxu;
	dfs(r, r, 0);

	queue<int> q;

	for(int a=1;a<=n;a++){
		if(deg[a] == 1 && a != f && a != r){
			q.push(a);
			debug("bota %d\n", a);
		}
	}

	while(!q.empty()){
		int u = q.front();
		q.pop();
		debug("folha %d\n", u);
		int d1 = dist(u, f), d2 = dist(u, r);
		res += max(d1, d2);
		debug("soma %d %d\n", d1, d2);
		if(d1 > d2)
			ans.pb(pii(u, f));
		else
			ans.pb(pii(u, r));
		for(int nxt: adj[u]){
			deg[nxt]--;
			if(nxt != f && nxt != r && deg[nxt] == 1)
				q.push(nxt);
		}
	}
	while(f != r){
		debug("r %d f %d\n", r, f);
		res += dist(f, r);
		ans.pb(pii(f, r));
		f = pai[f][0];
	}
	printf("%lld\n", res);
	for(pii x: ans){
		printf("%d %d %d\n", x.fst, x.snd, x.fst);
	}
}

