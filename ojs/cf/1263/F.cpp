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

const int MAXN = 2003;

int n, m[2], k;
int s[2][MAXN];

int liga[MAXN];

vector<int> adj[MAXN];
int lca[MAXN][MAXN];
int h[MAXN];

int c[2][MAXN][MAXN];

pii go(int u, int p=1){
    pii res = {INT_MAX, INT_MIN};
    h[u] = h[p]+1;
    if(liga[u] != 0)
        res.fst = res.snd = liga[u];
    vector<pii> segs;
    for(int nxt: adj[u]){
        pii aux = go(nxt, u); 
        segs.pb(aux);
        res.fst = min(res.fst, aux.fst);
        res.snd = max(res.snd, aux.snd);
    }
    sort(segs.begin(), segs.end());
    for(pii p: segs){
        for(int a=p.fst;a<=p.snd;a++){
            for(int b=p.snd+1;b<=res.snd;b++){
                //printf("set lca %d %d to %d\n", a, b, u);
                lca[a][b] = u;
                lca[b][a] = u;
            }
        }
    }
    return res;
}

int dp[MAXN][2][MAXN];

int pd(int i, int t, int l){
    if(i == n+1)
        return 0;
    int &r = dp[i][t][l];
    if(r != -1)
        return r;
    int l1, l2;
    if(t == 0){
        l1 = i-1;
        l2 = l;
    }
    else{
        l1 = l;
        l2 = i-1;
    }
    r = min(pd(i+1, 0, (!t ? l : i-1)) + c[0][l1][i], pd(i+1, 1, (t ? l : i-1)) + c[1][l2][i]);
    //printf("pd %d %d %d : %d = min(pd(%d %d) %d + %d, pd(%d, %d) %d + %d)\n", i, l1, l2, r, i+1, i, pd(i+1, i), c[0][l1][i], i+1, l1, pd(i+1, l1), c[1][l2][i]);
    return r;
}

int main (){
    memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
    for(int t=0;t<2;t++){
        scanf("%d", &m[t]);
        for(int a=0;a<=m[t];a++){
            liga[a] = 0;
            adj[a].clear();
            lca[0][a] = 1;
        }
        for(int a=0;a<m[t]-1;a++){
            int x;
            scanf("%d", &x);
            adj[x].pb(a+2);
        }
        for(int a=1;a<=n;a++){
            scanf("%d", &s[t][a]);
            liga[s[t][a]] = a;
        }
        h[0] = 0;
        h[1] = -1;
        go(1);
        for(int a=0;a<=n;a++){
            for(int b=a+1;b<=n;b++){
                int ua = s[t][a], ub = s[t][b], lc = lca[a][b];
                c[t][a][b] = h[ub] - h[lc];
                //printf("c t %d a %d (ua %d) b %d (ub %d) lca %d: %d (%d - %d)\n", t, a, ua, b, ub, lc, c[t][a][b], h[ub], h[lc]);
            }
        }
    }
    printf("%d\n", m[0] + m[1] - 2 - pd(1, 0, 0)); 
}
