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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;


ll pa(ll x){
    if(x <= 0)
        return 0;
    return ((x+1)*x)/2ll;
}

int main (){
    ll n, x, y, c;
	scanf("%lld%lld%lld%lld", &n, &x, &y, &c);
    ll l = 0, r = 1e9 + 5ll;
    while(l < r){
        ll k = (l + r)/2;
        ll dx = min(n, x + k) - max(1ll, x-k) + 1;
        ll dy = min(n, y+k) - max(1ll, y-k) + 1;
        ll cnt = dx*dy;
        ll d[] = { max(0ll, y+k - n), max(0ll, x+k - n), max(0ll, 1 + k-y), max(0ll, 1 + k-x) };
        for(int a=0;a<4;a++){
            int nxt = (a+1)%4;
            cnt -= pa(k - d[a] - d[nxt]);
        }
        if(cnt >= c)
            r = k;
        else
            l = k+1;
    }
    printf("%lld\n", l);

}

