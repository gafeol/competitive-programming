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

const long double EPS = 1e-6;

ll n, m, k;


void test(ll val, ll a, ll b, ll c){
    if(val*val*a + b*val + c == 0){
        printf("%lld\n", val);
        exit(0);
    }
}


void solve(long double a, long double b, long double c){
    long double delta = sqrt(b*b/(4*a*a) - c/a);
    long double x1 = -b/(2*a) + delta;
    long double x2 = -b/(2*a) - delta;

    test(x1, a, b, c);
    test(x1+EPS, a, b, c);
    test(x1-EPS, a, b, c);
    test(x2, a, b, c);
    test(x2+EPS, a, b, c);
    test(x2-EPS, a, b, c);
}

void test3(ll b){
    ll nn = n;
    ll val = 0;
    ll dez = 1;
    while(nn > 0){
        if((nn%b) > 9)
            return ;
        val += dez*(nn%b);
        dez *= 10ll;
        nn/=b;
    }
    if(val < k) 
        return ;
    printf("%lld\n", b);
    exit(0);
}

int main (){
	scanf("%lld%lld", &n, &k);

    for(ll nb = k;nb < 100;nb++){
        ll i = nb/10, j = nb%10;
        if((n - j)%i == 0){
            printf("%lld\n", (n-j)/i);
            return 0;
        }
    }

    for(ll nb = max(100ll, k);nb < 1000;nb++){
        ll a = nb/100;
        ll b = ((nb/10)%10);
        ll c = (nb%10) - n;
        solve(a, b, c);
    }

    long long sqrt3 = 1;
    while(sqrt3*sqrt3*sqrt3 <= n)
        sqrt3++;
    sqrt3--;
    
    for(ll base = sqrt3;base > 0;base--){
        test3(base);
    }
    assert(false); 
}
