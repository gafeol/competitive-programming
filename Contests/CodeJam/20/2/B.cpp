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

const int MAXN = 2123;
const int INF = 0X3f3f3f3f;

int n, m, k;

vector<int> aft[MAXN];
vector<int> tim[MAXN];

vector<pii> adj[MAXN];

int res[MAXN];
int cus[MAXN];
int mrk[MAXN];

void dij(int u){
    mrk[u] = 1;
    set<pii> q;
    q.insert({1, u});
    while(!q.empty()){
        int u = q.begin()->snd;
        q.erase(q.begin());
        for(pii ar: adj[u]){
            int nxt = ar.fst;
            int id = ar.snd;
            if(cus[id] == -1){
                cus[id] = max(1, res[nxt] - res[u]); 
                q.insert({res[nxt], nxt});
            }
        }
    }
}

int main (){
    for_tests(t, tt){
        for(int a=0;a<MAXN;a++){
            tim[a].clear();
            aft[a].clear();
            adj[a].clear();
            mrk[a] = 0;
            cus[a] = -1;
        }
        scanf("%d%d", &n, &m);
        for(int a=2;a<=n;a++){
            int x;
            scanf("%d", &x);
            if(x < 0)
                aft[-x].pb(a); 
            else
                tim[x].pb(a);
        }
        for(int a=0;a<m;a++){
            int i, j;
            scanf("%d%d", &i, &j);
            adj[i].pb({j, a});
            adj[j].pb({i, a});
        }
        tim[0].pb(1);
        int cnt = 0;
        for(int t=0;t<MAXN;t++){
            if(aft[cnt].empty() && tim[t].empty()) continue;
            for(int v: aft[cnt]){
                res[v] = t; 
            }
            for(int v: tim[t]){
                res[v] = t;
            }
            cnt += aft[cnt].size();
            cnt += tim[t].size();
        }
        dij(1);
        printf("Case #%d:", tt);
        for(int a=0;a<m;a++)
            printf(" %d", cus[a]);
        puts("");
    }
}

