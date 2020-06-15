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

const int MAXN = 1123;
const int LOGN = 12;

int n, m, k;
int s[MAXN];

int p[MAXN][LOGN];
int h[MAXN];
vector<pii> adj[MAXN];
void go(int u, int pai){
    p[u][0] = pai;
    h[u] = h[pai] + 1;
    for(int i=1;i<LOGN;i++)
        p[u][i] = p[p[u][i-1]][i-1];
    for(pii ar: adj[u]){
        int nxt = ar.fst;
        if(nxt == pai) continue;
        go(nxt, u);
    }
}

int LCA(int u, int v){
    if(h[u] != h[v]){
        if(h[u] < h[v])
            swap(u, v);
        for(int i=LOGN-1;i>=0;i--){
            if(h[p[u][i]] > h[v])
                u = p[u][i];
        }
        u = p[u][0];
    }
    if(u == v) return u;
    for(int i=LOGN-1;i>=0;i--){
        if(p[u][i] != p[v][i]){
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}

inline int dist(int u, int v){
    return h[u] + h[v] - 2*h[LCA(u, v)];
}

int d[MAXN][MAXN];
int dis[MAXN], mrk[MAXN], tempo;

bool inpath(int u, int s, int t){
    //printf("is %d in path %d %d? %d\n", u, s, t, (d[s][u] + d[u][t] == d[s][t]));
    return (d[s][u] + d[u][t] == d[s][t]);
}

void bfs(int ini, int fim){
    set<pii> q;
    dis[ini] = 0;
    mrk[ini] = tempo;
    q.insert({dis[ini], ini});
    //printf("ini %d fim %d\n", ini, fim);
    while(!q.empty()){
        int u = q.begin()->snd;
        q.erase(q.begin());
        for(pii ar: adj[u]){
            int nxt = ar.fst;
            if(!inpath(nxt, ini, fim) || d[nxt][fim] >= d[u][fim]) continue;
            if(mrk[nxt] != tempo || dis[nxt] > dis[u] + ar.snd){
                if(mrk[nxt] == tempo){
                    q.erase({dis[nxt], nxt});
                }
                dis[nxt] = dis[u] + ar.snd;
                mrk[nxt] = tempo;
                q.insert({dis[nxt], nxt});
            }
        }
    }
}

int main (){
	scanf("%d", &n);
    tempo =0;
	for(int a=0;a<n-1;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        i--;j--;
        adj[i].pb({j, 1});
        adj[j].pb({i, 1});
	}
    go(0, 0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            d[i][j] = dist(i, j);
            //printf("d[%d][%d] %d\n", i, j, d[i][j]);
        }
    }
    scanf("%d", &m);
    vector<tuple<int, int, int> > vec; 
    for(int a=0;a<m;a++){
        int u, v;
        scanf("%d%d", &u, &v);
        u--;v--;
        vec.pb({d[u][v], u, v});
    }
    sort(vec.begin(), vec.end());
    int res = 0;
    for(tuple<int, int, int> tp: vec){
        int aaa, u, v;
        tie(aaa, u, v) = tp;
        tempo++;
        bfs(u, v);
        res += dis[v]+1;
        adj[u].pb({v, 0});
        adj[v].pb({u, 0});
    }
    printf("%d\n", res);
}

