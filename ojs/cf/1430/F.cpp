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

const int MAXN = 2123;

const ll INF = (ll)1e14;

int n, m, k;
ll s[MAXN], l[MAXN], R[MAXN];
ll acc[MAXN];

ll dp[MAXN][MAXN][2];

ll go(int i, int lstR, bool fim){
    ll &r = dp[i][lstR][fim];
    if(r != -1)
        return r;
    r = INF;
    if(i == n+1)
        return r = 0; 

    ll mo = acc[i-1] - acc[lstR];
    ll left = k - mo%k;
    ll t = (s[i] <= left ? 0 : (s[i]-left+k-1)/k);
    ll sob = t*k + left - s[i];
    int blckFst = (fim && R[i-1] == l[i]);
    //printf("go i %d lst R %d sob %lld t %lld blckFst %d\n", i, lstR, sob, t, blckFst);
    if(l[i] + t  + blckFst > R[i])
        return r = INF;
    r = min(r, go(i+1, lstR, ((s[i] - left)%k == 0 && l[i] + t + blckFst == R[i])));
    if(i < n && l[i] + t + blckFst <= R[i])
        r = min(r, go(i+1, i, (l[i] + t + blckFst == R[i])) + sob);
    //printf("go %d %d %lld\n", i, lstR, r);
    return r;
}

int main (){
	scanf("%d%d", &n, &k);
	for(int a=1;a<=n;a++){
        scanf("%lld%lld%lld", l+a, R+a, s+a);
        acc[a] = s[a] + acc[a-1];
	}
    memset(dp, -1, sizeof(dp));
    ll res = acc[n] + go(1, 0, 0);
    if(res < INF)
        printf("%lld\n", acc[n] + res);
    else
        puts("-1");
}

