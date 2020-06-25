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

const int MAXN = 212345;

int n, m, k;
ll s[MAXN];

bool valid(ll x, ll a, ll b){
    ll val = ((a+x-1)/x)*x;
    return (val <= b);
}

int main (){
    scanf("%lld%lld%lld%lld", s, s+1, s+2, s+3);

    vector<ll> poss;
    poss.pb(1);
    for(int t=0;t<4;t++){
        poss.pb(s[t]);
        for(ll a = 2;a*a <= s[t];a++){
            if(s[t]%a == 0){
                poss.pb(a);
                poss.pb(s[t]/a);
                poss.pb(s[(t^1)]/a);
            }
        }
    }
    sort(poss.begin(), poss.end());
    poss.erase(unique(poss.begin(), poss.end()), poss.end());
    ll ans = 0;
    for(ll x: poss){
        if(valid(x, s[0], s[1]) && valid(x, s[2], s[3]))  {
            ans = max(x, ans);
        }
    }
    printf("%lld\n", ans);
}

