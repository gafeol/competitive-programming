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

const int MAXN = 2123456;

ll n[MAXN][3];
ll dp[MAXN];

int main (){

    dp[1] = 0;
    n[1][0] = 1;
    n[1][1] = 0;
    n[1][2] = 0;
    dp[2] = 0;
    n[2][0] = 1;
    n[2][1] = 1;
    n[2][2] = 0;
    dp[3] = 4;
    n[3][0] = 3;
    n[3][1] = 1;
    n[3][2] = 1;
    for(int a=4;a<MAXN;a++){
        ll n0 = mod(n[a-1][0] + n[a-1][1]*2);
        ll n1 = n[a-1][0];
        ll n2 = mod(n[a-1][2] + n[a-1][1]);
        dp[a] = mod(4*n[a-2][0] + dp[a-3]);
        n[a][0] = n0;
        n[a][1] = n1;
        n[a][2] = n2;
    }
    for_tests(t, tt){
        ll x;
        scanf("%lld", &x);
        printf("%lld\n", dp[x]);
    }
}

