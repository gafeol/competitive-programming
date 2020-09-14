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

const int MAXN = 100005;

int n, m, k;
int s[MAXN];

ll f[MAXN], inv[MAXN];

ll expo(ll base, ll e){
    if(e == 0)
        return 1;
    ll ans = expo(base, e/2);
    ans = mod(ans*ans);
    if(e&1)
        ans = mod(ans*base);
    return ans;
}

ll ch(int a, int b){
    return mod(f[a]*mod(inv[a-b]*inv[b]));
}

int main (){
    f[0] = inv[0] = 1;
    for(int i=1;i<MAXN;i++){
        f[i] = mod(i*f[i-1]);
    }
    inv[MAXN-1] = expo(f[MAXN-1], modn-2);
    for(int i=MAXN-2;i>=1;i--){
        inv[i] = mod(inv[i+1]*(i+1));
    }
    for_tests(t, tt){
        scanf("%d", &n);
        int mx = 0, cnt;
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
            if(s[a] > mx){
                mx = s[a];
                cnt = 1;
            }
            else if(s[a] == mx)
                cnt++;
        }
        ll ans = 0;
        ll o = expo(2, n - cnt); 
        for(int q=cnt/2+1;q<=cnt;q++){
            ans = mod(ans + ch(cnt, q)*o); 
        }
        ans = mod(2*ans);
        printf("%lld\n", ans);
    }
}

