#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
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
int n, m, k;


pll lo[MAXN], up[MAXN];

int sz[MAXN], p[MAXN];

map<ll, set<pli>> X, Y;
ll ar[MAXN];

int raiz(int u){
    if(p[u] == u) return u;
    return p[u] = raiz(p[u]);
}

void join(int i, int j){
    if(i == -1 || j == -1) return;
    i = raiz(i);
    j = raiz(j);
    if(i == j) return;

    if(sz[i] < sz[j])
        swap(i, j);

    sz[i] += sz[j];
    ar[i] += ar[j];
    p[j] = i;
}

void insertSq(ll x, ll y, ll xx, ll yy, int id){
    lo[id] = {x, y};
    up[id] = {xx, yy};
    X[x].insert({y, id});
    X[x].insert({yy, id});
    X[xx].insert({y, id});
    X[xx].insert({yy, id});
    Y[y].insert({x, id});
    Y[y].insert({xx, id});
    Y[yy].insert({x, id});
    Y[yy].insert({xx, id});
}


bool in(ll x, ll y, int id){
    return (x >= lo[id].fst && y >= lo[id].snd && x <= up[id].fst && y <= up[id].snd); 
}

int find(ll x, ll y){

    auto itx = X[x].upper_bound({y, INT_MAX-2});
    if(itx != X[x].begin()){
        --itx;
        if(in(x, y, itx->snd))
            return itx->snd;
    }
    auto ity = Y[y].upper_bound({x, INT_MAX-2});
    if(ity != Y[y].begin()){
        --ity;
        if(in(x, y, ity->snd))
            return ity->snd;
    }
    return -1;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        ll x, y, w, h;
        scanf("%lld%lld%lld%lld", &x, &y, &w, &h);
        insertSq(x, y, x+w-1, y+h-1, a);
        ar[a] = w*h;
        p[a] = a;
        sz[a] = 1;
	}
    for(int a=0;a<n;a++){
        int vx[] = {-1, 0, 0, 1, 1, 1, -1, -1};
        int vy[] = {0, 1, -1, 0, 1,-1, -1,  1};
        for(int d=0;d<8;d++){
            int o;
            ll x = lo[a].fst + vx[d], y = lo[a].snd + vy[d];
            if(!in(x, y, a)){
                o = find(x, y);
                join(a, o);
            }

            x = lo[a].fst + vx[d]; y = up[a].snd + vy[d];
            if(!in(x, y, a)){
                o = find(x, y);
                join(a, o);
            }

            x = up[a].fst + vx[d]; y = lo[a].snd + vy[d];
            if(!in(x, y, a)){
                o = find(x, y);
                join(a, o);
            }

            x = up[a].fst + vx[d]; y = up[a].snd + vy[d];
            if(!in(x, y, a)){
                o = find(x, y);
                join(a, o);
            }
        }
    }
    /*
    for(int a=0;a<n;a++){
        if(p[a] == a){
            printf("a %d ar %lld\n", a, ar[a]);
        }
    }
    */
    printf("%lld\n", *max_element(ar, ar+n));
}

