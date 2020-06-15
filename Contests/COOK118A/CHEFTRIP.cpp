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
#define dec askldjaslkjd

const int MAXN = 212345;
const int LOGN = 20;

int n, m, k;
int s[MAXN], h[MAXN];

int mx[MAXN][LOGN], mn[MAXN][LOGN], p[MAXN][LOGN];
int inc[MAXN][LOGN], dec[MAXN][LOGN];

vector<int> adj[MAXN];


void go(int u, int pai){
    h[u] = h[pai] + 1;
    p[u][0] = pai;
    mx[u][0] = mn[u][0] = s[u];
    inc[u][0] = dec[u][0] = 1;
    for(int i=1;i<LOGN;i++){
        p[u][i] = p[p[u][i-1]][i-1];
        mx[u][i] = max(mx[u][i-1], mx[p[u][i-1]][i-1]);
        mn[u][i] = min(mn[u][i-1], mn[p[u][i-1]][i-1]);
        inc[u][i] = (inc[u][i-1] && inc[p[u][i-1]][i-1] && mx[u][i-1] < mn[p[u][i-1]][i-1]);
        dec[u][i] = (dec[u][i-1] && dec[p[u][i-1]][i-1] && mn[u][i-1] > mx[p[u][i-1]][i-1]);
    }

    for(int nxt: adj[u]){
        if(nxt == pai) continue;
        go(nxt, u);
    }
}

int lca(int u, int v){
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
    return p[u][0];
}

int mxt(int u, int v){
    int aux = 0; 
    if(u != v){
        for(int i=LOGN-1;i>=0;i--){
            if(h[p[u][i]] > h[v]){
                aux = max(aux, mx[u][i]);
                u = p[u][i];
            }
        }
        aux = max(aux, mx[u][0]);
        u = p[u][0];
    }
    assert(u == v);
    return max(aux, s[u]);
}

bool isinc(int u, int v){
   if(h[u] <= h[v]) return 1; 
   int mxx = 0;
   for(int i=LOGN-1;i>=0;i--){
        if(h[p[u][i]] > h[v]){
            if(mxx >= mn[u][i] || !inc[u][i])
                return false;
            mxx = max(mxx, mx[u][i]);
            u = p[u][i];
        }
        if(mxx >= mn[u][0] || !inc[u][0])
            return false;
        mxx = max(mxx, mx[u][0]);
        u = p[u][0];
   }
   assert(u == v);
   return (mxx < mn[u][0]);
}
bool isdec(int u, int v){
   if(h[u] <= h[v]) return 1; 
   int mnn = INT_MAX;
   for(int i=LOGN-1;i>=0;i--){
        if(h[p[u][i]] > h[v]){
            if(mnn <= mx[u][i] || !dec[u][i])
                return false;
            mnn = min(mnn, mn[u][i]);
            u = p[u][i];
        }
        if(mnn <= mx[u][0] || !inc[u][0])
            return false;
        mnn = min(mnn, mn[u][0]);
        u = p[u][0];
   }
   assert(u == v);
   return (mnn > mx[u][0]);
}

int find(int u, int x){
    for(int i=LOGN-1;i>=0;i--){
        if(mx[u][i] < x)
            u = p[u][i];
    }
    //if(s[u] != x)
        //u = p[u][0];
    assert(s[u] == x);
    return u;
}

bool valid(int u, int v){
    int lc = lca(u, v);

    int mxl = mxt(u, lc);
    int mxr = mxt(v, lc);

    int pivot;
    if(mxl > mxr){
        pivot = find(u, mxl);
        return (isinc(u, pivot) && isdec(pivot, lc) && isinc(v, lc));
    }
    else{
        pivot = find(v, mxr);
        return (isinc(v, pivot) && isdec(pivot, lc) && isinc(u, lc));
    }
}

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        for(int a=1;a<n;a++){
            int i,j;
            scanf("%d%d", &i, &j);
            i--;j--;
            adj[i].pb(j);
            adj[j].pb(i);
        }
        for(int a=0;a<n;a++)
            scanf("%d", s+a);
        go(0, 0);
        for(int a=0;a<m;a++){
            int i, j;
            scanf("%d%d", &i, &j);
            i--;j--;
            printf("%d", valid(i, j));
        }
        puts("");
    }
}

