#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
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

const int MAXN = 512345;
//               12345678901234
const ll INF  = 500000000000009LL;
int n, m, k;
int L[MAXN], R[MAXN];
vector<pil> adj[MAXN];
vector<tuple<int, int, int>> q[MAXN];
struct arv{
    ll lz, s;
} tree[MAXN*4];

void unlaze(int idx, int i, int j){
    if(tree[idx].lz != 0 && i != j){
        ll aux = tree[idx].lz;
        tree[idx*2].s += aux;  
        tree[idx*2].lz += aux;

        tree[idx*2+1].s += aux;
        tree[idx*2+1].lz += aux;
    }
    tree[idx].lz = 0;
}

void upd(int idx, int i, int j, int l, int r, ll x){
    if(i > r || j < l) return ;
    unlaze(idx, i, j);
    if(i >= l && j <= r){
        tree[idx].lz += x;
        tree[idx].s += x;
        return ;
    }
    int m = (i + j)/2;
    upd(idx*2, i, m, l, r, x);
    upd(idx*2+1, m+1, j, l, r, x);
    tree[idx].s = min(tree[idx*2].s, tree[idx*2+1].s);
}

ll qry(int idx, int i, int j, int l, int r){
    if(i > r || j < l) return LLONG_MAX;
    unlaze(idx, i, j);
    if(i >= l && j <= r)
        return tree[idx].s;
    int m = (i + j)/2;
    return min(qry(idx*2, i, m, l, r), qry(idx*2+1, m+1, j, l, r));
}

ll dis[MAXN];
void dfs(int u, ll d){
    L[u] = R[u] = u;
    dis[u] = d;
    for(pil ar: adj[u]){
        int nxt = ar.fst;
        ll c = ar.snd;
        dfs(nxt, d+c);
        L[u] = min(L[u], L[nxt]);
        R[u] = max(R[u], R[nxt]);
    }
}


ll ans[MAXN];

void go(int u){
    for(tuple<int, int, int> tp: q[u]){
        int l, r, ind;
        tie(l, r, ind) = tp;
        ans[ind] = qry(1, 1, n, l, r);
    }
    for(pil ar: adj[u]){
        int nxt = ar.fst;
        ll c = ar.snd;
        upd(1, 1, n, L[nxt], R[nxt], -c);
        if(L[nxt] > 1)
            upd(1, 1, n, 1, L[nxt]-1, c);
        if(R[nxt] < n)
            upd(1, 1, n, R[nxt]+1, n, c);
        go(nxt);
        upd(1, 1, n, L[nxt], R[nxt], c);
        if(L[nxt] > 1)
            upd(1, 1, n, 1, L[nxt]-1, -c);
        if(R[nxt] < n)
            upd(1, 1, n, R[nxt]+1, n, -c);
    }
}

void build(int idx, int i, int j){
    tree[idx].lz = 0;
    if(i == j){
        if(adj[i].empty())
            tree[idx].s = dis[i];
        else
            tree[idx].s = INF;
        return;
    }
    int m = (i + j)/2;
    build(idx*2, i, m);
    build(idx*2+1, m+1, j);
    tree[idx].s = min(tree[idx*2].s, tree[idx*2+1].s);
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=2;a<=n;a++){
        int p;
        ll k;
        scanf("%d%lld", &p, &k);
        adj[p].pb({a, k});
	}
    for(int a=0;a<m;a++){
        int v, l, r;
        scanf("%d%d%d", &v, &l, &r);
        q[v].pb({l, r, a});
    }
    dfs(1, 0);
    build(1, 1, n);
    go(1);
    for(int a=0;a<m;a++){
        printf("%lld\n", ans[a]);
    }
}

