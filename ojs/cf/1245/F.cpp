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
int s[MAXN];

ll mx, x;
// less than mx, &x = 0
ll dp[31][2];


ll go(int i=30, bool lt=false){
    if(i == -1) return 1;
    ll &r = dp[i][lt];
    if(r != -1)
        return r;
    if(lt){ // curr < mx
        if(x&(1<<i)) // x tem 1
            r = go(i-1, lt);  // coloca 0
        else // x tem 0
            r = 2ll*go(i-1, lt); // coloca 0 ou 1
    }
    else{ // curr = mx
        if(mx&(1<<i)){ // mx tem 1
            if(x&(1<<i)) //x tem 1
                r = go(i-1, true); // tem que ser 0
            else // x tem 0
                r = go(i-1, true) + go(i-1, lt); // coloca 0 ou 1
        }
        else // mx tem 0
            r = go(i-1, lt);
    }
    return r;
}

ll g(ll xx, ll mxx){
    memset(dp, -1, sizeof(dp));
    x = xx; 
    mx = mxx;
    return go();
}

ll solve(ll i, ll j){
    if(i == j-1){
        if(i == 0)
            return 1;
        else
            return 0;
    }
    if(i == 0)
        return 2ll*(j-1ll) + 1ll + solve(1, j);
    if(i&1)
        return solve(i+1, j) + 2ll*(g(i, j-1) - g(i, i-1)); // posso trocar por g(i, i) tb, ja que i != 0
    else if(j&1)
        return solve(i, j-1) + 2ll*(g(j-1, j-1) - g(j-1, i-1));
    else
        return 3ll*solve(i/2ll, j/2ll);
}

int main (){
    scanf("%d", &n);
    for(int a=0;a<n;a++){
        ll i, j;
        scanf("%lld %lld", &i, &j);
        printf("%lld\n", solve(i, j+1));
    }
}

