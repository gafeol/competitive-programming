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

const int MAXN = 1123;
const int INF = 0x3f3f3f3f;

int n, m, k;
char s[MAXN];
int dp[MAXN][2];
int v[2];

int val(int i, int j){
    if((i^j) == 1)
        return v[i];
    return 0;
}

int go(int i, int prv){
    int &r = dp[i][prv];
    if(r != INF)
        return r;
    if(i == n)
        return r = 0;

    if(i == 0) prv = 2;

    if(s[i] == '?'){
        r = min(r, val(prv, 0) + go(i+1, 0));
        r = min(r, val(prv, 1) + go(i+1, 1));
    }
    else 
        r = min(r, val(prv, (s[i] == 'J')) + go(i+1, (s[i] == 'J')));
    return r;
}

int main (){
    for_tests(t, tt){
        scanf("%d%d", v, v+1);
        scanf(" %s", s);
        n = strlen(s);
        memset(dp, INF, sizeof(dp));
        printf("Case #%d: %d\n", tt, go(0, 0)); 
    }
    return 0;
}

