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

#define int ll

vector<tuple<int, int, int>> pilar;

int x, r;

int dist2(tuple<int, int, int> a, tuple<int, int, int> b);

const int INF = LLONG_MAX;
vector<int> cost;
vector<bool> ext;

int dij(int from = x){
    set<pair<int, int>> q;
    vector<int> dis(pilar.size(), INF);
    dis[from] = 0;
    q.insert({0, from});
    while(!q.empty()){
        auto [du, u] = *q.begin();
        q.erase(q.begin());
        auto [x, y, z] = pilar[u];
        for(int v=0;v<pilar.size();v++){
            auto [vx, vy, vz] = pilar[v];
            int d2 = dist2(pilar[u], pilar[v]);
            if(z >= vz && d2 <= r*r && dis[v] > dis[u] + cost[v]){
                if(dis[v] != INF)
                    q.erase({dis[v], v});
                dis[v] = dis[u] + cost[v];
                q.insert({dis[v], v});
            }
        }
    }
    int ans = LLONG_MAX;
    auto [ix, iy, iz] = pilar[from];
    for(int u=0;u<pilar.size();u++){
        if(ext[u]){
            auto [ex, ey, ez] = pilar[u];
            ans = min(ans, dis[u] + abs(iz - ez)*2ll);
        }
    }
    return ans;
}

int main (){
    dij();
}

