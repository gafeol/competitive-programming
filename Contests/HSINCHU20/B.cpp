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

const int INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];

vector<int> adj[MAXN];
int p[MAXN];

void dfs(int u){
    for(int nxt: adj[u]){
        if(nxt == p[u]) continue;
        p[nxt] = u;
        dfs(nxt);
    }
}

int dp[MAXN][3][3];

int go(int u, int pg, int ppg){
    //printf("go u %d pg %d ppg %d\n", u, pg, ppg);
    int &r = dp[u][pg][ppg];
    if(r != -1)
        return r;
    r = INF;

    int cnt = 0;
    int s[2][2];
    memset(s, 0, sizeof(s));
    for(int nxt: adj[u]){
        if(nxt == p[u]) continue;
        cnt++;

        for(int t=0;t<2;t++){
            for(int tt=0;tt<2;tt++){
                if(t == 1 && tt == 0) continue;
                s[t][tt] += go(nxt, t, tt);
            }
        }
        //mxpg = max(mxpg, go(nxt, 1));
        //mxn = max(mxn, go(nxt, 0));
    }
    if(cnt == 0){
        if(pg == 0)
            return r = 1;
        else
            return r = 0;
    }

    r = min(r, 1 + s[1][1]);
    //printf("vou calc u %d pg %d ppg %d\n", u, pg, ppg);
    if(!pg){
        if(!ppg){
            r = min(r, s[0][0]); 
        }
        else{
            for(int nxt: adj[u]){
                if(nxt == p[u]) continue;
                r = min(r, go(nxt, 1, 1) + s[0][0] - go(nxt, 0, 0));
            } }
    }
    else{
        if(!ppg){
            // n eh possivel
            assert(false);
        }
        else{
            for(int nxt: adj[u]){
                if(nxt == p[u]) continue;
                r = min(r, go(nxt, 1, 1) + s[0][1] - go(nxt, 0, 1));
            }
        }
    }
    return r;
}


int main (){
    memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
    int mx = 0;
	for(int a=1;a<n;a++){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
        mx = max(mx, (int)adj[u].size());
        mx = max(mx, (int)adj[v].size());
	}
    p[1] = 1;
    dfs(1);
    printf("%d\n", go(1, 0, 1));
}

