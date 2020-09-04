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
int s[MAXN];
ll dp[MAXN][2];
int sz[MAXN];
vector<int> adj[MAXN];

int dfs(int u, int p){
    sz[u] = 1;
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        sz[u] += dfs(nxt, u);
    }
    return sz[u];
}

ll go(int u, int p, int t){
    vector<pair<ll, ll>> val;
    vector<int> son;
    ll &r = dp[u][t];
    if(r != -1)
        return r;
    r = 0;
    ll sum = 0;
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        val.pb({go(nxt, u, 0), go(nxt, u, 1)});
        son.pb(nxt);
        sum += val.back().first;
    }

    if(t == 0){
        r = sz[u] + sum;
    }
    else{
        if(val.empty())
            r = n;
        else{
            for(int i=0;i<val.size();i++){
                pair<ll, ll> p = val[i];
                int f = son[i];
                r = max(r, n - sz[f] + sum - p.fst + p.snd);
            }
        }
    }
    //printf("res u %d p %d t %d eh %lld\n", u, p, t, 
    return r;
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<n;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        i--;j--;
        adj[i].pb(j);
        adj[j].pb(i);
	}
    int r = 0;
    for(int a=0;a<n;a++){
        if(adj[a].size() == 1)
            r = a;
    }

    dfs(r, r);
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", max(go(r, r, 0), go(r, r, 1)));
}

