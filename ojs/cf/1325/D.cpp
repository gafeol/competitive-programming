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

ll n, m, k, x, s;
int res[70];

int main (){
	scanf("%lld%lld", &x, &s);
    if(x > s){
        puts("-1");
        return 0;
    }
    
    ll os = s, ox = x;
    ll L = 1, R = 1000000;
    ll mx = 0;
    while(L < R){
        s = os;
        x = ox;
        memset(res, 0, sizeof(res));
        ll M = (L + R)/2ll;
        mx = 0;
        for(ll i=60;i>=0;i--){
            ll pot = (1ll<<i);
            ll p = ((x&pot)>0ll);
            if(p)
                x ^= pot;
            ll cnt = (s-x)/pot;
            cnt = min(cnt, M);
            if((cnt&1ll) != p)
                cnt--;
            if(cnt <= 0){
                if(p){
                    s = 1;
                    break;
                }
                continue;
            }
            s -= pot*cnt;
            res[i] = cnt; 
            mx = max(mx, cnt);
        }
        if(s > 0)
            L = M + 1;
        else
            R = M;
    }
    ll M = L;
    debug("lim %lld\n", M);
    s = os;
    x = ox;
    memset(res, 0, sizeof(res));
    mx = 0;
    for(ll i=60;i>=0;i--){
        ll pot = (1ll<<i);
        ll p = ((x&pot)>0ll);
        if(p)
            x ^= pot;
        ll cnt = (s-x)/pot;
        cnt = min(cnt, M);
        if((cnt&1ll) != p)
            cnt--;
        if(cnt <= 0){
            if(p){
                s = 1;
                break;
            }
            continue;
        }
        s -= pot*cnt;
        res[i] = cnt; 
        mx = max(mx, cnt);
    }
    if(s > 0){
        puts("-1");
    }
    else{
        vector<ll> ans(mx, 0);
        for(ll i=60;i>=0;i--){
            for(int x=0;x<res[i];x++){
                ans[x] += (1ll << i);
            }
        }
        printf("%lld\n", mx);
        for(ll x: ans)
            printf("%lld ", x);
        puts("");

    }
}

