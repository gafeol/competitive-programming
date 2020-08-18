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

ll n, m, d;
ll s[MAXN];

ll sz(ll q){
    if(q == 0)
        return 0;
    return 1 + (q-1)*(d+1);
}

int main (){
	scanf("%lld%lld%lld", &n, &d, &m);
    vector<ll> sm, bg;
	for(int a=0;a<n;a++){
        ll x;
        scanf("%lld", &x);
        if(x <= m)
            sm.pb(x);
        else
            bg.pb(x);
	}
    sort(sm.begin(), sm.end(), greater<ll>());
    sort(bg.begin(), bg.end(), greater<ll>());

    ll j = 0;
    ll ans = 0;
    ll res = 0;
    while(j < bg.size()){
        if(1 + j*(d+1) > n){
            break;
        }
        ans += bg[j];
        j++;
    }
    res = max(res,ans);
    //debug("pegando i %d j %lld ans %lld\n", -1, j, ans);
    for(int i=0;i<sm.size();i++){
        if(i+1 > n)
            break;
        ans += sm[i]; 
        while(i+1 + sz(j) > n){
            ans -= bg[j-1];
            j--;
        }
        //debug("pegando i %d j %lld ans %lld\n", i, j, ans);
        res = max(ans, res);
    }
    printf("%lld\n", res);
}

