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

const int MAXN = 212345;

ll n, m, k, x, y;
int s[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%lld%lld", &x, &y);
        scanf("%lld%lld", &n, &m);
        m = min(m, 2ll*n);
        ll res = LLONG_MAX; 
        res = min(res, abs(x - y)*n + min(abs(x), abs(y))*m);
        res = min(res, abs(x)*n + abs(y)*n);
        printf("%lld\n", res);
    }
}

