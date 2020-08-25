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
int r;
int pai[MAXN];
int sz[MAXN];
vector<int> adj[MAXN];

void go(int u, int p){
    pai[u] = p;
    int cnt = 0;
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        cnt++;
        go(nxt, u);
        sz[u] += sz[nxt];
    }
    if(cnt == 0)
        sz[u] = 1;
}
set<pii> q;

int get(int u){
    int mxu = -1;
    for(int nxt: adj[u]){
        if(nxt == pai[u]) continue;
        if(mxu == -1 || sz[nxt] > sz[mxu])
            mxu = nxt;
    }
    if(mxu == -1)
        return u;
    return get(mxu);
}

void rmv(int u){
    int mxu = -1;
    for(int nxt: adj[u]){
        if(nxt == pai[u]) continue;
        if(mxu == -1 || sz[nxt] > sz[mxu])
            mxu = nxt;
    }
    if(mxu == -1)
        return ;

    for(int nxt: adj[u]){
        if(nxt == pai[u]) continue;
        if(nxt == mxu) 
            continue;
        else
            q.insert({-sz[nxt], nxt});
    }
    rmv(mxu);
}

int main (){
	scanf("%d%d", &n, &r);
	for(int a=1;a<n;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        adj[i].pb(j);
        adj[j].pb(i);
	}
    go(r, r);
    for(int nxt: adj[r]){
        q.insert({-sz[nxt], nxt});
    }

    vector<pii> ans;
    while(!q.empty()){
        pii big = *q.begin(); 
        q.erase(q.begin());
        int u = get(big.snd);
        if(q.empty()){
            ans.pb({r, u});
        }
        else{
            pii big2 = *q.begin();
            q.erase(q.begin());
            int v = get(big2.snd);
            ans.pb({u, v});
            rmv(big2.snd);
        }
        rmv(big.snd);
    }
    printf("%d\n", (int)ans.size());
    for(pii p: ans)
        printf("%d %d\n", p.fst, p.snd);
}

