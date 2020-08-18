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

const int MAXN = 1123456;

int n, m, k;
ll w;
ll l[MAXN];

ll cl[MAXN], cr[MAXN];
ll h[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d%d%lld", &n, &k, &w);
        for(int a=0;a<n;a++)
            cl[a] = cr[a] = 0;
        for(int a=0;a<k;a++)
            scanf("%lld", l+a);
        ll A, B, C, D;
        scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
        for(int a=k;a<n;a++)
            l[a] = ((A*l[a-2] + B*l[a-1] + C)%D) + 1;

        for(int a=0;a<k;a++)
            scanf("%lld", h+a);
        scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
        for(int a=k;a<n;a++)
            h[a] = ((A*h[a-2] + B*h[a-1] + C)%D) + 1;

        ll ans = 1;
        ll per = 0;
        ll xate = 0; 
        for(int a=0;a<n;a++){
            if(l[a] >= xate){
                xate = l[a] + w; 
                per += 2*w;
            }
            else{
                per += 2*(l[a]+w - xate);
                xate = l[a]+w;
            }
            per = mod(per);
            for(int b=a-1;b>=0;b--){
                if(l[b] + w < l[a]) break;
                // get cl
                cl[a] = max(cl[a], h[b]);
                // update cr
                per -= max(0ll, h[b] - cr[b]);
                cr[b] = max(cr[b], h[a]);
                per += max(0ll, h[b] - cr[b]);
                per = mod(per);
            }
            
            per = mod(mod(per) + max(0ll, h[a] - cl[a]) + h[a]);
            ans = mod(ans*per);
        }
        printf("Case #%d: ", tt);
        printf("%lld\n", ans);
    }
}

