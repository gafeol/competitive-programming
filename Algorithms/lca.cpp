int n, m;
vector<int> adj[MAXN];
int h[MAXN], p[MAXN][LOGN];
void dfs(int u, int pai){
    h[u] = h[pai] + 1;
    p[u][0] = pai;
    for(int i=1;i<LOGN;i++)
        p[u][i] = p[p[u][i-1]][i-1];
    for(int nxt: adj[u])
        if(nxt != pai)
            dfs(nxt, u);
}

void init(int r = 1) {
    h[r] = -1;
    dfs(r, r);
}

int lca(int u, int v){
    if(h[u] != h[v]){
        if(h[u] < h[v]) swap(u, v);
        for(int i=LOGN-1;i>=0;i--)
            if(h[p[u][i]] > h[v]) 
                u = p[u][i];
        u = p[u][0];
    }
    if(u == v) return u;
    for(int i=LOGN-1;i>=0;i--){
        if(p[u][i] != p[v][i]){
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}

int dis(int u, int v){ return h[u] + h[v] - 2*h[lca(u, v)]; }
