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

const int MAXN = 100005;
const int LOGN = 21;

int n, m, k;
int s[MAXN];

int p[MAXN][LOGN];
int pai[MAXN];
vector<int> adj[MAXN];

vector<pii> q[MAXN];

void dfs(int u){
    p[u][0] = pai[u];
    for(int i = 1;i<LOGN;i++){
        p[u][i] = p[p[u][i-1]][i-1];
    }
    for(int nxt: adj[u])
        dfs(nxt);
}


int bit[MAXN];

void upd(int i, int x){
    while(i < MAXN){
       bit[i] += x; 
       i += (i&-i);
    }
}

int qry(int i){
    int ans = 0;
    while(i > 0 ){
        ans +=  bit[i];
        i -= (i&-i);
    }
    return ans;
}

int ans[MAXN];

void go(int u){
    for(auto [l, r]: q[u]){
        upd(l, 1);
        upd(r+1, -1);
    }
    ans[u] = qry(s[u]);
    for(int nxt: adj[u]){
        go(nxt);
    }
    for(auto [l, r]: q[u]){
        upd(l, -1);
        upd(r+1, 1);
    }
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        scanf("%d%d", s+a, pai+a);
        pai[a]--;
        if(a != 0)
            adj[pai[a]].pb(a);
	}
    dfs(0);
    for(int a=0;a<m;a++){
        int u, l, r;
        scanf("%d%d%d", &u, &l, &r);
        u--;
        for(int i=LOGN-1;i>=0;i--){
            if(s[p[u][i]] <= r)
                u = p[u][i];
        }
        q[u].eb(l, r); 
    }
    go(0);
    for(int a=0;a<n;a++)
        printf("%d ", ans[a]);
    puts("");
    return 0;
}

