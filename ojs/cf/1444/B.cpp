#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 312345;

int n, m, k;
int s[MAXN];

ll expo(ll b, ll e){
    ll ans = 1;
    ll pot = b;
    while(e){
        if(e&1)
            ans = mod(ans*pot);
        pot = mod(pot*pot);
        e >>= 1;
    }
    return ans;
}

ll f[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<2*n;a++){
        f[a] = (a > 0 ? mod(a*f[a-1]) : 1);
        scanf("%d", s+a);
	}
    sort(s, s+2*n);
    f[2*n] = mod(2*n*f[2*n-1]);
    ll res = 0;
    for(int a=0;a<n;a++)
        res = mod(res - s[a]); 
    for(int a=n;a<2*n;a++)
        res = mod(res + s[a]);
    res = mod(modn + res);
    res = mod(res*f[2*n]);
    ll e = expo(f[n], modn-2);
    res = mod(mod(res*e)*e);
    printf("%lld\n", res);
    return 0;
}
