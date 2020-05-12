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

const int MAXN = 21234;

int n, m, k;
int s[MAXN];
int mrk[MAXN];
int deg[MAXN];
int sz[MAXN];
int h[MAXN];

vector<int> adj[MAXN];

void go(int u){
    if(mrk[u]) return ;
    sz[u] = 1; 
    h[u] = 0;
    for(int nxt: adj[u]){
        go(nxt); 
        sz[u] += sz[nxt];
        h[u] = max(h[u], h[nxt]);
    }
    h[u]++;
}

int main (){
	scanf("%d %d", &n, &m);
	for(int a=1;a<=n;a++){
        int x;
        scanf("%d", &x);
        if(x){
            adj[a].pb(x);
            deg[x]++;
        }
	}
    set<pii> q;
    for(int a=1;a<=n;a++){
        go(a);
        if(!deg[a])
            q.insert({-h[a], a});
    }
    int ans = 0;
    while(!q.empty()){
        ans++;
        int k = m;
        queue<int> prox;
        while(!q.empty() && k--){
            int u = q.begin()->snd; 
            q.erase(q.begin());
            for(int nxt: adj[u]){
                deg[nxt]--;
                if(!deg[nxt])
                    prox.push(nxt);
            }

        }
        while(!prox.empty()){
            int u = prox.front();
            prox.pop();
            q.insert({-h[u], u});
        }
    }
    printf("%d\n", ans);

}

