#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 100005;

vector<int> adj[N];
int t, n, m, q[N];
bool dead[N];

void dfs(int u, int d, int p) {
	q[u] = d;
	for(int v : adj[u])
		if(v != p)
			dfs(v, d + dead[u], u);
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) { 
			adj[i].clear();
			dead[i] = false;
			q[i] = 0;
		}
		for(int i = 0; i < n-1; i++) {
			int u, v;
			scanf("%d %d", &u, &v); u--; v--;
			adj[u].pb(v);
			adj[v].pb(u);
		} 	
		scanf("%d", &m);
		for(int i = 0; i < m; i++) {
			int u;
			scanf("%d", &u); u--;
			dead[u] = true;
		}
		dfs(0, 0, -1);
		double ans = 0;
		for(int i = 0; i < n; i++) {
			double k = q[i];		
			ans += k / (k + 1.);
		}
		printf("%.20lf\n", ans);
	}
}
