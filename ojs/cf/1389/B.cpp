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

const int MAXN = 102345;

int n, m, z;
int k;
ll s[MAXN];
ll dp[MAXN][6][2];

ll go(int i, int l, bool lstLeft){
    ll &r = dp[i][l][lstLeft];
    if(r != -1)
        return r;
    if(i + (z - l)*2 == k)
        return r = 0;
    r= 0;
    if(i+1 < n)
        r = max(r, go(i+1, l, 0) + s[i+1]);
    if(i && l && !lstLeft)
        r = max(r, go(i-1, l-1, 1) + s[i-1]);
    return r;
}

int main (){
    for_tests(t, tt){
        scanf("%d%d%d", &n, &k, &z);
        for(int a=0;a<=n;a++){
            for(int b=0;b<=5;b++){
                for(int c=0;c<2;c++){
                    dp[a][b][c] = -1;
                }
            }
        }
        for(int a=0;a<n;a++)
            scanf("%lld", s+a);
        printf("%lld\n", s[0] + go(0, z, 0));
    }

}
