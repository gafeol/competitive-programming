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

// vals ate 2**20 -1
const int MAXN = 1100006;

int n, m, k;
int s[MAXN];
int L[MAXN], R[MAXN];
vector<pii> adj[MAXN];
int mrk[MAXN], vis[MAXN];
int temp_path[MAXN], final_path[MAXN], tsz, fsz;
int usd[MAXN];
// Only use if graph is guaranteed to have an euler cycle
void euler_dfs(int u){
	temp_path[tsz++] = u;
    while(!adj[u].empty()){
        pii ar = adj[u].back();
        adj[u].pop_back();
		int id = ar.snd;
		if(mrk[id])
            continue;
		mrk[id] = 1;
		int v = ar.fst; 
        euler_dfs(v);
	}
	final_path[fsz++] = temp_path[--tsz];
}
// Cycle stored in final_path[0...fsz-1]

inline void add_edge(int u, int v, int id){
    adj[u].pb({v, id});
    adj[v].pb({u, id});
}

inline void print(int id, int u, int v, int k){
    if(u == (s[id*2]%(1<<k))){
        printf("%d %d ", id*2+1, id*2+2);
    }
    else
        printf("%d %d ", id*2+2, id*2+1);
}

void dfs(int u){
    vis[u] = true;
    for(pii ar: adj[u]){
        int nxt = ar.fst;
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        int u, v;
        scanf("%d%d", &u, &v);
        s[a*2] = u;
        s[a*2+1] = v;
	}
    for(int k = 20;k>=0;k--){
        //debug("k %d\n", k);
        /// CLEAN
        tsz = fsz = 0;
        for(int a=0;a<n;a++){
            mrk[a] = 0;
            usd[a] = 0;
            int u = (s[a*2]%(1<<k));
            L[a] = u;
            int v = (s[a*2+1]%(1<<k));
            R[a] = v;
            adj[u].clear();
            vis[u] = 0;
            adj[v].clear();
            vis[v] = 0;
        }
        /// /CLEAN END
        for(int a=0;a<n;a++){
            mrk[a] = 0;
            int u = L[a];
            int v = R[a];
            add_edge(u, v, a);
        }
        int u = L[0];

        bool ok = true;
        // checa se eh par os grau
        dfs(u);
        for(int a=0;ok && a<n;a++){
            int u = L[a];
            int v = R[a];
            if((adj[u].size()&1))
                ok = false;
            if((adj[v].size()&1))
                ok = false;
            if(!vis[u])
                ok = false;
            if(!vis[v])
                ok = false;
        }
        if(!ok) continue;
        // checa se eh conexo

        euler_dfs(u);
//        printf("fsz %d\n", fsz);
//        for(int a=0;a<fsz;a++)
//            printf("%d ", final_path[a]);
//        puts("");
        if(fsz == n+1){
            printf("%d\n", k);
            unordered_map<int, unordered_map<int, vector<int>>> cord;
            for(int a=0;a<n;a++){
                int u = L[a];
                int v = R[a];
                cord[u][v].pb(a);
                cord[v][u].pb(a);
            }
            for(int a=0;a+1<fsz;a++){
                int aa = (a + 1)%fsz;
                int u = final_path[a];
                int v = final_path[aa];
                assert(!cord[u][v].empty());
                int ar = cord[u][v].back();
                while(usd[ar]){
                    cord[u][v].pop_back();
                    assert(!cord[u][v].empty());
                    ar = cord[u][v].back();
                }
                usd[ar] = 1;
                print(ar, u, v, k);
            }
            puts("");
            return 0;
        }
    }
}

