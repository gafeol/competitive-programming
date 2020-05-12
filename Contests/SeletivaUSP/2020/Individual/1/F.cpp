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
ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 512345;

int n, m, k;
int s[MAXN];

int prv[MAXN];
vector<int> adj[MAXN];

int sz[MAXN];
int cnt[MAXN];

int go(int u){
    sz[u] = 1;
    for(int nxt: adj[u]){
        sz[u] += go(nxt);
    }
    return sz[u];
}

void add(int x){
    while(x > 1){
        cnt[prv[x]]++;
        x/=prv[x];
    }
}

void rmv(int x){
    while(x > 1){
        cnt[prv[x]]--;
        x/=prv[x];
    }
}

ll expo(ll base, ll e){
    if(e == 0)
        return 1ll;
    ll ans = expo(base, e/2ll);
    ans = mod(ans*ans);
    if(e&1)
        ans = mod(ans*base);
    return ans;
}

int main (){
    memset(prv, -1, sizeof(prv)); 
    for(int a=2;a<MAXN;a++){
        if(prv[a] != -1) continue;
        prv[a] = a;
        for(ll b = a;a*b < MAXN;b++){
            prv[a*b] = a;
        }
    }
    for_tests(t, tt){
        scanf("%d%lld", &n, &modn);
        for(int a=1;a<=n;a++){
            adj[a].clear();
            cnt[a] = 0;
        }
            
        for(int a=2;a<=n;a++){
            int x;
            scanf("%d", &x);
            adj[x].pb(a);
        }
        go(1);
        for(int a=2;a<sz[1];a++)
            add(a);
        for(int a=2;a<=n;a++)
            rmv(sz[a]);
        ll ans = 1;
        for(int a=2;a<=n;a++){
            ans = mod(ans*expo(a, cnt[a]));
        }
        printf("%lld\n", ans);
    }
}

