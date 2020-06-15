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

ll n, m, k;
int main (){
    for_tests(t, tt){
        scanf("%lld", &n);
        if(n == 1){
            puts("0");
            continue; 
        }
        ll bit = 1;
        ll nn = n;
        while(!(n&1)){
            bit++;
            n>>=1;
        }
        printf("%lld\n", (nn-1)/(1ll<<bit));
    }
}

