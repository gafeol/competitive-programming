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

const int MAXN = 4*212345;

int n, m, k;
int s[MAXN];

int nc, visc;
int cy[MAXN], vis[MAXN], mn[MAXN], id[MAXN];
vector<int> adj[MAXN];
stack<int> q;

void reset(int nn=n){
	while(!q.empty()) q.pop();
	nc = visc = 0;
	for(int a=0;a<=n;a++){
		adj[a].clear();
		cy[a] = -1;
		vis[a] = 0;
	}
}


int tarjan(int u){
	q.push(u);
	vis[u] = 1;
	id[u] = visc++;
	mn[u] = id[u];
	for(int nxt: adj[u]){
		if(!vis[nxt])
			mn[u] = min(mn[u], tarjan(nxt));
		else if(cy[nxt] == cy[u])
			mn[u] = min(mn[u], id[nxt]);
	}
	if(mn[u] == id[u]){
		cy[u] = nc++;
		while(q.top() != u){
			cy[q.top()] = cy[u];
			q.pop();
		}
		q.pop();
	}
	return mn[u];
}

void scc(){
	// nodes 0..n-1
	for(int a=0;a<n;a++)
		if(!vis[a])
			tarjan(a);
}

//NAO DEU MAXN
int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		int ii, i, jj, j;
		char ci, cj;
		scanf("%d%c %d%c", &ii, &ci, &jj, &cj);
		i = ii*2 + (ci == 'w');
		j = jj*2 + (cj == 'w');
	}
}

