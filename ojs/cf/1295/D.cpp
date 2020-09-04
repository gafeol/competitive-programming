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

ll n, m, k;

ll gcd(ll a, ll b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main (){
    for_tests(t, tt){
        scanf("%lld%lld", &n, &k);
        ll gc = gcd(n, k);
        k = k/gc;
        vector<ll> f;
        ll mx = k - 1;
        //printf("mx %lld\n", mx);
        for(ll d=2;d<=sqrt(k)+1 && d <= k;d++){
            if(k%d == 0){
                //printf("fact %lld\n", d);
                f.pb(d);
                while(k%d == 0)
                    k /= d;
            }
        }
        if(k > 1){
            //printf("fact %lld\n", k);
            f.pb(k);
        }

        ll ans = 0;
        for(int bm=0;bm < 1<<f.size();bm++){
            ll mul = 1;
            int cnt = 0;
            for(int i=0;i<f.size();i++){
                if((bm>>i)&1){
                    cnt++;
                    mul *= f[i];
                }
            }
            //printf("mul %lld\n", mul);
            if(cnt&1){
                ans -= mx/mul;
            }
            else
                ans += mx/mul;
        }
        printf("%lld\n", ans);
    }
}
