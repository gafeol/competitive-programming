#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
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
ll s[MAXN];
ll tot[MAXN];
vector<int> adj[MAXN];

bool ok;

pii go(int u, int p){
    pii cnt = {0, tot[u]};
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        pii f = go(nxt, u);
        cnt.fst += f.fst;
        cnt.snd += f.snd;
    }
    //         feliz       triste
    ll dif = (cnt.fst - cnt.snd) - s[u];
    //printf("u %d cnt %d %d s %d dif %d tot %d\n", u, cnt.fst, cnt.snd, s[u], dif, tot[u]);
    if(dif > 0 || dif%2 != 0)
        ok = false;
    else{
        cnt.fst -= dif/2; 
        cnt.snd += dif/2;
        if(cnt.fst < 0 || cnt.snd < 0)
            ok = false;
        assert(cnt.fst - cnt.snd - s[u] == 0);
    }
    return cnt;
}

int main (){
    for_tests(t, tt){
        ok = true;
        scanf("%d%d", &n, &m);
        for(int a=0;a<=n;a++)
            adj[a].clear();
        for(int a=1;a<=n;a++)
            scanf("%lld", tot+a);
        for(int a=1;a<=n;a++)
            scanf("%lld", s+a);
        for(int a=1;a<n;a++){
            int u, v;
            scanf("%d%d", &u, &v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        go(1, 1);
        if(ok)
            puts("YES");
        else
            puts("NO");
    }
}

