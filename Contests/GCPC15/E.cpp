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

int n, m, k;

int s[MAXN], d[MAXN][2];

vector<pii> adj[MAXN];

set<pii> q;

void relax(int t, int u, int v, int c){
	if(d[v][t] > d[u][t] + c){
		if(d[v][t] != INF)
			q.erase(pii(d[v][t], v));

		d[v][t] = d[u][t] + c;
		q.insert(pii(d[v][t], v));
	}
}

void dij(int t){
	int S;
	if(t == 0) S = 1;
	else S = n;
	d[S][t] = 0;
	q.insert(pii(0, S));
	while(!q.empty()){
		int u = q.begin()->snd;
		q.erase(q.begin());
		for(pii ar: adj[u]){
			int nxt = ar.fst;
			relax(t, u, nxt, ar.snd);
		}
	}
}

int main (){
	memset(d, INF, sizeof(d));
	scanf("%d%d%d", &n, &m, &k);
	for(int a=0;a<k;a++){
		scanf("%d", s+a);
	}
	for(int a=0;a<m;a++){
		int i, j, c;
		scanf("%d %d %d", &i, &j, &c);
		adj[i].pb(pii(j, c));
		adj[j].pb(pii(i, c));
	}
	dij(0);
	dij(1);
	for(int i=0;i<k-1;i++){
		int u = s[i];
		int proi = -1;
		for(int j=0;j<adj[u].size();j++){
			pii ar = adj[u][j];
			int v = ar.fst;
			int c = ar.snd;
			if(v == s[i+1] && d[u][0] + c + d[v][1] == d[n][0]){
				proi = j;			
			}
		}
		for(int j=0;j<adj[u].size();j++){
			if(j == proi) continue;
			int v = adj[u][j].fst;
			int c = adj[u][j].snd;
			if(d[u][0] + c + d[v][1] == d[n][0]){
				puts("yes");
				return 0;
			}
		}
	}
	puts("no");
}
