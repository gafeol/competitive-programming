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

int n, m;
ll k;
ll s[MAXN];
ll acc[MAXN];

int rounds(ll x, ll k){
    int ans = 1;
    while(k < x){
        k *= 2;
        ans++;
    }
    return ans;
}

int main (){
    for_tests(t, tt){
        scanf("%d%lld", &n, &k);
        for(int a=0;a<n;a++){
            scanf("%lld", s+a);
        }
        sort(s, s+n);
        acc[n] = 0;
        for(int a=n-1;a>0;a--)
            acc[a] = rounds(s[a], 2*s[a-1]) + acc[a+1];
        ll ans = LLONG_MAX;
        for(int a=0;a<n;a++){
            ans = min(ans, a + rounds(s[a], k) + acc[a+1]);
            //debug("a %d ans %lld + %d + %d\n", a, acc[a+1], rounds(s[a], k), a);
        }
        printf("%lld\n", ans);
    }
}
