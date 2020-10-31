#include "bits/stdc++.h"
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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 512345;

int n, m, k;

vector<tuple<int, int, int>> adj[MAXN];


int id[2][MAXN];
int v[2][MAXN];
int s[2][MAXN];
int h[2][MAXN];
int in[2][MAXN], out[2][MAXN];

int mxd, mx;

void dfs(int u, int p, int d){
    if(d > mxd){
        mxd = d;
        mx = u;
    }
    for(auto [nxt, t, id]: adj[u]){
        if(nxt == p) continue; 
        dfs(nxt, u, d+1);
    }
}

int deg;

void go(int r, int u, int p){
    id[r][deg] = u;
    in[r][u] = deg++;
    for(auto [nxt, t, id]: adj[u]){
        if(nxt == p) continue;
        v[r][id] = nxt;
        s[r][nxt] = s[r][u]^t;
        h[r][nxt] = h[r][u] + 1;
        go(r, nxt, u);
    }
    out[r][u] = deg-1;
    debug("em r %d u %d in %d  out %d s %d h %d\n", r, u, in[r][u], out[r][u], s[r][u], h[r][u]);
}

struct arv{
    int h[2];
    int lz;
} tree[2][MAXN*4];

void build(int t, int idx, int i, int j){
    arv &r = tree[t][idx];
    r.lz = 0;
    if(i == j){
        r.h[0] = r.h[1] = -1;
        int u = id[t][i];
        r.h[s[t][u]] = h[t][u];
        return ;
    }
    int m = (i + j)/2;
    build(t, idx*2, i, m);
    build(t, idx*2+1, m+1, j);

    for(int a=0;a<2;a++)
        r.h[a] = max(tree[t][idx*2].h[a], tree[t][idx*2+1].h[a]);
}

void unlaze(int t, int idx, int i, int j){
    if(tree[t][idx].lz){
        tree[t][idx].lz = 0;
        if(i != j){
            swap(tree[t][idx*2].h[0], tree[t][idx*2].h[1]);
            tree[t][idx*2].lz ^= 1;
            swap(tree[t][idx*2+1].h[0], tree[t][idx*2+1].h[1]);
            tree[t][idx*2+1].lz ^= 1;
        }
    }
}

void upd(int t, int idx, int i, int j, int l, int r){
    if(i > r || j < l) return ; 
    unlaze(t, idx, i, j);
    if(i >= l && j <= r){
        debug("t %d idx %d i %d j %d l %d r %d\n", t, idx, i, j, l, r);
        swap(tree[t][idx].h[0], tree[t][idx].h[1]);
        tree[t][idx].lz ^= 1;
        debug("tree %d %d %d\n", tree[t][idx].h[0], tree[t][idx].h[1], tree[t][idx].lz);
        return ;
    }
    int m = (i + j)/2;
    upd(t, idx*2, i, m, l, r);
    upd(t, idx*2+1, m+1, j, l, r);

    for(int a=0;a<2;a++)
        tree[t][idx].h[a] = max(tree[t][idx*2].h[a], tree[t][idx*2+1].h[a]);
    debug("atu t %d id %d i %d j %d l %d r %d\n", t, idx, i, j, l, r);
    debug("%d %d\n", tree[t][idx].h[0], tree[t][idx].h[1]);
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<n;a++){
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        u--;v--;
        adj[u].pb({v, t, a});
        adj[v].pb({u, t, a});
	}

    mxd = -1;
    dfs(0, 0, 0);
    mxd = -1;
    int R1 = mx;
    dfs(mx, mx, 0);
    int R2 = mx;

    deg = 0;
    go(0, R1, R1);
    build(0, 1, 0, deg-1);

    deg = 0;
    go(1, R2, R2);

    debug("diam %d %d\n", R1, R2);
    build(1, 1, 0, deg-1);
    debug("%d %d %d %d\n", tree[0][1].h[0], tree[0][1].h[1], tree[1][1].h[0], tree[1][1].h[1]);
    scanf("%d", &m);
    while(m--){
        int x;
        scanf("%d", &x);
        int u;

        for(int a=0;a<2;a++){
            u = v[a][x];
            debug("em r %d upd tudo abaixo de %d\n", a, u);
            upd(a, 1, 0, deg-1, in[a][u], out[a][u]);
        }
        debug("====RES ");
        printf("%d\n", max(tree[0][1].h[0], tree[1][1].h[0]));
    }

    return 0;
}

