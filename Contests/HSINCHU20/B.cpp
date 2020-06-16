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
int dp[MAXN][3];

void go(int u, int p){
    int s0 = 0, s1 = 0;
    int cnt = 0;
    for(int i=0;i<adj[u].size();i++){
        if(adj[u][i] == p){
            swap(adj[u][i], adj[u][adj[u].size()-1]);
            adj[u].pop_back();
            break;
        }
    }
    for(int nxt: adj[u]){
        cnt++;
        go(nxt, u);
        s0 += dp[nxt][0];
        s1 += dp[nxt][1];
    }
    dp[u][0] = 1+s0;
    dp[u][1] = 1+s0;
    dp[u][2] = 1+s0;
    if(cnt <= 1)
        dp[u][0] = min(dp[u][0], s0);
    if(cnt == 1){
        dp[u][1] = min(dp[u][1], dp[adj[u][0]][1]); 
    }
    if(cnt >= 1)
        dp[u][1] = min(dp[u][1], s1);

    if(cnt){
        int bst2 = adj[u][0];
        for(int nxt: adj[u]){
            if(dp[nxt][2] - dp[nxt][1] < dp[bst2][2] - dp[bst2][1])
                bst2 = nxt;
        }
        for(int nxt: adj[u]){
            dp[u][0] = min(dp[u][0], s1 + dp[nxt][0] - dp[nxt][1]);
            if(nxt != bst2)
                dp[u][0] = min(dp[u][0], s1 + dp[bst2][2] - dp[bst2][1] + dp[nxt][0] - dp[nxt][1]); 
        }
        for(int nxt: adj[u]){
            if(nxt != bst2)
                dp[u][0] = min(dp[u][0], s1 + dp[bst2][0] - dp[bst2][1] + dp[nxt][2] - dp[nxt][1]);
        }
    }
    dp[u][2] = min(dp[u][2], 1 + min(dp[u][0], dp[u][1]));
    dp[u][1] = min(dp[u][1], min(1+dp[u][0], dp[u][2]));
    dp[u][0] = min(dp[u][0], min(dp[u][1], dp[u][2]));
    printf("go %d dps %d %d %d\n", u, dp[u][0], dp[u][1], dp[u][2]);
}


int main (){
    memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int a=1;a<n;a++){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
	}
    go(1, 1);
    printf("%d\n", min(1 + dp[1][0], min(dp[1][1], dp[1][2])));
}

