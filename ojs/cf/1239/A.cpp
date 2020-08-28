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

ll dp[MAXN][2][2];

ll go(int i, bool lst=false, bool ja=false){
    ll &r = dp[i][lst][ja];
    if(r != -1)
        return r;
    if(i == m)
        return r = 1;

    r = 0;
    // bota false em i
    if(lst == true || ja == false || i <= 1)
        r = mod(r + go(i+1, false, (lst == false)));
    // bota true
    if(lst == false || ja == false || i <= 1)
        r = mod(r + go(i+1, true, (lst == true)));
    return r;
}

ll dp2[MAXN][2];
ll go2(int i, bool ig=false){
    ll &r = dp2[i][ig];
    if(r != -1)
        return r;
    if(i == n)
        return r = 1;
    r = 0;
    r = mod(r + go2(i+1, false));
    if(!ig)
        r = mod(r + go2(i+1, true));
    return r;
}

int main (){
	scanf("%d%d", &n, &m);
    memset(dp, -1, sizeof(dp));
    ll num = go(0);
    //printf("num %lld\n", num);
    ll ans = num-2;
    memset(dp2, -1, sizeof(dp2));
    ll j1 = go2(0);
    //printf("j1 %lld\n", j1);
    ans = mod(ans + 2*go2(0, true));
    printf("%lld\n", ans);
}

