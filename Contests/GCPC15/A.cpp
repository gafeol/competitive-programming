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

const int MAXN = 21234, INF = 0x3f3f3f3f;

int n, m, k, tx, T;

int w;
int ds[17][17];

int id[MAXN];

int dist[17][(1<<17)][2];

int sp[MAXN];

vector<pii> adj[MAXN];
set<pii> q;

int d[MAXN][17];

void relax(int t, int u, int v, int c){
	if(d[v][t] > d[u][t] + c){
		if(d[v][t] != INF)
			q.erase(pii(d[v][t], v));
		d[v][t] = d[u][t] + c;
		q.insert(pii(d[v][t],v));
	}
}

void dij(int t){
	int st = id[t];
	d[st][t] = 0;
	q.clear();
	q.insert(pii(0, st));
	while(!q.empty()){
		int u = q.begin()->snd;
		q.erase(q.begin());
		for(pii ar: adj[u]){
			int nxt = ar.fst;
			int c = ar.snd;
			relax(t, u, nxt, c);
		}
	}
}


set<tuple<int, int, int, int> > sq;

void relax2(int u, int bm, int t, int v, int nbm, int c){
	if(dist[v][nbm][t] > dist[u][bm][t] + c){
		if(dist[v][nbm][t] != INF)
			sq.erase({dist[v][nbm][t], v, nbm, t});
		dist[v][nbm][t] = dist[u][bm][t] + c;
		sq.insert({dist[v][nbm][t], v, nbm, t});
	}
	
	if(t) return;
	c = tx;
	if(dist[v][nbm][1] > dist[u][bm][t] + c){
		if(dist[v][nbm][1] != INF)
			sq.erase({dist[v][nbm][1], v, nbm, 1});
		dist[v][nbm][1] = dist[u][bm][t] + c;
		sq.insert({dist[v][nbm][1], v, nbm, 1});
	}
}

void dij2(int st, int bm){
	dist[st][bm][0] = 0;
	sq.clear();
	sq.insert({0, st, bm, 0});
	while(!sq.empty()){
		int u, t;
		tie(ignore, u, bm, t) = *sq.begin();	
		sq.erase(sq.begin());
		for(int v=0;v<=k;v++){
			int nbm = bm|(1<<v);
			relax2(u, bm, t, v, nbm, ds[u][v]);
		}
	}
}

int main (){
	scanf("%d %d %d %d %d", &n, &k, &m, &T, &tx);
	memset(sp, -1, sizeof(sp));
	memset(d, INF, sizeof(d));
	memset(dist, INF, sizeof(dist));
	sp[0] = 0;
	for(int a=1;a<=k;a++){
		int tem;
		scanf("%d %d", &id[a], &tem); 
		sp[id[a]] = a;
		w += tem;
	}
	T -= w;
	for(int a=0;a<m;a++){
		int i, j, c;
		scanf("%d %d %d", &i, &j, &c);
		adj[i].pb(pii(j, c));
		adj[j].pb(pii(i, c));
	}
	for(int a=0;a<=k;a++){
		dij(a);
		for(int b=a+1;b<=k;b++){
			ds[b][a] = ds[a][b] = d[id[b]][a];
			debug("de %d %d - %d\n", a, b, ds[a][b]);
		}
	}
	dij2(0, 1);	
	if(dist[0][(1<<(k+1))-1][0] <= T)
		puts("possible without taxi");
	else if(dist[0][(1<<(k+1))-1][1] <= T)
		puts("possible with taxi");
	else
		puts("impossible");
}
