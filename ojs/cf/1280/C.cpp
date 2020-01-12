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

unordered_map<int, int> dp[MAXN];
vector<int> adj[MAXN];

int go(int i, int p){
    if(dp[i].find(p) != dp[i].end())
        return dp[i][p];
    dp[i][p] = 1;
    for(int nxt: adj[i]){
        if(nxt == p) continue;
        dp[i][p] += go(nxt, i);
    }
    return dp[i][p];
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        vector<tuple<int, int, int> > ed;
        for(int a=0;a<=2*n;a++){
            adj[a].clear();
            dp[a].clear();
        }
        for(int a=0;a<2*n-1;a++){
            int i, j;
            scanf("%d%d%d", &i, &j, &k);
            adj[i].pb(j);
            adj[j].pb(i);
            ed.pb({i, j, k});
        } 
        ll ans = 0;
        ll sum = 0;
        for(tuple<int, int, int> tp: ed){
            int i, j, k;
            tie(i, j, k) = tp;
            if(dp[i].find(j) != dp[i].end()){
                ans += ((ll)k)*((ll)min(dp[i][j], 2*n - dp[i][j]));
                if(dp[i][j]&1)
                    sum += k;
            }
            else if(dp[j].find(i) != dp[j].end()){
                ans += ((ll)k)*((ll)min(dp[j][i], 2*n - dp[j][i]));
                if(dp[j][i]&1)
                    sum += k;
            }
            else{
                go(i, j);
                go(j, i);
                ans += ((ll)k)*((ll)min(dp[j][i], 2*n - dp[j][i]));
                if(dp[j][i]&1)
                    sum += k;
            }
        }
        printf("%lld %lld\n", sum, ans);
    }
}

