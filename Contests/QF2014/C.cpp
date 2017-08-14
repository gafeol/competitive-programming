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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

vector<int> adj[MAXN];
int imx, mx;

void go(int u, int p, int d){
	if(d > mx){
		mx = d;
		imx = u;
	}
	for(int nxt: adj[u]){
		if(nxt == p) continue;
		go(nxt, u, d+1);
	}
}

int dist[MAXN];

void dfs(int u, int p, int d){
	dist[u] = max(d, dist[u]);
	for(int nxt: adj[u]){
		if(nxt == p) continue;
		dfs(nxt, u, d+1);
	}
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n-1;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	go(1, 1, 0);
	int u = imx;
	mx = -1;
	go(u, u, 0);
	int v = imx;
	mx = -1;

	dfs(u, u, 0);
	dfs(v, v, 0);
	for(int a=1;a<=n;a++){
		printf("%d ", dist[a]);
	}
}
