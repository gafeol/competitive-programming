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
const ll modn = 998244353;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 512;

int n, m, k;
int s[MAXN];

ll dp[MAXN][MAXN];

ll go(int i, int j){
    if(i >= j) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    int mn = INT_MAX, mnp;
    for(int a=i;a<=j;a++){
        mn = min(mn, s[a]);
        if(mn == s[a])
            mnp = a;
    }

    ll &res = dp[i][j];
    res = 0;
    ll left = 0;
    
    for(int a=i-1;a<mnp;a++)
        left = mod(left + mod(go(i, a) * go(a+1, mnp-1)));
    for(int a=mnp;a<=j;a++)
        res = mod(res + mod(mod(go(mnp+1, a) * go(a+1, j))*left));

    return res;
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
	}
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", go(0, n-1));
}

