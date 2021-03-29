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
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

ll n;

ll sum(ll x){
    ll res = 0;
    while(x > 0){
        res += x%10;
        x /= 10;
    }
    return res;
}

ll gcd(ll a, ll b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main (){
    for_tests(t, tt){
        scanf("%lld", &n);
        while(gcd(n, sum(n)) == 1)
            n++;
        printf("%lld\n", n);
    }
    return 0;
}

