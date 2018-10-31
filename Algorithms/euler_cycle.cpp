// maximum node and edge constraints
const int MAXN = 212345;
const int MAXE = 2123456;

int s[MAXN];

// adjacency list
vector<pii> adj[MAXN];
int cnt;

int mrk[MAXE];

int temp_path[MAXE], final_path[MAXE], tsz, fsz;

void add_edge(int a, int b){
	// undirected edge
	adj[a].pb(pii(b, cnt));	
	adj[b].pb(pii(a, cnt++));
}

// Only use if graph is guaranteed to have an euler cycle
void euler_dfs(int u){
	temp_path[tsz++] = u;
	for(pii ar: adj[u]){
		int id = ar.snd;
		if(mrk[id]) continue;
		mrk[id] = 1;
		int v = ar.fst; euler_dfs(v);
	}
	final_path[fsz++] = temp_path[--tsz];
}
// Cycle stored in final_path[0...fsz-1]
