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

const int MAXN = 212;

int n, m, k;
int s[MAXN];
ll x[] = {1518410187442699518LL,1518409177581024365LL};
vector<int> adj[MAXN];
ll ans[MAXN];

void go(int u, int p, int t){
    ans[u] = x[t];
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        go(nxt, u, 1-t);
    }

}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<=n;a++){
            adj[a].clear();
        }
        for(int a=0;a<n-1;a++){
            int i, j;
            scanf("%d%d", &i, &j);
            adj[i].pb(j);
            adj[j].pb(i);
        }
        go(1, 1, 0);
        for(int a=1;a<=n;a++)
            printf("%lld%c", ans[a], " \n"[a==n]);
    }
}

