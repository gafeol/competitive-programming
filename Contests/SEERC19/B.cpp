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

const int MAXN = 501;
int n, m, k;
int s[MAXN];

ll dp[MAXN][2*MAXN][MAXN];
ll s1, s2;

ll x[MAXN];
ll t[MAXN];
ll y[MAXN];
ll r[MAXN];
int ind[MAXN];

ll go(int ii, int e1, int e2){
    e1 = max(0, e1);
    e2 = max(0, e2);
    ll &R = dp[ii][e1][e2];
    if(R != -1)
        return R;
    if(e1 == 0 && e2 == 0)
        return R = 0;
    int i = ind[ii];
    if(e1 >= s1 && e1 - x[i] < s1){
        R = min(R, t[i] + go(ii+1, e1-x[i], e2));
    }
    if(e1 < s1)
        R = min(R, t[i] + go(ii+1, e1-x[i], e2));
    R = min(R, r[i] +  go(ii+1, e1, e2-y[i]));
    return R;
}

int main (){
	scanf("%d%lld%lld", &n, &s1, &s2);
	for(int a=0;a<n;a++){
        ind[a] = a;
        scanf("%lld%lld%lld%lld", x+a, t+a, y+a, r+a);
	}
    sort(ind, ind+n, [](int a, int b){ return x[a] > x[b]; });
    memset(dp, -1, sizeof(dp));
    ll ans = LLONG_MAX;
    for(ll ex = 0;ex <= s2;ex++){
        ans = min(ans, go(0, s1+ex, s2));
    }
    printf("%lld\n", ans);
}
