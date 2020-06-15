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

const int MAXN = 512345;


ll expo(ll base, ll e){
    if(e == 0)
        return 1ll;
    ll ans = expo(base, e/2ll);
    ans= mod(ans*ans);
    if(e&1)
        ans = mod(ans*base);
    return ans;
}

int n, m, k;
ll fat[MAXN];

ll inv(ll x){
    return expo(x, modn-2);
}
ll ch(ll a, ll b){
    return mod(mod(fat[a]*inv(fat[b]))*inv(fat[a-b]));
}

int main (){
	scanf("%d%d", &n, &k);
    if(n < k){
        puts("0");
        return 0;
    }
    fat[0] = 1;
    for(ll a=1;a<=n;a++){
        fat[a] = mod(fat[a-1]*a); 
    }
    ll res = 0;
    for(ll a=1;a<=n;a++){
        ll mul = n/a; 
        if(mul < k) break;
        res = mod(res + ch(mul-1, k-1));
    }
    printf("%lld\n", res);
}

