#include "bits/stdc++.h"
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

int n, m, k;
ll s[MAXN];

ll gcd(ll a, ll b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main (){
	scanf("%d", &n);
    ll gc = 0;
	for(int a=0;a<n;a++){
        scanf("%lld", s+a);
        gc = gcd(gc, s[a]);
	}
    printf("%lld\n", gc);
}

