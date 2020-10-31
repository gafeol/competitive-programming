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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

map<pii, bool> mrk;
vector<int> adj[MAXN], inv[MAXN];

int vis[MAXN];

void go(int u){
    vis[u] = true;

    for(int nxt: adj[u]){
        if(!vis[nxt]){
            mrk[{u, nxt}] = true;
            go(nxt);
        }
    }
}


void goinv(int u){
    vis[u] = true;
    for(int nxt: inv[u]){
        if(!vis[nxt]){
            mrk[{nxt, u}] = true;
            goinv(nxt);
        }
    }
}


int main (){
    int t;
    scanf("%d", &t);
    vector<pii> roads;
    while(t--){
        scanf("%d%d", &n, &m);
        roads.clear();
        mrk.clear();
        for(int a=0;a<n;a++){
            adj[a].clear();
            inv[a].clear();
        }
        for(int a=0;a<m;a++){
            int i, j;
            scanf("%d%d", &i, &j);
            i--;j--;
            roads.pb({i, j});
            adj[i].pb(j);
            inv[j].pb(i);
        }
        for(int a=0;a<n;a++)
            vis[a] = 0;
        go(0);
        for(int a=0;a<n;a++)
            vis[a] = 0;
        goinv(0);

        int sob = 2*n - mrk.size();
        for(pii p: roads){
            if(mrk[p])
                continue;
            else if(sob > 0){
                sob--;
                continue;
            }
            printf("%d %d\n", p.fst+1, p.snd+1);
        }
    }
    return 0;
}

