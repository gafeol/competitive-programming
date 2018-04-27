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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 4*212345;

int n, m, k;
int s[MAXN];

int nc, visc;
int cy[MAXN], vis[MAXN], mn[MAXN], idd[MAXN], rep[MAXN];
vector<int> adj[MAXN];
stack<int> q;


vector<int> adjc[MAXN], c[MAXN];

int res[MAXN];

void reset(int nn=n){
	while(!q.empty()) q.pop();
	nc = visc = 0;
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
	return u*2 + t;
}

void add_edge(int u, int v){
	debug("add %d%c -> %d%c\n", (u/2), ((u%2) == 0 ? 'h' : 'w'), v/2, ((v%2)==0 ? 'h' : 'w'));
	adj[u].pb(v);
}

void seta(int u, int t){
	add_edge(id(u, 1-t), id(u, t));
}

//NAO DEU MAXN
int main (){
	while(scanf("%d%d", &n, &m) != EOF && n+m != 0){
		reset(n);
		for(int a=0;a<m;a++){
			int i, j;
			char ci, cj;
			scanf(" %d%c %d%c", &i, &ci, &j, &cj);
			int ti = (ci == 'w');
			int tj = (cj == 'w');
			add_edge(id(i, 1-ti), id(j, tj)); 
			add_edge(id(j, 1-tj), id(i, ti)); 
		}
		add_edge(id(0, 0), id(0, 1));
		for(int a=0;a<2*n;a++)
			if(!vis[a])
				tarjan(a);
		int ok = 1;
		for(int a=0;a<n;a++){
			if(cy[id(a, 0)] == cy[id(a, 1)]){
				puts("bad luck");
				ok = 0;
				break;
			}
		}
		if(!ok) continue;
		debug("OK\n");
		// tarjan deixa as componentes na ordem topologica reversa
		for(int a=0;a<nc;a++){
			if(res[a] == -1){
				res[a] = 1;
				int b = cy[rep[a]^1];
				res[b] = 0;
			}
		}
		int pt = 0;
		for(int a=2;a<2*n;a++){
			//printf("%d%c cy %d res %d\n", a/2, ((a&1)==0 ? 'h' : 'w'), cy[a], res[cy[a]]);
			if(res[cy[a]] == res[cy[1]]){
				if(pt) putchar(' ');
				pt = 1;
				printf("%d%c", a/2, ((a&1)==0 ? 'h' : 'w'));
			}
		}
		puts("");
	}
}
