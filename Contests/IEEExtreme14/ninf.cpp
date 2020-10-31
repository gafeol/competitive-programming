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

const int MAXN = 180000;
const int LOGN = 20;

int n;
vector<int> adj[MAXN];
int h[MAXN];
int S[MAXN];
int pai[MAXN][LOGN];

vector<int> roots;

vector<int> P,sz;

int find(int u){
    if(P[u] == u) return u;
    return P[u] = find(P[u]);
}

inline void join(int u, int v){
    assert(max(u, v) < 2*n);
    u = find(u);
    v = find(v);
    if(u == v) return ;
    if(sz[u] < sz[v]) swap(u, v);
    P[v] = u;
    sz[u] += sz[v];

}

inline void add(int u, int c){
    adj[u].pb(c);
    adj[c].pb(u);
    join(u, c);
}

//ELVASITO ----------------------
vector<int> g[MAXN];
struct edge {int u,v,comp;bool bridge;};
vector<edge> e;
void add_edge(int u, int v){
    g[u].pb(e.size());g[v].pb(e.size());
    e.pb((edge){u,v,-1,false});
}
int D[MAXN],B[MAXN],T;
int nbc;  // number of biconnected components
int s[MAXN];  // articulation point iff !=0
stack<int> st;  // only for biconnected

void dfs(int u,int pe){
    B[u]=D[u]=T++;
    for(int ne:g[u])if(ne!=pe){
        int v=e[ne].u^e[ne].v^u;
        if(D[v]<0){
            st.push(ne);dfs(v,ne);
            if(B[v]>D[u])e[ne].bridge = true; // bridge
            if(B[v]>=D[u]){
                s[u]++; 
                int last; // start biconnected
                do {
                    last=st.top();st.pop();
                    e[last].comp=nbc;
                    add(e[last].u, n + nbc);
                    add(e[last].v, n + nbc);
                } while(last!=ne);
                nbc++;    // end biconnected
            }
            B[u]=min(B[u],B[v]);
        }
        else if(D[v]<D[u])st.push(ne),B[u]=min(B[u],D[v]);
    }
}

void doit(){
    memset(D,-1,sizeof(D));memset(s,0,sizeof(s));
    nbc=T=0;
    for(int i=0;i<n;i++){
        if(D[i]<0){
            roots.pb(i);
            dfs(i,-1),
                s[i]--;
        }
    }
}
/// ELVASITO------------------------------

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
        assert(h[u] == h[v]);
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

bool mrk[MAXN];

void go(int u, int p){
    pai[u][0] = p;
    for(int i=1;i<LOGN;i++)
        pai[u][i] = pai[pai[u][i-1]][i-1];
    h[u] = h[p] + 1;
    mrk[u] = true;
    S[u] = S[p] + (s[u] != 0);
    for(int nxt: adj[u]){
        if(max(u, nxt) < on && (s[u] == 0 || s[nxt] == 0)) continue;
        if(find(u) == find(nxt) && s[u] != 0 && s[nxt] != 0) continue;
        if(mrk[nxt]) continue;
        debug("%d %d\n", u+1, nxt+1);
        go(nxt, u);
    }
}

int m, k;

int color[MAXN];
void paint(int u, int c){
    debug("paint u %d c %d\n", u+1, c);
    add(u, c);
    if(s[u] != 0)
        return ;
    color[u] = c;
    for(int nxt: adj[u]){
        if(nxt >= on) continue;
        if(color[nxt] == 0 || (s[nxt] != 0 && adj[nxt].back() != c)) {
            paint(nxt, c); 
        }
    }
}

int main (){
    scanf("%d%d", &n, &m);
    on = n;
    P = vector<int>(2*n,0);
    sz = vector<int>(2*n,1);
    for(int a=0;a<2*n;a++)
        P[a] = a;
    for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        i--;j--;
        adj[i].pb(j);
        adj[j].pb(i);
        add_edge(i, j);
    }
    doit();

    /*
    for(int u=0;u<on;u++){
        if(color[u] == 0 && s[u] == 0){
            paint(u, n);
            n++;
        }
    }
    */
    for(int u: roots){
        assert(S[u] == 0);
        go(u, u);
    }

    for(int a=0;a<n;a++){
        if(s[a] != 0)
            debug("u eh PA %d\n", a+1);
    }
    int q;
    scanf("%d", &q);
    for(int a=0;a<q;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        i--;j--;
        int lc = lca(i, j);
        debug("lca %d S[%d] %d S[%d] %d S[%d] %d\n", lc, i, S[i], j, S[j], lc, S[lc]);
        printf("%d\n", 2 - (s[i] != 0) - (s[j] != 0) + S[i] + S[j] - 2*S[lc] + (s[lc] != 0));
    }
    return 0;
}
