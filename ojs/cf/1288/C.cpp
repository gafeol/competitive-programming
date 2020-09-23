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

const int MAXN = 1123;

int n, m, k;
int s[MAXN];

ll dp[MAXN][12];

ll go(int n, int i=0){
    ll &r = dp[n][i];
    if(r != -1)
        return r;
    if(n == 0)
        return r = 0;
    if(i == m)
        return r = 1;
    r = 0;
    r = mod(r + go(n-1, i));
    r = mod(r + go(n, i+1));
    return r;
}

int main (){
    memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &m);
    ll ans = 0;
	for(int a=1;a<=n;a++){
        ans = mod(ans + mod(go(a)*go(n-a+1)) - mod(go(a)*go(n-a)));
	}
    ans = mod(modn + ans);
    printf("%lld\n", ans);
}

