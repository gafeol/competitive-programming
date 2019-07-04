// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1237
// 10296 - Jogging Trails

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

const int MAXN = 212;

const ll INF = LLONG_MAX/3ll;

int n, m, k;
int s[MAXN];

namespace match {
    const int BITMASK = (1<<16);
    ll min_cost[BITMASK];
    vector<vector<ll>> dist;
    int n;

    void init(int nn, vector<vector<ll>> &mnDist) {
        n = nn;
        dist = mnDist;
        for(int i=0;i<(1<<n);i++)
            min_cost[i] = INF;
    }

    ll mnCostMatch(int bm = (1<<n)-1){
        if(bm == 0) return 0;
        if(min_cost[bm] != INF)
            return min_cost[bm];
        
        for(int u=0;u<n;u++){
            if(!((1<<u)&bm)) continue;
            for(int v=u+1;v<n;v++){
                if(!((1<<v)&bm)) continue;
                min_cost[bm] = min(min_cost[bm], mnCostMatch(bm ^ (1<<u) ^ (1<<v)) + dist[u][v]);
            }
        }
        return min_cost[bm];
    }
}


ll cost_of_duplication(vector<vector<pair<int, ll>>> &adj, vector<vector<ll>> &mnDist){
    vector<int> oddVertex;
    for(int a=0;a<n;a++)
        if(((int)adj[a].size())&1)
            oddVertex.pb(a);

    vector<vector<ll>> edges(n, vector<ll>(n));

    for(int i=0;i<oddVertex.size();i++){
        for(int j=i+1;j<oddVertex.size();j++){
            int u = oddVertex[i], v = oddVertex[j];
            edges[j][i] = edges[i][j] = mnDist[u][v];
        }
    }

    match::init(oddVertex.size(), edges);

    return match::mnCostMatch();
}

void floyd_warshall(vector<vector<ll>> &mnDist){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                mnDist[i][j] = min(mnDist[i][k] + mnDist[k][j], mnDist[i][j]);
            }
        }
    }
}



int main (){
    while(scanf("%d", &n) != EOF && n){
        scanf("%d", &m);
        vector<vector<pair<int, ll>>> adj(n);
        vector<vector<ll>> mnDist(n, vector<ll>(n, INF));
        ll sum = 0;
        for(int a=0;a<n;a++)
            mnDist[a][a] = 0;
        for(int a=0;a<m;a++){
            int i, j;
            ll c;
            scanf("%d%d%lld", &i, &j, &c);
            i--;j--;
            adj[i].pb({j, c});
            adj[j].pb({i, c});
            mnDist[i][j] = min(mnDist[i][j], c);
            mnDist[j][i] = min(mnDist[j][i], c);
            sum += c;
        }
        floyd_warshall(mnDist);
        printf("%lld\n", sum + cost_of_duplication(adj, mnDist));
    }
}

