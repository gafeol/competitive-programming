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

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &k);
        for(int a=0;a<n;a++){
            scanf("%lld", s+a);
        }
        sort(s, s+n, greater<ll>());
        ll sum = 0;
        for(int i=0;i<=k && i < n;i++){
           sum += s[i]; 
           if(i > 0)
               s[i] = 0;
        }
        ll mn = *min_element(s, s+n);
        printf("%lld\n", sum - mn);
    }
}

