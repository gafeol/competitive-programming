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

const int MAXN = 100006;
//               123456789
const ll MAXX = 1000000000LL;

ll n;

bool test(ll x){
    ll i = 1, j = MAXX;
    while(i < j){
        ll m = (i + j + 1)/2ll;
        if(n/m < x)
            j = m-1;
        else
            i = m;
    }
    return (n/i == x);
}

int main (){
    for_tests(t, tt){
        scanf("%lld", &n);
        vector<ll> ans;
        ans.pb(0);
        for(int a=1;a<=min(n, (ll)MAXN);a++){
            if(ans.back() != n/a)
                ans.pb(n/a);
        }
        if(n > MAXN){
            int mn = ans.back();
            while(mn--){
                if(test(mn))
                    ans.pb(mn);
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        printf("%d\n", ans.size());
        for(int x: ans)
            printf("%d ", x);
        puts("");
    }
}

