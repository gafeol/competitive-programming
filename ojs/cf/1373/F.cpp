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

const int MAXN = 2000002;

int n;
ll s[MAXN];
ll c[MAXN];

ll sums[MAXN], sumc[MAXN];

int main(){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            scanf("%lld", s+a);
            s[a+n] = s[a];
        }
        for(int a=0;a<n;a++){
            scanf("%lld", c+a);
            c[a+n] = c[a];
        }
        s[2*n] = c[2*n] = 0;
        sums[0] = 0;
        sumc[0] = c[n-1];
        ll mx = 0;
        bool ok = true;
        for(int a=0;a<2*n;a++){
            if(a > 0){
                sums[a] = sums[a-1];
                sumc[a] = sumc[a-1];
            }
            sums[a] += s[a];
            sumc[a] += c[a];
            if(sumc[a] - sums[a] - mx < 0){
                ok = false;
                break;
            }
            mx = max(mx, sumc[a] - c[a] - sums[a]);
            //printf("mx %d sumc %lld - c %lld - sums %lld\n", mx, sumc[a], c[a], sums[a]);
        }
        ok &= (sumc[n-1] - c[n-1] >= sums[n-1]);
        if(ok)
            puts("YES");
        else
            puts("NO");
    }
}
