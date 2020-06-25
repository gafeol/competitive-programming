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
const ll modn = 998244353;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

ll n, m, k;
ll f(ll sz){
    if(sz&1)
        return 1;
    else
        return sz/2ll + 1;
}

ll expo(ll base, ll e){
    if(e == 0) return 1;
    ll ans = expo(base, e/2);
    ans = mod(ans*ans);
    if(e&1)
        ans = mod(ans*base);
    return ans;
}

int main (){
    for_tests(t, tt){
        scanf("%lld%lld", &n, &m);
        ll k = 1;
        ll pot = 0;
        while(log(k) + log(m) + 1e-8 < log(LLONG_MAX)){
            k *= m;
            pot++;
        }

        ll ate = 0, nsq = 0;
        ll tam = 0, nw = 1;
        while(k >= 1){
            ate += nsq;
            assert(ate <= n && nsq <= n);
            ll newSq = n/k - ate;
            //printf("qtd de caminhos com tam >= %d eh %lld\n", pot+1, newSq);
            tam += newSq*((pot+2)/2ll);
            nw = mod(nw*expo(f(pot+1),newSq));
            ate += newSq;
            nsq += newSq;
            //printf("tam %lld nw %lld\n", tam, nw);
            k /= m;
            pot--;
        }
        printf("%lld %lld\n", tam, nw);
    }
}
