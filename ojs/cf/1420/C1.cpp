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

const int MAXN = 312345;

int n, m, k;
int s[MAXN];

ll dp[MAXN][2];

ll go(int i, int t){
    ll &r = dp[i][t];
    if(r != -1)
        return r;
    if(i == n)
        return r = 0;
    r = max(r, go(i+1, t));
    r = max(r, go(i+1, 1-t) + (t ? -1:1)*s[i]);
    return r;
}

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        for(int a=0;a<=n;a++){
            for(int b=0;b<2;b++){
                dp[a][b] = -1;
            }
        }
        for(int a=0;a<n;a++)
            scanf("%d", s+a);
        printf("%lld\n", go(0, 0));
    }
}

