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
