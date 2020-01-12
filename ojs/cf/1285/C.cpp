#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pll;
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

const int MAXN = 1123456;

ll gcd(ll a, ll b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

ll n;
int main (){
    scanf("%lld", &n);
    pll res = {LLONG_MAX, LLONG_MAX};
    for(ll a=1;a<=sqrt(n)+2 && a <= n;a++){
        ll b = n/a; 
        if(a*b == n && gcd(a, b) == 1){
            res = min(res, {max(a, b), min(a, b)});
        }
    }
    printf("%lld %lld\n", res.snd, res.fst);
}

