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

const int MAXN = 212345;

ll n, m, k;
int s[MAXN];

ll chk(ll base, ll e){
    if(e == 0)
        return 1ll;
    ll ans = chk(base, e/2ll);
    ans = mod(ans*ans);
    if(e&1)
        ans = mod(ans*base);
    return ans;
}

ll expo(ll base, ll e){
    ll ob = base, oe = e;
    ll ans = 1;
    do{
        if(e&1ll)
            ans = mod(ans*base);
        base = mod(base*base);
    } while((e = (e >> 1ll)));
    assert(ans == chk(ob, oe));
    return ans;
}

ll inv(ll a){
    return expo(a, modn-2ll);
}

ll fat[MAXN];

ll choose(ll a, ll b){
    assert(a >= b);
    return mod(mod(fat[a]*inv(fat[b]))*inv(fat[a-b]));
}

int main (){
	scanf("%lld%lld", &n, &k);
    fat[0] = 1ll;
    for(ll a=1;a<=n;a++)
        fat[a] = mod(fat[a-1]*a);
	for(int a=0;a<n;a++)
        scanf("%d", s+a);
    ll dif = 0;
    for(int a=0;a<n;a++){
        int prv = (a + n - 1)%n;
        dif += (s[prv] != s[a]);
    }
    ll ans = 0;
    for(ll g = 0;2ll*g <= dif;g++){
        ll eq = expo((k-2ll), dif - 2ll*g);
        ans = mod(ans + mod(mod(eq*choose(dif, g))*choose(dif-g, g)));
    }
    ans = mod(ans*expo(k, n - dif));
    ll res = mod(expo(k, n) - ans);
    res = mod(res + modn);
    res = mod(res*inv(2));
    //printf("res %lld\n", res);
    printf("%lld\n", res);
}

