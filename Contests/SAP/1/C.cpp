#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
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

const int MAXN = 11234;

int n, m, k;
int s[MAXN];
long long res, ans;
vector<pil> adj[MAXN];
ll d[MAXN];

int main (){
    for_tests(t, tt){
        ans = 0;
        scanf("%d%d", &n, &m);
        for(int a=0;a<=n;a++){
            adj[a].clear();
            d[a] = LLONG_MAX;
        }
        for(int a=0;a<m;a++){
            int i, j;
            ll k;
            scanf("%d%d%lld", &i, &j, &k); 
            adj[i].pb({j, k});
        }

        set<pli> q;
        d[1] = 0;
        q.insert({0ll, 1});
        while(!q.empty()){
            pli t = *q.begin();
            q.erase(q.begin());
            int u = t.snd;
            for(pil ar: adj[u]){
                int nxt = ar.fst;
                ll k = ar.snd;
                if(d[nxt] > d[u] + k){
                    if(d[nxt] != LLONG_MAX)
                        q.erase({d[nxt], nxt});
                    d[nxt] = d[u]  + k;
                    q.insert({d[nxt], nxt});
                }
            }
        }
        res += d[n];
    }
    printf("%lld\n", res);
}

