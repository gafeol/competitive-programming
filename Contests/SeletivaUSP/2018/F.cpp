#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
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

const int MAXN = 212345, LOGN = 20;

int n, m, k;
int s[MAXN];

int h[MAXN];
int deg;
int pai[MAXN][LOGN];

int to[MAXN];
int nx[MAXN];
int es[MAXN];
int ini;

void go(int u, int p){
	pai[u][0] = p;	
	h[u] = h[p] + 1;
	for(int i=1;i<LOGN;i++)
		pai[u][i] = pai[pai[u][i-1]][i-1];
	for(int ar = es[u];ar != -1;ar = nx[ar]){
		int nxt = to[ar];
		if(nxt == p) continue;
		go(nxt, u);
	}
}

int lca(int u, int v){
	if(h[u] < h[v]) swap(u, v);
	if(h[u] > h[v]){
		for(int i=LOGN-1;i>=0;i--){
			if(h[pai[u][i]] > h[v])
				u = pai[u][i];
		}
		u = pai[u][0];
	}
	if(u == v) return u;
	for(int i=LOGN-1;i>=0;i--){
		if(pai[u][i] == pai[v][i]) continue;
		u = pai[u][i];
		v = pai[v][i];
	}
	return pai[u][0];
}

ll res;

int dfs(int u, int p){
	int cnt = 0;
	for(int ar = es[u];ar != -1;ar = nx[ar]){
		int nxt = to[ar];
		if(nxt == p) continue;
		cnt += dfs(nxt, u);
	}
	cnt += s[u];
	s[u] = cnt;
	if(u == p) return 0;
	if(s[u] == 0)
		res += (ll)m;
	else if(s[u] == 1)
		res++;
	return cnt;
}

void add_edge(int i, int j){
	to[deg] = j;
	nx[deg] = es[i];
	es[i] = deg++;
}

int main (){
	res = 0;
	deg = 0;
	scanf("%d %d", &n, &m);
	memset(es, -1, sizeof(es));
	ini = -1;
	for(int a=1;a<n;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		if(ini == -1)
			ini = i;
		add_edge(i, j);
		add_edge(j, i);
	}
	go(ini, ini);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		int mi = lca(i, j);
		s[j]++;
		s[i]++;
		s[mi]-=2;
	}
	dfs(ini, ini);
	printf("%lld\n", res);
}

