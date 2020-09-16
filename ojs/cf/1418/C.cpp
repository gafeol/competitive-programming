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
int s[MAXN];
int dp[MAXN][2];

int go(int i, int t){
    if(i == n)
        return 0;

    int &r = dp[i][t];
    if(r != -1)
        return r;
    r = INT_MAX;

    r = min(r, go(i+1, t^1) + (t == 0 && s[i] == 1));
    if(i + 2 <= n)
        r = min(r, go(i+2, t^1) + (t == 0 && s[i] == 1) + (t == 0 && s[i+1] == 1));
    return r;
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
            dp[a][0] = dp[a][1] = -1;
        }
        printf("%d\n", go(0, 0));
    }
}

