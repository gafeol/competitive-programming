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

const int MAXN = 312345;


struct arv {
    ll s, lz;
} tree[4*MAXN];

int n, m, k;
vector<int> adj[MAXN];

vector<pii> ev[MAXN];

void unlaze(int idx, int i, int j){
    if(tree[idx].lz != 0 && i != j){
        ll aux = tree[idx].lz;
        int m= (i + j)/2;
        tree[idx*2].s += (m-i+1)*aux;
        tree[idx*2].lz += aux;

        tree[idx*2+1].s += (j-m)*aux;
        tree[idx*2+1].lz += aux;
    }
    tree[idx].lz = 0;
}

void upd(int idx, int i, int j, int l, int r, ll x){
    if(i > r || j < l) return;  
    unlaze(idx, i, j);
    if(i >= l && j <= r){
        tree[idx].s += (j-i+1)*x;
        tree[idx].lz += x;
        return ;
    }
    int m = (i + j)/2;
    upd(idx*2, i, m, l, r, x);
    upd(idx*2+1,m+1, j, l, r, x);
}

ll qry(int idx, int i, int j, int l){
    if(l < i || l > j)
        return 0;
    unlaze(idx, i, j);
    if(i == j){
        return tree[idx].s;
    }
    int m = (i +j)/2;
    return qry(idx*2, i, m, l) + qry(idx*2+1, m+1, j, l);
}


ll ans[MAXN];

void go(int u, int p, int h){
    for(pii e: ev[u]){
        upd(1, 0, n, h, min(n, h+e.fst), e.snd);
    }
    ans[u] = qry(1, 0, n, h);
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        go(nxt, u, h+1);
    }
    for(pii e: ev[u]){
        upd(1, 0, n, h, min(n, h+e.fst), -e.snd);
    }
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<n;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        adj[i].pb(j);
        adj[j].pb(i);
	}
    scanf("%d", &m);
    for(int a=0;a<m;a++){
        int u, d, x;
        scanf("%d%d%d", &u, &d, &x);
        ev[u].pb({d, x});
    }
    go(1, 1, 0);
    for(int a=1;a<=n;a++){
        printf("%lld%c", ans[a], " \n"[a==n]);
    }
}

