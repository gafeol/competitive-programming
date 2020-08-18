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

ll n, k, d, x;

int main (){
    scanf("%lld %lld%lld", &x, &k, &d);
    if(x > 0){
        if(x/d > k){
            x = x - d*k;
            k = 0;
        }
        else{
            ll nk = k - (x/d);
            x = x - d*(x/d);
            k = nk;
            if(k&1)
                x = x - d;
        }
    }
    else{
        if(abs(x/d) > k){
            x = x + d*k;
            d = 0;
        }
        else{
            ll nk = k - (x/d);
            x = x - d*(x/d);
            k = nk;
            if(k&1)
                x = x + d;
        }
    }
    printf("%lld\n", abs(x));
}

