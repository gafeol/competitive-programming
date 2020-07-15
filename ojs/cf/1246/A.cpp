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

ll n,p;

int main (){
	scanf("%lld%lld", &n, &p);
    for(ll i=1;i<70;i++){
        ll dif = n - p*i; 

        //printf("i %lld dif %lld popcnt %d\n", i, dif, __builtin_popcountll(dif));
        if(dif >= 0 && __builtin_popcountll(dif) <= i && dif >= i){
            printf("%lld\n", i);
            return 0;
        }
    }
    puts("-1");
}

