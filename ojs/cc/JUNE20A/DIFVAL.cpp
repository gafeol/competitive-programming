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

const int MAXN = 200009;
const int LOGN = 18;

int n, m, k;
int s[MAXN];
int p[MAXN][LOGN];
int id[MAXN], deg, mn[MAXN], mx[MAXN];
int vh[MAXN], degv;
int hh[MAXN];
int h[MAXN];


int nx[MAXN], to[MAXN], ar[MAXN], en;

struct arv{
    int som;
    int L, R;
} z, tree[MAXN*LOGN*8];
int degt;

inline void go(int u){
    for(int i=1;i<LOGN;i++)
        p[u][i] = p[p[u][i-1]][i-1];

    vh[degv] = u;
    hh[degv++] = h[u];
    mn[u] = deg;
    id[u] = deg++;
    while(ar[u] != -1){
        int nxt = to[ar[u]];
        h[nxt] = h[u] + 1;
        go(nxt);    
        ar[u] = nx[ar[u]];
    }
    mx[u] = deg-1;
}

inline int copia(arv a = z){
    tree[degt++] = a;
    return degt-1;
}

inline int qry(int idx, int i, int j, int l, int r){
    if(idx == 0 || i > r || j < l)
        return 0;
    if(i >= l && j <= r)
        return tree[idx].som;
    int m = ((i + j)>>1);
    return qry(tree[idx].L, i, m, l, r) + 
            qry(tree[idx].R, m+1, j, l, r);
    //printf("qry(%d %d %d %d %d): %d\n", idx, i, j, l, r, ans);
}

inline void upd(int idx, int i, int j, int l, int x){
    //debug("upd %d %d %d %d %d\n", idx, i, j, l, x);
    if(i == j){
        tree[idx].som += x;
        return ;
    }
    int m = ((i + j)>>1);
    if(l <= m){
        if(tree[idx].L == 0){
            //puts("eh -1");
            //printf("idx %d tree sz %d\n", idx, tree.size());
            int aux = copia();
            tree[idx].L = aux;
            //printf("depois de copiar idx %d L %d sz %d\n", idx, tree[idx].L, tree.size());
        }
        else{
            //puts("n eh -1");
            int aux = copia(tree[tree[idx].L]);
            tree[idx].L = aux;
        }

        //printf("tree[%d].L %d\n", idx, tree[idx].L);
        upd(tree[idx].L, i, m, l, x);
    }
    else{
        if(tree[idx].R == 0){
            int aux = copia();
            tree[idx].R = aux;
        }
        else{
            int aux = copia(tree[tree[idx].R]);
            tree[idx].R = aux;
        }
        upd(tree[idx].R, m+1, j, l, x);
    }
    tree[idx].som = 0;
    if(tree[idx].L)
        tree[idx].som += tree[tree[idx].L].som;
    if(tree[idx].R)
        tree[idx].som += tree[tree[idx].R].som;
}

inline int lca(int u, int v){
    int ou = u, ov = v;
    if(h[u] != h[v]){
        if(h[u] < h[v])
            swap(u, v);
        for(int i=LOGN-1;i>=0;i--){
            if(h[p[u][i]] > h[v])
                u = p[u][i];
        }
        u = p[u][0];
    }
    if(u == v)
        return u;

    for(int i=LOGN-1;i>=0;i--){
        if(p[u][i] != p[v][i]){
            u = p[u][i];
            v = p[v][i];
        }
    }
    u = p[u][0];
    return u;
}


set<pii> vals[MAXN];
int L[MAXN], ind[MAXN];
int main (){
    for_tests(t, tt){
        degt = 0;
        degv = 0;
        en = 0;
        scanf("%d", &n);
        for(int a=0;a<=n;a++){
            vals[a].clear();
            L[a] = 0;
            ind[a] = a;
            ar[a] = -1;
        }
        p[1][0] = 1;
        for(int a=2;a<=n;a++){
            scanf("%d", &p[a][0]);
            nx[en] = ar[p[a][0]];
            to[en] = a;
            ar[p[a][0]] = en++;
        }
        for(int a=1;a<=n;a++)
            scanf("%d", s+a);
        h[1] = 1;
        go(1);
        sort(ind, ind+degv, [&](int a, int b) { return hh[a] < hh[b]; });
        int roots[MAXN], degr = 0;
        roots[degr++] = copia();
        int newRoot;
        for(int i=0;i<degv;i++){
            if(i == 0 || hh[ind[i-1]] != hh[ind[i]])
                newRoot = copia(tree[roots[degr-1]]);
            int u = vh[ind[i]];
            if(!vals[s[u]].empty()){
                //printf("vals s[%d] %d nao vazio\n", u, s[u]);
                auto aft = vals[s[u]].upper_bound({id[u], u});
                auto bef = aft;
                int bu, au;
                bool hasbef = false, hasaft = false;
                if(bef != vals[s[u]].begin()){
                    hasbef = true;
                    bef--;
                    bu = bef->snd;
                }
                if(aft != vals[s[u]].end()){
                    hasaft = true;
                    au = aft->snd;
                }
                if(hasbef && hasaft){
                    //assert(L[bef->snd] == lca(bef->snd, aft->snd));
                    int lc = L[bu];//lca(bef->snd, aft->snd);
                    upd(newRoot, 0, deg-1, id[lc], 1);
                }
                if(hasbef){
                    int lc = lca(bu, u);
                    L[bu] = lc;
                    upd(newRoot, 0, deg-1, id[lc], -1);
                }
                if(hasaft){
                    int lc = lca(u, au);
                    L[u] = lc;
                    upd(newRoot, 0, deg-1, id[lc], -1);
                }
            }
            vals[s[u]].insert({id[u], u});
            upd(newRoot, 0, deg-1, id[u], 1);
            //puts("");
            if(i == degv-1 || hh[ind[i]] != hh[ind[i+1]])
                roots[degr++] = newRoot;
        }
        scanf("%d", &m);
        int ans = 0;
        for(int a=0;a<m;a++){
            int u, x;
            scanf("%d%d", &u, &x);
            u ^= ans; x ^= ans;
            int prof = min(degr-1, h[u] + x);
            //printf("para u %d prof ate %d\n", u, prof);
            ans = qry(roots[prof], 0, deg-1, mn[u], mx[u]);
            printf("%d\n", ans);
        }
    }
}

