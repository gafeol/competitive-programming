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

const int MAXN = 5123;
const int INF = 0x3f3f3f3f;

int n, m, k;
ll s[MAXN];

ll dp[MAXN][MAXN];

ll go(int i, int sub){
    if(sub >= MAXN) return INF;    
    ll &r = dp[i][sub];
    if(r != -1)
        return r;
    if(i == n) 
        return r = 0;
    r = INF;

    if(s[i] <= sub){
        r = min(r, go(i+1, s[i]));
    }
    else{
        r = min(r, go(i+1, s[i]) + s[i] - sub);
        r = min(r, go(i+1, sub) + 1);
    }
    return r;
}

int main (){
    memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%lld", s+a);
	}
    printf("%lld\n", go(0, 0));
}

