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

int n, m, k;

ll gcd(ll a, ll b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        ll b, r, k;
        scanf("%lld%lld%lld", &b, &r, &k);
        ll gc = gcd(b, r);
        b /= gc;
        r /= gc;
        if(b > r)
            swap(b, r);
        if((r-1ll+ b-1)/b >= k)
            puts("REBEL");
        else
            puts("OBEY");
	}
}

