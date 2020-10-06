#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
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

const int LOGN = 61;

int n, m, k;
int dp[LOGN][7];
int upt[LOGN][7], tempo;

map<ll, int> ans;

inline void clean(int i, int s){
    if(upt[i][s] != tempo){
        upt[i][s] = tempo;
        dp[i][s] = 0;
    }
}

vector<int> vals[] = { {0, 2, 4, 6}, {1, 3, 5, 7}};


int main (){
    for_tests(t, tt){
        tempo++;
        ll x;
        scanf("%lld", &x);
        /*
        if(ans.find(x) != ans.end()){
            printf("%d\n", ans[x]);
            continue;
        }
        dp[0][0] = 1;
        upt[0][0] = tempo;
        int ate = 63 - __builtin_clzll(x) + 1;
        for(int i=0;i<ate;i++){
            int b = ((x>>i)&1);
            for(int sob=0;sob<7;sob++){
                clean(i, sob);
                if(dp[i][sob] == 0) continue;
                for(int v: vals[b]){
                    int nsob = ((v + sob)>>1);
                    clean(i+1, nsob);
                    dp[i+1][nsob] = mod(dp[i+1][nsob] + dp[i][sob]);
                }
                b ^= 1;
            }
        }
        ans[x] = dp[ate][0];
        printf("%d\n", dp[ate][0]);
        */
        ll A = x/2ll;
        if(A&1){
            printf("%lld\n", mod(mod(A/2+1ll)*mod(A/2+2ll)));
        }
        else{
            printf("%lld\n", mod(mod(A/2+1)*mod(A/2+1)));
        }
    }
}

