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

const int MAXN = 112345;

int n, m;
ll sz[MAXN];
vector<int> adj[MAXN];
vector<ll> ar;
int getsz(int u, int p){
    sz[u] = 1;
    for(int nxt: adj[u]){
        if(nxt == p) continue; 
        sz[u] += getsz(nxt, u);
    }
    if(u != p)
        ar.pb((n-sz[u])*sz[u]);
    return sz[u];
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<=n;a++){
            adj[a].clear();
            sz[a] = 0;
        }
        for(int a=1;a<n;a++){
            int u, v;
            scanf("%d%d", &u, &v);
            u--;v--;
            adj[v].pb(u);
            adj[u].pb(v);
        }
        scanf("%d", &m);
        ar.clear();
        vector<ll> p;
        int deg = 0;
        while(deg < m){
            ll x;
            scanf("%lld", &x);
            p.pb(x);
            deg++;
        }
        while(p.size() < n-1)
            p.pb(1);
        sort(p.begin(), p.end());
        while(p.size() > n-1){
            ll gt = p.back();
            p.pop_back();
            ll gtt = p.back();
            p.pop_back();
            p.pb(mod(gt*gtt));
        }
        sort(p.begin(), p.end(), greater<ll>());
        getsz(0, 0);
        assert(p.size() == ar.size());
        assert(p.size() == n-1);
        ll ans = 0;
        sort(ar.begin(), ar.end(), greater<ll>());
        for(int i=0;i<p.size();i++){
            //printf("soma %lld * %lld\n", p[i], ar[i]);
            ans = mod(ans + mod(p[i]*ar[i]));
        }
        ans = mod(ans + modn);
        printf("%lld\n", ans);
    }
}

