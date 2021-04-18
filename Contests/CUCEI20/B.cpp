#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
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

const int MAXN = 50004;
const int LOGN = 21;

int n, m, k;
int s[MAXN];

vector<int> adj[MAXN];

int p[MAXN][LOGN];
int h[MAXN];

void dfs(int u, int pai){
    p[u][0] = pai;
    h[u] = h[pai] + 1;
    for(int i=1;i<LOGN;i++){
        p[u][i] = p[p[u][i-1]][i-1];
    }
    for(int nxt: adj[u]){
        if(nxt == pai) continue;
        dfs(nxt, u);
    }
}

int lca(int u, int v){
    if(h[u] != h[v]){
        if(h[u] < h[v])
            swap(u, v);
        for(int i=LOGN-1;i>=0;i--){
            if(h[p[u][i]] > h[v]){
                u = p[u][i];
            }
        }
        u = p[u][0];
    }
    assert(h[u] == h[v]);

    if(u == v)
        return u;

    for(int i=LOGN-1;i>=0;i--){
        if(p[u][i] == p[v][i]) continue;
        u = p[u][i];
        v = p[v][i];
    }
    return p[u][0];
}

vector<pii> compress(vector<pii> v){
    map<int, int> q;
    for(auto [x, qtd]: v){
        q[x] += qtd;
    }
    vector<pii> nv;
    for(auto par: q)
        nv.pb(par);
    return nv;
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<n;a++){
        int u, v;
        scanf("%d%d", &u, &v);
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
	}
    h[0] = 0;
    dfs(0, 0);

    int q;
    scanf("%d", &q);
    vector<pii> pos;
    ll c[14];
    for(int qry=0;qry<q;qry++){
        ll ans = 0;
        pos.clear();
        scanf("%d", &k);
        for(int i=0;i<k;i++){
            int u;
            scanf("%d", &u);
            u--;
            pos.eb(u, 1);
        }
        pos = compress(pos);
        c[0] = 0;
        for(int a=1;a<=k;a++){
            scanf("%lld", c+a);
            for(int b=0;b<a;b++) // ctz?
                c[a] = min(c[a], c[b] + c[a-b]);
        }

        while(pos.size() > 1){
            int mxh = 0;
            for(int i=0;i<pos.size();i++){
                for(int j=i+1;j<pos.size();j++){
                    int lc = lca(pos[i].fst, pos[j].fst);
                    mxh = max(mxh, h[lc]);
                }
            }
            //printf("mxh %d\n", mxh);

            for(auto& [u, qtd]: pos){
                if(h[u] <= mxh) continue;
                //printf("sobe u %d h %d  (%d caras) para altura %d\n", u, h[u], qtd, mxh);
                ans += (h[u] - mxh)*c[qtd];
                for(int i=LOGN-1;i>=0;i--){
                    if(h[p[u][i]] > mxh)
                        u = p[u][i];
                }
                u = p[u][0];
                //printf("agora novo u %d h %d\n", u, h[u]);
            }
            pos = compress(pos);
        }
        auto [u, qtd] = pos[0];
        assert(qtd == k);
        ans += (h[u] - h[0])*c[k];
        printf("%lld\n", ans);
    }
    return 0;
}

