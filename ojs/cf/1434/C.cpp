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

ll d, h, dh, cd;

ll f(ll i){
    if(i < 0) return 0;
    return (i+1)*d - (((i+1)*i)/2)*h*cd;
}

int main (){
    for_tests(t, tt){
        scanf("%lld%lld%lld%lld", &d, &h, &dh, &cd);
        if(d > h*dh){
            puts("-1");
            continue;
        }
        if(cd >= dh){
            printf("%lld\n", d);
            continue;
        }
        ll ans = 0;

        int i = (2*d/(h*cd) - 1)/2;

        ans = max(f(i), max(f(i-1), f(i+1)));
        printf("%lld\n", ans);
    }
}

