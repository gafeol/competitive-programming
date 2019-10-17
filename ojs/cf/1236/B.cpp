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

ll n, m, k;

ll expo(ll base, ll e){
    if(e == 0) return 1ll;

    ll ans = expo(base, e/2ll);
    ans = mod(ans*ans);

    if(e&1)
        ans = mod(ans*base);
    return ans;
}

int main (){
	scanf("%lld%lld", &n, &m);
    ll ans = expo(2, m) - 1;
    ans = expo(ans, n);
    printf("%lld\n", ans);
}

