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

const int MAXN = 500005;

int n, m, k;
int s[MAXN];

bool apg[MAXN];

vector<pii> adj[MAXN];
vector<int> comp[MAXN];
int p[MAXN], sz[MAXN];

int raiz(int u){
    if(p[u] == u) return u;
    return p[u] = raiz(p[u]);
}

int join(int u, int v){
    u = raiz(u);
    v = raiz(v);
    if(u == v) return 0;

    if(sz[u] < sz[v])
        swap(u, v);

    sz[u] += sz[v];
    p[v] = u;
    for(int x: comp[v])
        comp[u].pb(x);
    return v;
}
vector<pii> qry;
vector<pii> ares(1);
set<pii> rcomp[MAXN];
int main (){
    int q;
	scanf("%d%d%d", &n, &m, &q);
	for(int a=1;a<=n;a++){
        scanf("%d", s+a);
        p[a] = a;
        sz[a] = 1;
        comp[a].pb(a);
	}
    for(int a=1;a<=m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        adj[i].pb({j, a});
        adj[j].pb({i, a});
        ares.pb({i, j});
    }
    vector<int> mnRaiz(q);
    vector<vector<int>> mnComp(q);
    for(int a=0;a<q;a++){
        int t, i;
        scanf("%d %d", &t, &i);
        if(t == 2)
            apg[i] = 1;
        qry.pb({t, i});
    }
    for(int a=1;a<=m;a++){
        if(apg[a]) continue;
        int v = join(ares[a].fst, ares[a].snd);
        comp[v].clear();
    }

    for(int a=q-1;a>=0;a--){
        int t,i;
        t = qry[a].fst;
        i = qry[a].snd;
        if(t == 1)
            continue;
        int u = ares[i].fst, v = ares[i].snd;
        mnRaiz[a] = join(u, v);
        if(mnRaiz[a] > 0){
            mnComp[a] = comp[mnRaiz[a]];
            comp[mnRaiz[a]].clear();
        }
    }

    for(int u=1;u<=n;u++){
        if(u == p[u]){
            for(int v: comp[u]){
                rcomp[u].insert({-s[v], v});
            }
        }
    }
    for(int a=0;a<q;a++){
        int t,i;
        t = qry[a].fst;
        i = qry[a].snd;

        if(t == 1){
            int r = raiz(i);
            pii mai = {0, 0};
            if(!rcomp[r].empty()){
                mai = *rcomp[r].begin(); 
                rcomp[r].erase(rcomp[r].begin());
            }
            printf("%d\n", -mai.fst);
        }
        else{
            if(mnRaiz[a] == 0) continue;
            int mn = mnRaiz[a];
            int oldR = raiz(mn);
            assert(oldR != mn);
            p[mn] = mn;
            for(int v: mnComp[a]){
                p[v] = mn; 
                if(rcomp[oldR].find({-s[v], v}) != rcomp[oldR].end()){
                    rcomp[oldR].erase({-s[v], v});
                    rcomp[mn].insert({-s[v], v});
                }
            }
        }
    }
}

