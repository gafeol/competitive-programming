//                       to prev centroid
int sz[MAXN], mrk[MAXN], link[MAXN];
vector<int> adj[MAXN];

int getsz(int u, int p){
    sz[u] = 1;
    for(int nxt: adj[u]){
        if(mrk[nxt] || nxt == p) continue;
        sz[u] += getsz(nxt, u);
    }
    return sz[u];
} 

int getc(int u, int p, int tot){
    for(int nxt: adj[u]){
        if(mrk[nxt] || nxt == p) continue;
        if(sz[nxt] > tot/2){
            return getc(nxt, u, tot);
        } 
    }
    return u;
}

int decomp(int u, int prvc=-1){
    getsz(u, u);
    int c;
    c = getc(u,u,sz[u]);
    link[c] = prvc;
    mrk[c] = true;
    for(int nxt: adj[c]){
        if(mrk[nxt]) continue;
        int nxtc = decomp(nxt, c);
    }
    return c;
}

void reset(int n) {
    for(int a=0;a<=n;a++){
        adj[a].clear();
        mrk[a] = false;
    }
}
