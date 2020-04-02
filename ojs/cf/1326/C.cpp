
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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

ll dp[MAXN][2];

ll go(int i, bool ok){
    ll &r = dp[i][ok];
    if(i == n) return r = ok;
    if(r != -1) return r; 
    if(s[i] > n-k){
        if(ok)
            r = 0;
        else
            r = mod(go(i+1, true) + go(i+1, false));
    }
    else{
        if(ok)
            r = mod(go(i+1, false) + go(i+1, true));
        else
            r = go(i+1, false);
    }
    //debug("go %d %d : %lld\n", i, ok, r);
    return r;
}

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
	}
    printf("%lld ", (((ll)k)*((ll)n - k + 1 + n))/2ll);
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", go(0, 0));
}

