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

const int MAXN = 3123;

int n, m, k;
int s[MAXN], mrk[MAXN], D[MAXN][MAXN][2];

pii dist[MAXN][4][2];

vector<int> adj[MAXN][2];

void add(int u, int d, int s, int c){
	int i = 0;
	if(dist[c][i][s].snd < d){
		swap(dist[c][1][s], dist[c][2][s]);
		swap(dist[c][0][s], dist[c][1][s]);
		dist[c][i][s] = pii(u, d);
		return;
	}
	i = 1;
	if(dist[c][i][s].snd < d){
		swap(dist[c][1][s], dist[c][2][s]);
		dist[c][i][s] = pii(u, d);
		return;
	}
	i = 2;
	if(dist[c][i][s].snd < d){
		dist[c][i][s] = pii(u, d);
		return;
	}
}

queue<int> q;

void go(int u, int s){
	q.push(u);
	mrk[u] = u;
	D[u][u][s]= 0;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		debug("for %d\n", v);
		for(int nxt: adj[v][s]){
			if(mrk[nxt] == u) continue;
			if(u == 1)
				debug("UM %d->%d\n", v,nxt);
			mrk[nxt] = u;
			D[u][nxt][s] = D[u][v][s]+1;
			add(nxt, D[u][nxt][s], s, u);
			q.push(nxt);
		}
	}
}

void zera(){
	for(int a=0;a<=n;a++){
		mrk[a] = 0;
	}
}

set<int> seti;
pair<pii, pii> ans;
int res;

void test(int a, int b, int c, int d){

	if(a == c || b == d || a == d || a == b || c == d || D[a][b][0] == -1 || D[b][c][0] == -1 || D[c][d][0] == -1) return;
	int dis = D[a][b][0] + D[b][c][0] + D[c][d][0];
	if(res < dis){
		res = dis;
		ans = make_pair(pii(a, b), pii(c, d));
	}
	
}

int main (){
	memset(D, -1, sizeof(D));
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i][0].pb(j);
		adj[j][1].pb(i);
	}
	for(int a=1;a<=n;a++){
		debug("go %d 0\n", a);
		go(a, 0);
		zera();
		debug("go %d 1\n", a);
		go(a, 1);
		zera();
	}
	for(int u=1;u<=n;u++){
		debug("vertice %d\n", u);
		for(int i=0;i<2;i++){
			debug("	sentido %d\n", i);
			for(int v=1;v<=n;v++){
				debug("%d ", D[u][v][i]);
			}
			debug("\n");
			debug("melhores:\n");
			for(int sen=0;sen<2;sen++){
				debug("sentido %d\n", sen);
				for(int i=0;i<3;i++){

					debug("(%d %d) ", dist[u][i][sen].fst, dist[u][i][sen].snd);
				}
				debug("\n");
			}
			debug("\n");
		}

	}
	for(int a=1;a<=n;a++){
		for(int b=1;b<=n;b++){
			if(b == a || D[a][b][0] == -1) continue;
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					test(dist[a][i][1].fst, a, b, dist[b][j][0].fst);
				}
			}
		}
	}
	debug("res %d\n", res);
	printf("%d %d %d %d\n", ans.fst.fst, ans.fst.snd, ans.snd.fst, ans.snd.snd);
}
