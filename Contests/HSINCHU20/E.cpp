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

ll n, m, k, L;
int main (){
    for_tests(t, tt){
        scanf("%lld%lld", &k, &L);
        for(ll n=max(1ll, L-1);n<1999;n++){
            if(k + n + 1 <= 1000000*n){
                ll sum = k + n + 1;
                printf("%lld\n-1 ", n+1);
                for(int a=0;a<n;a++){
                    ll val = min(1000000ll, sum);
                    printf("%lld ", val);
                    sum -= val; 
                }
                goto deubom;
            }
        }
        printf("-1");
deubom: puts("");
    }
}

