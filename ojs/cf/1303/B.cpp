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

ll n;

int main (){
    for_tests(t, tt){
        ll g, b;
        scanf("%lld%lld%lld", &n, &g, &b);

        ll i = 0, j = (ll)1e18+1;
        while(i < j){
            ll m = (i + j)/2;
            ll good = (m/(g+b))*g + min(g, m%(g+b));
            ll bad = m - good;
            if(good >= (n+1)/2 && good + bad >= n)
                j = m;
            else
                i = m+1;
        }
        printf("%lld\n", i);
    }
}

