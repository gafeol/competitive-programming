#include <bits/stdc++.h>
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
const ll modn = 1000000009;
const ll p =    1000000007;
const ll p2 =   1052578027;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 11234;

int n, m, k;
char s[MAXN];
int sz[MAXN];
vector<int> adj[MAXN];

map<pll, bool> has[MAXN];

int ans = 0;

ll val[MAXN];
ll val2[MAXN];
ll e[MAXN];
ll e2[MAXN];

pll go(int u){
    pll h = {val[s[u]], val2[s[u]]};
    sz[u] = 1;
    for(int nxt: adj[u]){
        pll nxth = go(nxt);
        sz[u] += sz[nxt];
        h.fst = mod(h.fst*e[sz[nxt]]);
        h.snd = mod(h.snd*e2[sz[nxt]]);
        h.fst = mod(h.fst + nxth.fst);
        h.snd = mod(h.snd + nxth.snd);
        h.fst = mod(h.fst*p + val[s[u]]);
        h.snd = mod(h.snd*p2 + val2[s[u]]);
    }
    has[sz[u]][h] = true;
    return h;
}

pll qry(int u){
    pll h = {val[s[u]], val2[s[u]]};
    sz[u] = 1;
    for(int nxt: adj[u]){
        pll nxth = qry(nxt);
        sz[u] += sz[nxt];
        h.fst = mod(h.fst*e[sz[nxt]]);
        h.snd = mod(h.snd*e2[sz[nxt]]);
        h.fst = mod(h.fst + nxth.fst);
        h.snd = mod(h.snd + nxth.snd);
        h.fst = mod(h.fst*p + val[s[u]]);
        h.snd = mod(h.snd*p2 + val2[s[u]]);
    }
    if(ans < sz[u] && has[sz[u]].find(h) != has[sz[u]].end())
        ans = sz[u];
    return h;
}
int main (){
    srand(time(NULL));
    e[0] = 1;
    e2[0] = 1;
    for(int i=1;i<MAXN;i++){
        e[i] = mod(e[i-1]*p);
        e2[i] = mod(e2[i-1]*p2);
    }
    for(int a='A';a<='Z';a++){
        val[a] = rand();
        val2[a] = rand();
    }
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        for(int a=0;a<=max(m, n);a++){
            adj[a].clear();
            has[a].clear();
        }
        int r = 0;
        for(int a=0;a<n;a++){
            int p;
            scanf(" %c %d", s+a, &p);
            if(p != -1)
                adj[p].pb(a);
            else
                r = a;
        }
        go(r);

        for(int a=0;a<=max(n, m);a++)
            adj[a].clear();
        n = m;
        r = 0;
        for(int a=0;a<n;a++){
            int p;
            scanf(" %c %d", s+a, &p);
            if(p != -1)
                adj[p].pb(a);
            else
                r = a;
        }
        ans = 0;
        qry(r);

        printf("%d\n", ans);
    }
}


