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

const int MAXN = 312345;

int n, m, k;
ll s[MAXN];

bool go(double x){
    double mn = DBL_MAX;
    double v[MAXN];
    v[0] = 0;
    for(int a=1;a<=n;a++){
        v[a] = v[a-1] + s[a]; 
        if(a - k >= 0)
            mn = min(mn, v[a-k] - x*(a-k));
        if(mn <= v[a] - x*a)
            return true; 
    }
    return false;
}

int main (){
    scanf("%d%d", &n, &k);
    for(int a=1;a<=n;a++)
        scanf("%lld", s+a);
    double i = 0, j = 1000000;
    while(j-i > 1e-5){
        double m = (i + j)/2.;
        if(go(m))
            i = m;  
        else
            j = m;
    }
    printf("%.10f\n", i);
}
