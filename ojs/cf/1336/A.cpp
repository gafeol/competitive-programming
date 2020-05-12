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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];
int h[MAXN];
int son[MAXN];
int deg[MAXN];
vector<int> adj[MAXN];

set<pii> q;

void go(int u, int p, int d=0){
    int cnt = 0;
    h[u] = d;
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        deg[u]++;
        cnt++;
        go(nxt, u, d+1);
    }
    if(cnt == 0)
        q.insert({-d, u});
}

int main (){
	scanf("%d%d", &n, &k);
	for(int a=1;a<n;a++){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
	}
    go(1, 1); 
    ll ans = 0;
    while(k--){
        pii p = *q.begin();
        q.erase(q.begin());
        ans -= p.fst;
        int u = p.snd;
        //printf("pega %d com valor %d\n", u, -p.fst);
        for(int nxt: adj[u]){
            if(h[nxt] == h[u]-1){
                son[nxt] += son[u] + 1;
                deg[nxt]--;
                if(deg[nxt] == 0){
                    q.insert({son[nxt] - h[nxt], nxt});
                    //printf("insere %d com son %d h %d\n", nxt, son[nxt], h[nxt]);
                }
            }
        }
    }
    printf("%lld\n", ans);
}
