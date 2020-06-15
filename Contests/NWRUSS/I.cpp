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

const int MAXN = 2123;

int n, m, k;
int s[MAXN];

int main (){
    ll mnx = LLONG_MAX, mxx =LLONG_MIN, mny = LLONG_MAX, mxy = LLONG_MIN;
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        ll i, j, k;
        scanf("%lld%lld%lld", &i, &j, &k);
        mnx = min(mnx, i-k);
        mxx = max(mxx, i+k);
        mny = min(mny, j-k);
        mxy = max(mxy, j+k);
	}
    //printf("x %lld %lld y %lld %lld\n", mnx, mxx, mny, mxy);
    ll h = max(mxy - mny + 1, mxx - mnx + 1)/2ll;
    printf("%lld %lld %lld\n", mnx + h, mny + h, h); 
}

