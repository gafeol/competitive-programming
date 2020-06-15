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

int nc, visc;
int cy[MAXN], vis[MAXN], mn[MAXN], idd[MAXN], rep[MAXN];
vector<int> adj[MAXN];
stack<int> q;


vector<int> adjc[MAXN], c[MAXN];

int res[MAXN];

void reset(int nn=n){
	while(!q.empty()) q.pop();
	nc = visc = 0;
	/* atencao para zerar o valor de TODAS variaveis */
	for(int a=0;a<=2*n;a++){
		adj[a].clear();
		cy[a] = -1;
		vis[a] = 0;
		res[a] = -1;
	}
}


int tarjan(int u){
	q.push(u);
	vis[u] = 1;
	idd[u] = visc++;
	mn[u] = idd[u];
	for(int nxt: adj[u]){
		if(!vis[nxt])
			mn[u] = min(mn[u], tarjan(nxt));
		else if(cy[nxt] == cy[u])
			mn[u] = min(mn[u], idd[nxt]);
	}
	if(mn[u] == idd[u]){
		rep[nc] = u;
		cy[u] = nc++;
		while(q.top() != u){
			cy[q.top()] = cy[u];
			q.pop();
		}
		q.pop();
	}
	return mn[u];
}

int id(int u, int t){
	return u* 2 + t;
}

void add_edge(int u, int v){
	adj[u].pb(v);
}

void seta(int u, int t){
	add_edge(id(u, 1-t), id(u, t));
}

//NAO DEU MAXN
int main (){
	reset(n);

	// add edges

	for(int a=0;a<2*n;a++)
		if(!vis[a])
			tarjan(a);
	for(int a=0;a<n;a++){
		if(cy[id(a, 0)] == cy[id(a, 1)]){
			puts("Deu ruim");
			return 0;
		}
	}
	// tarjan deixa as componentes na ordem topologica reversa
	for(int a=0;a<nc;a++){
		if(res[a] == -1){
			res[a] = 1;
			int b = cy[rep[a]^1];
			res[b] = 0;
		}
	}
	for(int a=0;a<2*n;a++)
		printf("res[%d] %d\n", a, res[a]);
	puts("");
}

int n, m, k;
int s[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
	}
}

