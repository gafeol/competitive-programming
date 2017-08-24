#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 50004;
vector<int> adj[N];
int n, q, c[N], lv[N], imp[N], par[N], pre[N], pos[N], t, pai[N];

void dfs(int u, int p, int l) {
	lv[u] = l;
	imp[u] = c[u];
	pre[u] = t++;
	for(int v : adj[u]) {
		if(v == p) continue;
		dfs(v, u, l+1);
		par[u] ^= imp[v];
		imp[u] ^= par[v];
	}
	pos[u] = t++;
}

int win(int u, int v) {
	int nlv = lv[v] + 1;	
	if(nlv%2 != lv[u]%2) return par[0] ^ par[u] ^ imp[u];
	return par[0];
}

bool invalid(int u, int v) {
	return pre[u] < pre[v] && pos[u] > pos[v];	
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", c+i);
	for(int i = 0; i < n-1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);	a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0, -1, 1);
	scanf("%d", &q);
	while(q--) {
		int u, v;
		scanf("%d %d", &u, &v);	u--; v--;
		if(invalid(u, v)) puts("INVALID");
		else {
			if(win(u, v)) puts("YES");
			else puts("NO");
		}
	}
}
