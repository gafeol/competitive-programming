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
ll s[MAXN];

int onxt[MAXN];
vector<int> nxt[MAXN];
ll dp[MAXN];

ll go(int u){
    dp[u] = s[u];
    for(int nx: nxt[u]){
        go(nx); 
        if(dp[nx] > 0)
            dp[u] += dp[nx];
    }
    return dp[u];
}

void re(int u){
    for(int nx: nxt[u]){
        if(dp[nx] > 0)
            re(nx);
    }
    printf("%d ", u+1);
    for(int nx: nxt[u]){
        if(dp[nx] <= 0)
            re(nx);
    }
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%lld", s+a);
	}
    for(int a=0;a<n;a++){
        scanf("%d", &onxt[a]);
        if(onxt[a] >= 0){
            onxt[a]--;
            nxt[onxt[a]].pb(a);
        }
    }

    for(int a=0;a<n;a++){
        if(onxt[a] == -1){
            go(a);
        }
    }

    ll res = 0;
    for(int a=0;a<n;a++){
        res += dp[a];
    }
    printf("%lld\n", res);
    for(int a=0;a<n;a++){
        if(onxt[a] == -1)
            re(a);
    }
    puts("");
}

