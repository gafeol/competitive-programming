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

const int MAXN = 212345;

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
		debug("u %d nc %d\n", u, nc);
		cy[u] = nc++;
		while(q.top() != u){
			cy[q.top()] = cy[u];
			debug("	q.top() %d\n", q.top());
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


vector<int> adjc[MAXN];
int deg[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	reset();
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		i--;j--;
		adj[i].pb(j);
	}
	scc();

	queue<int> qu;
	for(int a=0;a<n;a++){
		debug("a %d cy %d\n", a, cy[a]);
		for(int nxt:adj[a]){
			if(cy[a] != cy[nxt]){
				adjc[cy[a]].pb(cy[nxt]);
				deg[cy[a]]++;
			}
		}
	}
	int res = -1;
	for(int a=0;a<nc;a++){
		if(deg[a] == 0){
			if(res != -1){
				puts("0");
				return 0;
			}
			else
				res = a;
		}
	}
	vector<int> ans;
	for(int a=0;a<n;a++){
		if(cy[a] == res)
			ans.pb(a);
	}
	printf("%d\n", (int)ans.size());
	for(int u: ans){
		printf("%d ", u+1);
	}
	puts("");
}

