#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 160000;
const int LOGN = 18;

vector<int> adj[MAXN];
bool mrk[MAXN];
bool s[MAXN];
int h[MAXN];
int S[MAXN];
int deg;
vector<int> id, mn;
int cnt[MAXN];
int pai[MAXN][LOGN];

void dfs(int u, int p){
    mrk[u] = true;
    id[u] = mn[u] = deg++;
    int nc = 0;
    for(int nxt: adj[u]){
        if(mrk[nxt] && nxt != p)
            mn[u] = min(mn[u], id[nxt]);
        else if(!mrk[nxt]){
            dfs(nxt, u);
            nc++;
            mn[u] = min(mn[u], mn[nxt]);
            if(mn[nxt] >= id[u] && u != p){
                s[u] = 1;
            }
        }
    }
    if(u == p && nc > 1)
        s[u] = 1;
    if(s[u])
        debug("PA %d\n", u+1);
}

int lca(int u, int v){
    if(h[u] < h[v])
        swap(u, v);
    if(h[u] > h[v]){
        for(int i=LOGN-1;i>=0;i--){
            if(h[pai[u][i]] > h[v])
                u = pai[u][i];
        }
        u = pai[u][0];
    }

    if(u != v){
        for(int i=LOGN-1;i>=0;i--){
            if(pai[u][i] != pai[v][i]){
                u = pai[u][i];
                v = pai[v][i];
            }
        }

        u = pai[u][0];
    }
    return u;
}

int on;

vector<int> P,sz;

int find(int u){
    if(P[u] == u) return u;
    return P[u] = find(P[u]);
}

inline void join(int u, int v){
    u = find(u);
    v = find(v);
    if(sz[u] < sz[v]) swap(u, v);
    if(u == v) return ;
    P[v] = u;
    sz[u] += sz[v];

}

void go(int u, int p){
    pai[u][0] = p;
    for(int i=1;i<LOGN;i++)
        pai[u][i] = pai[pai[u][i-1]][i-1];
    h[u] = h[p] + 1;
    mrk[u] = true;
    S[u] = S[p] + s[u];
    for(int nxt: adj[u]){
        if(max(u, nxt) < on && (s[u] == 0 || s[nxt] == 0)) continue;
        if(find(u) == find(nxt) && s[u] == 1 && s[nxt] == 1) continue;
        if(mrk[nxt]) continue;
        debug("u %d nxt %d\n", u+1, nxt+1);
        go(nxt, u);
    }
}

int n, m, k;

int color[MAXN];

inline void add(int u, int c){
    adj[u].pb(c);
    adj[c].pb(u);
    join(u, c);
}

void paint(int u, int c){
    color[u] = c;
    add(u, c);
    if(s[u] == 1)
        return ;
    for(int nxt: adj[u]){
        if(color[nxt] == 0 || (s[nxt] == 1 && (adj[nxt].back() != c))) {
            paint(nxt, c); 
        }
    }
}

int main (){
    deg = 0;
    scanf("%d%d", &n, &m);
    id.resize(n);
    mn.resize(n);
    on = n;
    for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        i--;j--;
        adj[i].pb(j);
        adj[j].pb(i);
    }
    vector<int> roots;
    for(int u=0;u<n;u++){
        if(!mrk[u]){
            roots.pb(u);
            dfs(u, u);
        }
    }
    mn.clear();
    id.clear();
    P = vector<int>(2*n,0);
    sz = vector<int>(2*n,0);

    for(int a=0;a<2*n;a++){
        P[a] = a;
        sz[a] = 1;
    }
    for(int u=0;u<on;u++){
        if(color[u] == 0 && s[u] == 0){
            paint(u, n);
            n++;
        }
    }
    for(int a=0;a<=n;a++)
        mrk[a] = false;
    for(int u: roots){
        go(u, u);
    }
    int q;
    scanf("%d", &q);
    for(int a=0;a<q;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        i--;j--;
        debug("lca %d\n", lca(i, j));
        printf("%d\n", 2 - s[i] - s[j] + S[i] + S[j] - 2*S[lca(i, j)] + s[lca(i, j)]);
    }
    return 0;
}

