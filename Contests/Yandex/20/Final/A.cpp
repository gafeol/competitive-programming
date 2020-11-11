#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
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

int n, m; ll k;

double sq(double x){
    return x*x;
}

double getmx(double a, double b){
    return -b/(2*a);
}

double val(double a, double b, double c, double x){
    return sq(x)*a + b*x + c;
}

double val(double a, double b, double c){
    if(a < 1e-8 && a > -1e-8) return c;
    double x = min(max(0., getmx(a, b)), (double)k);
    return sq(x)*a + b*x + c;
}

int main (){
	scanf("%d%lld", &n, &k);
    double res = 0;
    double cte = 0;
    double aa, bb, cc;

    vector<ll> A, B, C;
    vector<int> ind;
	for(int a=0;a<n;a++){
        ll x, y, z;
        scanf("%lld%lld%lld", &x, &y, &z);
        if(y <= 0){
            cte += z;
            continue;
        }
        A.pb(x);
        aa += x;
        B.pb(y);
        bb += y;
        C.pb(z);
        cc += z;
        int sz = ind.size();
        ind.pb(sz);
        //double mxx = -B[a]/(2.*A[a]);
        //ans += val(A[a], B[a], C[a], min((double)k, max(0., mxx)));
        //printf("ans %.4f\n", ans);
	}
    sort(ind.begin(), ind.end(), [&](int a, int b) { return getmx(A[a], B[a]) < getmx(A[b], B[b]); });
    res = max(res, val(aa, bb, cc));
    double sum = 0;
    for(int i: ind){
        double x = min((double)k, max(0., getmx(A[i], B[i]))); 
        sum += val(A[i], B[i], C[i], x);
        aa -= A[i];
        bb -= B[i];
        cc -= C[i];
        k -= x;
        res = max(res, sum + val(aa, bb, cc));
    }
    printf("%.10f\n", cte  + res);
    return 0;
}

