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

ll go(ll x){
    return 1 + ((x+k-2)*(k-x+1))/2;
}

int main (){
	scanf("%lld%lld", &n, &k);
    if(n == 1){
        puts("0");
        return 0;
    }
    if(go(2) < n){
        puts("-1");
        return 0;
    }
    if(n <= k){
        puts("1");
        return 0;
    }
    ll i = 2, j = k;
    while(i < j){
        ll m = (i + j+1)/2;
        if(go(m) >= n)
            i = m;
        else
            j = m-1;
    }
    printf("%lld\n", (k - i + 1));
}

