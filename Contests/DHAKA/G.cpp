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
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 51234;
const int MAXQ = 112345;
const int LOGN = 21;

int n, m;
vector<int> adj[MAXN];

int sz[MAXN], mrk[MAXN];
int link[MAXN];

struct arv{
    int mn;
    arv *L, *R;
    arv() : mn(INT_MAX), L(NULL), R(NULL) {}
    arv(int x) : mn(x), L(NULL), R(NULL) {}
    arv(int x, arv *l, arv *r): mn(x), L(l), R(r) {}
    arv* left() {
        if(L == NULL){
            L = new arv();
        }
        return L;
    }
    arv* right() {
        if(R == NULL)
            R = new arv();
        return R;
    }
};

int val(arv* u){
    if(u == NULL)
        return INT_MAX;
    return u->mn;
}

vector<arv*> root;

void upd(arv* u, int i, int j, int l, int x){
    if(i == j){
        u->mn = x;
        return ;
    }
    int m = (i+j)/2;
    if(l <= m)
        upd(u->left(), i, m, l, x);
    else
        upd(u->right(), m+1, j, l, x);
    u->mn = min(val(u->L), val(u->R));
}

int qry(arv *u, int i, int j, int l, int r){
    if(u == NULL || l > j || r < i) 
        return INT_MAX;
    if(i >= l && j <= r)
        return u->mn; 
    int m = (i + j)/2;
    return min(qry(u->L, i, m, l, r),
                qry(u->R, m+1, j, l, r));
}

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

void add(int u, int p, int c, int d=0){
    upd(root[c], 1, n, u, d);             
    for(int nxt: adj[u]){
        if(nxt == p || mrk[nxt]) continue;
        add(nxt, u, c, d+1);
    }
}



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

// LCA {
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

// }


void decomp(int u, int prvc=-1){
    getsz(u, u);
    int c;
    c = getc(u,u,sz[u]);
    link[c] = prvc;
    add(c, c, c);
    mrk[c] = true;
    for(int nxt: adj[c]){
        if(mrk[nxt]) continue;
        decomp(nxt, c);
    }
}

vector<int> q;
pii cp[MAXQ];

int qryup(int u, int ini){
    if(u == -1)
        return INT_MAX;
    int mn = INT_MAX;
    for(int x: q)
        mn = min(mn, qry(root[u], 1, n, cp[x].fst, cp[x].snd));
    if(mn < INT_MAX)
        mn += dis(ini, u);
    int ans = qryup(link[u], ini);
    return min(mn, ans);
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        root.clear();
        root.resize(n+1);
        for(int a=1;a<=n;a++){
            root[a] = new arv();
            adj[a].clear();
            mrk[a] = false;
        }
        for(int a=1;a<n;a++){
            int i, j;
            scanf("%d%d", &i, &j);
            adj[i].pb(j);
            adj[j].pb(i);
        }

        init();
        decomp(1);

        vector<int> cmps;
        scanf("%d", &m);
        printf("Case %d:\n", tt);
        for(int a=0;a<m;a++){
            int t;
            scanf("%d", &t); 
            //debug("le qry %d\n", t);
            if(t == 1){
                int x, l, r;
                scanf("%d%d%d", &x, &l, &r);
                cp[x] = {l, r};
                cmps.pb(x);
            }
            else if(t == 2){
                int x;
                scanf("%d", &x);
                cp[x] = {0, 0};
            }
            else{
                int u, k;
                scanf("%d%d", &u, &k);
                q.clear();
                for(int a=0;a<k;a++){
                    int id;
                    scanf("%d", &id);
                    if(cp[id].fst != 0)
                        q.pb(id);
                }
                //debug("chama qryup %d\n", u);
                int ans = qryup(u, u);
                printf("%d\n", (ans == INT_MAX ? -1 : ans));
            }
        }

        for(int x: cmps)
            cp[x] = {0, 0};
        cmps.clear();
    }
}

