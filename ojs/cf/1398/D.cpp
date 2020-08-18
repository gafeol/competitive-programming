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

const int MAXN = 212;

int n, m, k;
ll s[3][MAXN];

ll dp[MAXN][MAXN][MAXN];

ll go(int i, int j, int h){
    ll &r = dp[i][j][h];
    if(r != -1)
        return r;
    r = 0;
    if(i < n && j < m)
        r = max(r, go(i+1, j+1, h) + s[0][i]*s[1][j]);
    if(i < n && h < k)
        r = max(r, go(i+1, j, h+1) + s[0][i]*s[2][h]);
    if(j < m && h < k)
        r = max(r, go(i, j+1, h+1) + s[1][j]*s[2][h]);
    return r;
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
	for(int a=0;a<n;a++)
        scanf("%lld", s[0]+a);
    for(int a=0;a<m;a++)
        scanf("%lld", s[1]+a);
    for(int a=0;a<k;a++)
        scanf("%lld", s[2]+a);
    sort(s[0], s[0]+n, greater<int>());
    sort(s[1], s[1]+m, greater<int>());
    sort(s[2], s[2]+k, greater<int>());
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", go(0,0,0));
}

