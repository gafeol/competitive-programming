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

map<ll, int> cnt;

int main (){
	scanf("%d", &n);
    ll J;
    scanf("%lld", &J);
    n--;
    vector<ll> v;
	for(int a=0;a<n;a++){
        scanf("%lld", s+a);
        cnt[s[a]]++;
        v.pb(s[a]);
    }
    sort(v.begin(), v.end(), greater<ll>());
    v.erase(unique(v.begin(), v.end()), v.end());
    bool lost = false;
    ll ans = 0;
    ll val = v[0];
    ll sz = cnt[val];
    for(int i=1;i<v.size();i++){
        ll lst = 64 - __builtin_clzll(sz) - 1;
        ll rounds = (val - v[i] - ans);
        debug("lst %lld  rounds %lld\n",lst, rounds);
        if(val + rounds*lst <= J){
            val += rounds*lst;  
            sz += cnt[v[i]];
            ans += rounds*(lst+1);
            debug("ans += %lld\n", rounds*(lst+1));
        }
        else
            break;
    }
    //make val surpass J
    ll lst = 64 - __builtin_clzll(sz) - 1;
    ll rounds = (J + 1 - val)/lst;
    debug("fim lst %lld rounds %lld\n", lst, rounds);

    val += rounds*lst;
    ans += rounds*(lst+1);
    
    if(val == J + 1){
        ans--;
        debug("asn --\n");
    }
    else{
        assert(val + lst > J); 
        ans += J + 1 - val;
        debug("ans += %lld\n", J + 1 - val); 
    }

    printf("%lld\n", ans-1);
     
}

