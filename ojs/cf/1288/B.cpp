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

const int MAXN = 212345;

ll n, m, k;
int main (){
    ll pot[12];
    pot[0] = 1;
    for(int i=1;i<12;i++)
        pot[i] = 10*pot[i-1];
    for_tests(t, tt){
        scanf("%lld%lld", &n, &m);
        ll ans = 0;
        for(int szb=1;szb<=10;szb++){
            if(pot[szb]-1 <= m){
               ans += n; 
            }
        }
        printf("%lld\n", ans);
    }
}

