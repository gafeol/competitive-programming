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

long double pi = acos(-1.);

int n, m, k;
int s[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        long double th = (long double)pi/n, ang = 0;
        double ans = 0;
        for(int a=0;a<(n-1)/2;a++){
            ang += th;
            ans += sin(ang);
        }
        ans *= 2.;
        if((n-1)&1)
            ans += 1.;
        printf("%.10f\n", ans);
    }
}

