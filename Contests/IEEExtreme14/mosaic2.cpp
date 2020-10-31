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

const int MAXN = 212345;

ll w, h, a, b, m, c;
int main (){
    scanf("%lld%lld%lld%lld%lld%lld", &w, &h, &a, &b, &m, &c);
    ll need = ((w + a-1)/a) * ((h + b-1)/b);
    ll ans = (need + 9)/10 * m;
    if(w%a != 0)
        ans += h*c;
    if(h%b != 0)
        ans += w*c;
    printf("%lld\n", ans);
    return 0;
}

