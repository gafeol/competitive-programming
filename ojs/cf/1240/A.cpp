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

const int MAXN = 212345;

int n, m;
ll s[MAXN];

bool cmp(ll a, ll b){
    return a>b;
}

ll gcd(ll a, ll b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

ll go(ll a, ll x, ll b, ll y, ll n){
    int i = 0;        
    ll ans = 0;
    int cnt = 0;
    ll lcm = a/gcd(a, b) * b;
    ll nl = n/lcm;
    while(i < nl){
        ans += s[i] * ( x + y);
        i++;
    }
    while(cnt < n/a - nl){
        //debug("i %d\n", i);
        ans += s[i]*x;
        i++;
        cnt++;
    }
    cnt = 0;
    while(cnt < n/b - nl){
        //debug("i %d\n", i);
        ans += s[i]*y;
        i++;
        cnt++;
    }
    return ans;
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            scanf("%lld", s+a);
            s[a] = s[a]/100;
        }
        sort(s, s+n, cmp);
        ll x, y;
        int a, b;
        scanf("%lld%d", &x, &a);
        scanf("%lld%d", &y, &b);
        if(x < y){
            swap(x, y);
            swap(a, b);
        }

        ll k;
        scanf("%lld", &k);

        int L = 0, R = n;
        while(L < R){
            int m = (L + R)/2;
            if(go(a, x, b, y, m) >= k)
                R = m;
            else
                L = m+1;

        }
        if(go(a, x, b, y, L) >= k) 
            printf("%d\n", L);
        else
            puts("-1");
    }
}

