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

ll n, m, k;

ll S(ll x){
    return ((1 + x)*x)/2;
}

int main (){
    for_tests(t, tt){
        scanf("%lld", &n);
        ll sum = S(n);
        if(sum&1){
            puts("0");
            continue;
        }
        ll ans = 0;
        ll xx = (-1 + sqrt(1 + 4*sum))/2;
        ll del = 6;
        for(ll x=max(1ll, xx-del);x<=min(n, xx+del);x++){
            ll sbef = S(x);   
            if(sbef == sum/2){
                ans += S(x-1) + S(n-x - 1);
            }
            else{
                ll dif = sum/2 - sbef;
                if(dif < 0) continue;
                ll i = max(1ll, x+1-dif);
                ll j = min(n, x+dif) - dif;
                ans += max(0ll, (j - i + 1));
            }
        }
        printf("%lld\n", ans);
    }
}

