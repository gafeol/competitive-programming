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
const ll modn = 998244353;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;

ll expo(ll base, ll e){
    if(e == 0)return 1ll;
    ll ans = expo(base, e/2ll);
    ans = mod(ans*ans);
    if(e&1)
        ans = mod(ans*base);
    return ans;
}

ll fat[MAXN];

ll ch(ll a, ll b){
    return  mod(fat[a]*mod(expo(fat[b], modn-2)*expo(fat[a-b], modn-2)));
}

int main (){
    fat[0] = 1;
    for(ll a = 1;a<MAXN;a++)
        fat[a] = mod(fat[a-1]*a);
	scanf("%d%d", &n, &m);
    if(n == 2){
        puts("0");
        return 0;
    }
    ll ans = 0;
	for(int x=n-1;x<=m;x++){
        ll c = ch(x-1, n-2);
        ans = mod(ans + mod(expo(2, n-3)*mod(c*(n-2ll)))); 
    }
    printf("%lld\n", ans);
}

