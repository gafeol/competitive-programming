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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 3123;

int n, m, k;
int s[MAXN];

ll dp[MAXN][MAXN];

vector<int> adj[MAXN];
vector<int> sz[MAXN];

int dfs(int u, int p){
    int size = 1;
    debug("no u %d p %d\n", u, p);
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        size += dfs(nxt, u);
    }
    debug("no u %d p %d sz %d\n", u, p, size);
    return size;
}

ll go(int u, int v, int bu, int bv){
    ll &r = dp[u][v]; 
    if(r != -1)
        return r;
    r = 0;
    ll totu = 0, totv = 0;
    for(int i=0;i<adj[u].size();i++){
        int nxt = adj[u][i];
        int tam = sz[u][i];
        if(bu == nxt || v == nxt) continue;
        totu += tam;
    }
    for(int i=0;i<adj[v].size();i++){
        int nxt = adj[v][i];
        int tam = sz[v][i];
        if(bv == nxt || u == nxt) continue;
        totv += tam;
    }


    //printf("u %d v %d totu %lld totv %lld\n", u, v, totu, totv);
    for(int i=0;i<adj[u].size();i++){
        int nxt = adj[u][i];
        int tam = sz[u][i];
        if(bu == nxt || v == nxt) continue;
        r = max(r, go(nxt, v, u, bv) + ((ll)tam)*(1ll+totv));
    }
    for(int i=0;i<adj[v].size();i++){
        int nxt = adj[v][i];
        int tam = sz[v][i];
        if(bv == nxt || u == nxt) continue;
        r = max(r, go(u, nxt, bu, v) + ((ll)tam)*(1ll+totu));
    }
    //printf("go(%d, %d) %lld\n", u, v, r);
    return r;
}

int main (){
    memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int a=1;a<n;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        adj[i].pb(j);
        adj[j].pb(i);
	}
    for(int a=1;a<=n;a++){
        for(int i=0;i<adj[a].size();i++){
            int nxt = adj[a][i];
            sz[a].pb(dfs(nxt, a));
        }
    }
    ll ans = 0;
    for(int a=1;a<=n;a++){
        ll tot = 0;
        for(int i=0;i<adj[a].size();i++)
            tot += sz[a][i];
        //printf("a %d tot %lld\n", a, tot);
        for(int i=0;i<adj[a].size();i++){
            int nxt = adj[a][i];
            //printf("poss chamar go(%d,%d) + %lld\n", a, nxt, (1ll + tot - sz[a][i])*((ll)sz[a][i]));
            ans = max(ans, go(a,nxt,nxt,a) + (1ll + tot - sz[a][i])*((ll)sz[a][i]));
        }
    }
    printf("%lld\n", ans);
}

