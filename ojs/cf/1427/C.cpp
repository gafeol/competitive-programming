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

int main (){
    int r, n;
	scanf("%d%d", &r, &n);
    vector<tuple<int, int, int>> s(n+1);
    int mx = INT_MIN;
    int ans = 0;
    vector<int> dp(n+1, INT_MIN);
    dp[0] = 0;
    s[0] = {0, 1, 1};
	for(int a=1;a<=n;a++){
        int t, i, j;
        scanf("%d%d%d", &t, &i, &j);
        s[a] = {t, i, j};
        if(a-2*r >= 0)
            mx = max(mx, dp[a-2*r]);
        dp[a] = mx + 1;
        for(int b=a-1;b>a-2*r && b>=0;b--){
            auto [ot, oi, oj] = s[b];
            if(t - ot >= abs(oi -i) + abs(oj - j)){
                //printf("%d >= %d + %d : dp[%d] = ma(%d, %d + 1)\n", t - ot, abs(oi - i), abs(oj - j), a, dp[a], dp[b]);
                dp[a] = max(dp[a], dp[b] + 1);
            }
        }
        //printf("dp[%d] %d\n", a, dp[a]);
        ans = max(ans, dp[a]);
	}
    printf("%d\n", ans);
}

