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
int sz[MAXN], pai[MAXN];

vector<int> adj[MAXN];

int raiz(int i){
	if(pai[i] == i) return i;
	return pai[i] = raiz(pai[i]);
}

void join(int i, int j){
	i = raiz(i);
	j = raiz(j);
	if(i == j) return;
	if(sz[i] < sz[j])
		swap(i, j);
	sz[i] += sz[j];
	pai[j] = i;
}

int cnt[3];
int mrk[MAXN];

pii ar[MAXN];

map<pii, int> lig;

int tempo, dist[MAXN][2];

int mxd, umx;

void dfs(int u, int d, int i){
	if(mxd < d){
		umx = u;
		mxd = d;
	}
	dist[u][i] = d;
	debug("dist[%d][%d] = %d\n", u, i, d);
	mrk[u] = tempo;
	for(int nxt:adj[u]){
		if(mrk[nxt] < tempo)
			dfs(nxt, d+1, i);
	}
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		sz[a] = 1;
		pai[a] = a;
		scanf("%d", &s[a]);
	}
	for(int a=0;a<n-1;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		ar[a].fst = i;
		ar[a].snd = j;
		if(s[i] == s[j])
			join(i, j);	
	}
	for(int a=0;a<n-1;a++){
		int ir = raiz(ar[a].fst);
		int jr = raiz(ar[a].snd);
		if(s[ir] == s[jr]) continue;
		if(lig.find(pii(ir, jr)) == lig.end()){
			adj[ir].pb(jr);
			adj[jr].pb(ir);
			lig[pii(ir, jr)] = 1;
			lig[pii(jr, ir)] = 1;
		}
	}
	mxd = -1;
	tempo = 1;
	dfs(raiz(1), 0, 0);
	tempo++;
	mxd = -1;
	debug("umx %d\n", umx);
	dfs(umx, 0, 0);
	tempo++;
	debug("umx %d\n", umx); 
	dfs(umx, 0, 1);
	int res = INT_MAX;
	for(int a=1;a<=n;a++){
		int r = raiz(a);
		res = min(res, max(dist[r][0], dist[r][1]));
	}
	printf("%d", res);
}
