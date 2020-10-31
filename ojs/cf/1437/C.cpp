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

const int MAXT = 412;
const int MAXN = 212;
const int INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];

int dp[MAXN][MAXT];

int go(int i, int t){
    if(t == MAXT)
        return INF;
    int &r = dp[i][t];
    if(r != -1)
        return r;
    if(i == n)
        return r = 0;
    r = INF;
    r = min(r, go(i, t+1));
    r = min(r, go(i+1, t+1) + abs(s[i] - t));
    return r;
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
        }
        sort(s, s+n);
        memset(dp, -1, sizeof(dp));
        printf("%d\n", go(0, 1));
    }
    return 0;
}

