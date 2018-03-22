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

const int MAXN = 212345, INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];

int sp[MAXN][3];
int d[MAXN][3], dist[MAXN];

int ini[3];
int res;

queue<int> q;

vector<int> adj[MAXN], inv[MAXN];

void bfsi(int u, int t){
	for(int a=0;a<n+3;a++){
		d[a][t] = INF;
	}
	d[u][t] = -1;
	q.push(u);
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(int nxt: inv[u]){
			if(d[nxt][t] == INF){
				d[nxt][t] = d[u][t] + 1;
				q.push(nxt);
			}
		}
	}
}

void bfs(int u){
	for(int a=0;a<=n+2;a++){
		dist[a] = INF;
	}
	dist[u] = 0;
	q.push(u);
	while(!q.empty()){
		u = q.front();
		q.pop();
		res = min(res, dist[u] + d[u][0] + d[u][1]);
		for(int nxt: adj[u]){
			if(dist[nxt] == INF){
				dist[nxt] = dist[u] + 1;
				q.push(nxt);
			}
		}
	}
}

int main (){
	res = INF;
	scanf("%d%d%d", &n, &m, &k);
	int u;
	ini[0] = n+1;
	ini[1] = n+2;
	for(int a=0;a<m;a++){
		scanf("%d", &u);
		sp[u][0] = 1;
		inv[ini[0]].pb(u);
	}
	for(int a=0;a<k;a++){
		scanf("%d", &u);
		sp[u][1] = 1;
		inv[ini[1]].pb(u);
	}
	for(int a=1;a<=n;a++){
		int cnt
		scanf("%d", &cnt); 
		while(cnt--){
			scanf("%d", &u);
			adj[a].pb(u);
			inv[u].pb(a);
		}
	}
	bfsi(ini[0], 0);
	bfsi(ini[1], 1);
	bfs(1);
	if(res == INF)
		puts("impossible");
	else
		printf("%d\n", res);
}

