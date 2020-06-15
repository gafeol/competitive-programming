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
const ll modn = 11092019;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1000009;

struct arv{
    int mx;  
    ll nj;
} tree[4*MAXN];

vector<int> adj[MAXN];

int n, m, k;
int s[MAXN], id[MAXN], L[MAXN], R[MAXN], deg;

arv join(arv a, arv b){
    if(a.mx != b.mx){
        if(a.mx < b.mx)
            swap(a, b);
        return a;
    }
    a.nj = mod(a.nj + b.nj);
    return a;
}

void upd(int idx, int i, int j, int l, arv x){
    if(i > l || j < l)
        return ;
    if(i == j){
        tree[idx] = x;
        return ;
    }
     int m = (i + j)/2;
     upd(idx*2, i, m, l, x);
     upd(idx*2+1, m+1, j, l, x);
     tree[idx] = join(tree[idx*2], tree[idx*2+1]);
}


arv qry(int idx, int i, int j, int l, int r){
    if(i > r || j < l)
        return {0, 0};
    if(i >= l && j <= r) 
        return tree[idx]; 
    int m = (i + j)/2;
    return join(qry(idx*2, i, m, l, r), qry(idx*2+1, m+1, j, l, r));
}

void go(int u){
    L[u] = deg;
    id[u] = deg++; 
    for(int nxt: adj[u]){
        go(nxt);
    }
    R[u] = deg-1;
}


int main (){
	scanf("%d", &n);
    int ind[MAXN];
	for(int a=1;a<=n;a++){
        scanf("%d", s+a);
        ind[a] = a;
	}
    for(int a=2;a<=n;a++){
        int p;
        scanf("%d", &p);
        adj[p].pb(a);
    }
    go(1);
    sort(ind+1, ind+n+1, [&](int a, int b) { return (s[a] > s[b] || (s[a] == s[b] && id[a] > id[b])); });
    arv ans = {0, 0};
    for(int a=1;a<=n;a++){
        int u = ind[a];
        arv res = qry(1, 0, deg-1, L[u], R[u]);
        if(res.mx == 0)
            res = {1, 1};
        else
            res = {res.mx+1, res.nj};
        ans = join(res, ans);
        //printf("upd %d res %d %lld\n", u, res.mx, res.nj);
        upd(1, 0, deg-1, id[u], res);
    }
    printf("%d %lld\n", ans.mx, ans.nj);
}

