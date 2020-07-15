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

const int MAXN = 100009;

int l, r;
struct arv{
    int sum;
    bool z;
} tree[MAXN*4];

void unlaze(int idx, int i, int j){
    if(tree[idx].z && i != j){
        tree[idx*2].sum = 0;
        tree[idx*2].z = 1;
        tree[idx*2+1].sum = 0;
        tree[idx*2+1].z = 1;
    }
    tree[idx].z = false;
}

void upd(int idx, int i, int j, int l, int x){
    if(i > l || j < l) return; 
    unlaze(idx, i, j);
    if(i == j){
        tree[idx].sum += x;
        return ;
    }
    int m = ((i + j)>>1);
    upd(idx*2, i, m, l, x);
    upd(idx*2+1, m+1, j, l, x);
    tree[idx].sum = tree[idx*2].sum + tree[idx*2+1].sum;
}

int qry(int idx, int i, int j, int l, int r){
    if(i > r || j < l) return 0;
    unlaze(idx, i, j);
    if(i >= l && j <= r)
        return tree[idx].sum;
    int m = ((i+j)>>1);
    return qry(idx*2, i, m, l, r) + qry(idx*2+1, m+1, j, l, r);
}

int n, m, k;
int sz[MAXN], mrk[MAXN];
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


void add(int x){
    //printf("add x %d\n", x);
    upd(1, 0, MAXN-1, x, 1);
}

void rmv(int x){
    //printf("rmv x %d\n", x);
    upd(1, 0, MAXN-1, x, -1);
}

ll getd(int x){
    ll ans = 0;
    if(r-x >= 0)
        ans = qry(1, 0, MAXN-1, max(0, l-x), r-x);
    //printf("getd %d l %d r %d ans %d\n", x, l, r, ans);
    return ans;
}

void clean(){
    tree[1].sum = 0;
    tree[1].z = true;
}

void goadd(int u, int p, int d){
    //printf("goadd u %d d %d\n", u, d);
    add(d);
    for(int nxt: adj[u]){
        if(nxt == p || mrk[nxt]) continue;
        goadd(nxt, u, d+1);
    }
}

void gormv(int u, int p, int d){
    //printf("gormv u %d d %d\n", u, d);
    rmv(d);
    for(int nxt: adj[u]){
        if(nxt == p || mrk[nxt]) continue;
        gormv(nxt, u, d+1);
    }
}

ll goans(int u, int p, int d){
    ll ans = getd(d);
    for(int nxt: adj[u]){
        if(nxt == p || mrk[nxt]) continue;
        ans += goans(nxt, u, d+1);
    }
    //printf("go ans u %d ans %lld\n", u, ans);
    return ans;
}

ll decomp(int u=1){
    int c = getc(u,u,sz[u]);
    //printf("decomp %d cent %d\n", u, c);
    mrk[c] = true;
    ll ans = 0;
    for(int nxt: adj[c]){
        if(mrk[nxt]) continue;
        goadd(nxt, c, 1);
    }
    ans += getd(0); 
    //printf("ans += d0 %lld\n", getd(0));
    for(int nxt: adj[c]){
        if(mrk[nxt]) continue;
        gormv(nxt, c, 1); 
        ans += goans(nxt, c, 1);  
    }
    clean();
    for(int nxt: adj[c]){
        if(mrk[nxt]) continue;
        getsz(nxt, c);
        ans += decomp(nxt);
    }
    //printf("decomp %d cent %d ans %lld\n", u, c, ans);
    return ans;
}

int main (){
    freopen("awesome.in", "r", stdin);
    for_tests(t, tt){
        scanf("%d%d%d", &n, &l, &r);
        for(int a=0;a<=n;a++){
            adj[a].clear();
            mrk[a] = 0;
        }
        swap(l, r);
        l = n-1-l;
        r = n-1-r;
        for(int a=1;a<n;a++){
            int i, j;
            scanf("%d %d", &i, &j);
            adj[i].pb(j);
            adj[j].pb(i);
        }
        getsz(1,1);
        ll ans = decomp(1);
        printf("%lld\n", ans);
    }
}

