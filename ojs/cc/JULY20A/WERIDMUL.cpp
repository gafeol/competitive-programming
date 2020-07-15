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

const int MAXN = 212345;

int n, m;
ll k;
ll s[MAXN];

ll expo(ll base, ll e){
    if(e == 0) return 1;
    ll ans = expo(base, e/2);
    ans = mod(ans*ans);
    if(e&1) ans = mod(ans*base);
    return ans;
}

int main (){
    for_tests(t, tt){
        scanf("%d%lld", &n, &k);
        for(int a=0;a<n;a++){
            scanf("%lld", s+a);
        }
        ll sum = 0;
        ll ans = 1;
        for(int tam=1;tam<=n;tam++){
           sum = mod(sum*k + s[0]);
           ans = mod(ans*expo(mod(sum*sum), n-tam+1));
        }
        printf("%lld\n", ans);
	}
}

