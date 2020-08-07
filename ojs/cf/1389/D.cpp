#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

int n, m;
ll k;

bool in(pll u, pll v){
    return (u.fst >= v.fst && u.snd <= v.snd);
}

ll inter(pll u, pll v){
    if(in(u, v))
        return u.snd - u.fst;
    if(in(v, u))
        return v.snd - v.fst;
    if(u.fst > v.fst)
        swap(u, v);
    return max(0ll, u.snd - v.fst);
}

ll dis(pll u, pll v){
    if(in(u, v) || in(v, u) || inter(u, v) > 0)
        return 0;
    if(u.fst > v.fst)
        swap(u, v);
    return (v.fst - u.snd);
}

int main (){
    for_tests(t, tt){
        scanf("%d%lld", &n, &k);
        pll l, r;
        scanf("%lld%lld", &l.fst, &l.snd);
        scanf("%lld%lld", &r.fst, &r.snd);
        ll ans = LLONG_MAX;
        ll d = dis(l, r);
        k -= inter(l, r)*((ll)n);
        if(k <= 0){
            puts("0");
            continue;
        }
        for(ll q=1;q<=n;q++){
            ll cus = d*q;
            ll store = (max(r.snd, l.snd) - min(l.fst, r.fst) - inter(l, r))*q;
            if(k <= store){
                ans = min(ans, cus + k); 
            }
            else{
                ans = min(ans, cus + store + (k - store)*2ll); 
            }
        }
        printf("%lld\n", ans);
    }
}

