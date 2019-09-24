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

// gcd(a, b) = a*x + b*y
ll gcd(ll a, ll b, ll &x, ll &y){
    if (a == 0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return d;
} 

int main (){
    for_tests(t, tt){
        ll a, b, n, m;
        scanf("%lld%lld%lld%lld", &a, &n, &b, &m);
        assert(a < n && b < m);
        if(n == m && a != b){
            puts("no solution");
            continue;
        }
        ll x, y;
        ll gc = gcd(n, m, x, y); 

        if(abs(a-b)%gc != 0){
            puts("no solution");
            continue;
        }
        ll mmc = (n/gc)*m;
        ll res = (a + n*(((b-a)*x)/gc % (m/gc)))%mmc; 
        res = (res + mmc)%mmc;
        debug("res %lld, res mod n %lld  res mod m %lld\n", res, res%n, res%m);
        assert(res%n == a);
        assert(res%m == b);
        printf("%lld %lld\n", res, mmc);
    }
}
