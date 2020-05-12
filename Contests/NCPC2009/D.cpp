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
const double EPS = 1e-6;

double l, k, t1, t2, h; 

clock_t clk;

double bb(){
    double i = h, j = 1000000000.;
    while(((double)clock() - clk)/CLOCKS_PER_SEC < 0.8){
         double m = (i + j)/2.;
         double rt = m/t1;
         double afterLevel;
         if(rt <= k)
            afterLevel = l; 
         else
            afterLevel = l + (t1 - l/rt)*(rt - k);
         afterLevel -= k*t2;
         afterLevel = max(afterLevel, l);
         if(afterLevel <= h)
             i = m;
         else
             j = m;
    }
    return i;
}
int main (){
    clk = clock();
    scanf("%lf %lf %lf %lf %lf", &l, &k, &t1, &t2, &h);
    double mn, mx;
    if(h < l){
        mn = h;
        mx = h;
    }
    else if(h == l){
        mn = h;
        mx = bb();
    }
    else{
        mn = mx = bb();
    }
    printf("%.10f %.10f\n", mn, mx);
}

