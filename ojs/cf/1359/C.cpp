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

int n, m, k;
int s[MAXN];

int main (){
    for_tests(t, tt){
        ll h, c;
        scanf("%lld%lld%d", &h, &c, &k);
        if(h <= k){
            puts("1");
            continue;
        }
        if(2ll*k <= h+c){
            puts("2");
            continue;
        }
        ll i = 1, j = 1000000ll;
        while(i < j){
            ll m = (i + j+1)/2ll;
            if(h*m + (m-1)*c >= ((ll)k)*(2ll*m-1))
                i = m; 
            else
                j = m-1;
        }
        if(((i*h + (i-1)*c) - k*(2*i-1))*(2*i+1)  <= (k*(2*i + 1) - ((i+1)*h + i*c))*(2*i-1))
            printf("%lld\n", 2ll*i-1);
        else
            printf("%lld\n", 2ll*i + 1);
    }
}
