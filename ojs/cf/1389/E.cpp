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

ll m, d, w;

ll gcd(ll a, ll b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

ll f(ll x){
    if(x <= 1) return 0;
    return (x*(x-1))/2;
}

int main (){
    for_tests(t, tt){
        scanf("%lld%lld%lld", &m, &d, &w);
        w = w/gcd(d-1, w);
        ll rem = (min(d, m)-1)%w;
        ll q = (min(d, m)-1)/w;
        ll ans = (rem+1)*f(q + 1)
                    + (w-1-rem)*f(q);
        printf("%lld\n", ans);
    }
}

