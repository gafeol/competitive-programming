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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];
int sz[MAXN];

vector<pil> adj[MAXN];

int getsz(int u, int p){
    sz[u] = 1;
    for(pii ar: adj[u]){
        int nxt = ar.fst;
        if(nxt == p) continue;
        sz[u] += getsz(nxt, u);
    }
    return sz[u];
}

int getc(int u, int p){
    for(pii ar: adj[u]){
        int nxt = ar.fst;
        if(nxt == p) continue;
        if(sz[nxt] >= n/2)
            return getc(nxt, u);
    }
    return u;
}

ll ans;

void go(int u, int p, ll d = 0){
    ans += d*2ll;
    for(pil ar: adj[u]){
        int nxt = ar.fst;
        if(nxt == p) continue;
        go(nxt, u, d + ar.snd);
    }
}

int main (){
    for_tests(t, tt){
        ans = 0;
        scanf("%d", &n);
        for(int a=0;a<=n;a++)
            adj[a].clear();
        for(int a=1;a<n;a++){
            int i, j;
            ll c;
            scanf("%d%d%lld", &i, &j, &c);
            adj[i].pb({j, c});
            adj[j].pb({i, c});
        }
        getsz(1, 1);
        int c = getc(1, 1);
        go(c, c);
        printf("Case #%d: %lld\n", tt, ans);
    }
}

