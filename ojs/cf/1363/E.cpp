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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];
int g[MAXN];
ll c[MAXN];
int p[MAXN];
int ind[MAXN];

int tem[MAXN][2], quer[MAXN][2], err[MAXN];
vector<int> adj[MAXN];

void go(int u, int pai){
   p[u] = pai; 
   for(int nxt:adj[u]){
       if(nxt == pai) continue;
       go(nxt, u);
   }
}

bool cmp(int a, int b){
    return c[a] < c[b];
}


void solve(int u){
    if(err[u] != -1) return ; // ja solvou

    err[u] = !(s[u] == g[u]);
    //tem[u][1-s[u]] = 0;
    quer[u][1-g[u]] = 0;
    if(err[u]){
        //tem[u][s[u]] = 1;
        quer[u][g[u]] = 1;
    }
    else{
        //tem[u][s[u]] = 0;
        quer[u][g[u]] = 0;
    }
    for(int nxt: adj[u]){
        if(nxt == p[u]) continue;
        solve(nxt);
        err[u] += err[nxt];
        for(int t=0;t<2;t++){
            //tem[u][t] += tem[nxt][t];
            quer[u][t] += quer[nxt][t];
        }
    }
}


int main (){
    memset(err, -1, sizeof(err));
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
        scanf("%lld%d%d", c+a, s+a, g+a);
        ind[a] = a;
	}
    for(int a=1;a<n;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        adj[i].pb(j);
        adj[j].pb(i);
    }
    go(1, 1);

    ll ans = 0;
    sort(ind+1, ind+n+1, cmp);
    for(int a=1;a<=n;a++){
        int u = ind[a];
        if(err[u] == -1){
            solve(u);
            int chg = min(quer[u][0], quer[u][1]);
            //printf("resolve u %d quer 0 %d quer 1 %d entao chf %d\n", u, quer[u][0], quer[u][1], chg);
            ans += c[u]*2ll*chg;
            quer[u][0] -= chg;
            quer[u][1] -= chg;
        }
    }
    if(quer[1][0] == 0 && quer[1][1] == 0)
        printf("%lld\n", ans);
    else
        puts("-1");
}

