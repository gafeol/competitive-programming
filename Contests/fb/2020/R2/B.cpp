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

const int MAXN = 8123;

int n, m, k;

double dp[MAXN][MAXN], p;

double go(int ns, int nb){
    if(ns  < 0 || nb < 0) return 0;
    double &r = dp[ns][nb];
    if(ns + nb == 0) return r = 0;
    if(r > -0.5)
        return r;
    double me = 1./(ns + nb + 1);
    double o = 0;
    r = 1;
    r += 2.*me*(ns/((double)ns+nb))*p*go(ns-1, nb);
    r += 2.*me*(nb/((double)ns+nb))*(1.-p)*go(ns, nb-1);
    // pega dois menor
    if(ns > 1)
        r += (ns/((double)ns+nb+1))*((ns-1.)/(ns+nb)) * go(ns-1, nb);
    if(nb > 1)
        r += (nb/((double)ns+nb+1))*((nb-1.)/(ns+nb)) * go(ns, nb-1);
    if(ns > 0 && nb > 0)
        r += 2*(ns/(ns+nb+1.))*(nb/((double)ns+nb)) * (p*go(ns-1, nb) + (1.-p)*go(ns, nb-1));
    return r;
}

int main (){
    for_tests(t, tt){
        scanf("%d%lf", &n, &p);
        for(int a=0;a<=n;a++){
            for(int b=0;b<=n;b++){
                dp[a][b] = -1.;
            }
        }
        printf("Case #%d:\n", tt);
        for(int a=0;a<n;a++){
            printf("%.10f\n", go(a, n-a-1));
        }
    }
}

