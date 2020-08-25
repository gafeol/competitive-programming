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

const int MAXN = 212345;

int n, m, k;

vector<int> adj[MAXN];
int ini, fim;
int mrk[MAXN];

bool foundPath;
vector<int> path;

void findPath(int u){
    mrk[u] = true;
    if(u == fim){
        foundPath = true;
        path.pb(u);
        return ;
    }
    for(int nxt: adj[u]){
        if(mrk[nxt]) continue;
        findPath(nxt);
        if(foundPath){
            path.pb(u);
            return ;
        }
    }
}

int indPath[MAXN];

int dfs(int u){
    mrk[u] = true;
    int ate = indPath[u]; 
    for(int nxt: adj[u]){
        if(mrk[nxt]) continue;
        if(indPath[nxt] != -1){
            ate = max(ate, indPath[nxt]);
            continue;
        }
        ate = max(ate, dfs(nxt));
    }
    return ate;
}

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        scanf("%d%d", &ini, &fim);
        ini--;fim--;
        for(int a=0;a<n;a++){
            adj[a].clear();
            mrk[a] = 0;
            indPath[a] = -1;
        }
        for(int a=0;a<m;a++){
            int i, j;
            scanf("%d%d", &i, &j);
            i--;j--;
            adj[i].pb(j);
        }

        path.clear();
        foundPath = false;
        findPath(ini);
        reverse(path.begin(), path.end());
        for(int i=0;i<path.size();i++){
            indPath[path[i]] = i;
        }
        for(int a=0;a<n;a++){
            mrk[a] = 0;
        }
        vector<int> finalPath;
        int good = 0;
        for(int i=0;i<path.size();i++){
            if(i == good)
                finalPath.pb(path[i]);
            good = max(good, dfs(path[i]));
        }
        printf("%d\n", (int)finalPath.size());
        for(int u: finalPath)
            printf("%d ", u+1);
        puts("");
    }
}

