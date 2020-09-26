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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 312345;

int n, m, k;
ll fat[MAXN], inv[MAXN];

map<int, pii> ev;

ll expo(ll base, ll e){
    if(e == 0)
        return 1;
    ll ans = expo(base, e/2);
    ans = mod(ans*ans);
    if(e&1)
        ans = mod(ans*base);
    return ans;
}

ll ch(ll x){
    if(x < k) return 0;
    return mod(mod(fat[x]*inv[x-k])*inv[k]);
}

int main (){
	scanf("%d%d", &n, &k);
    fat[0] = 1;
    for(int a=1;a<=n;a++){
        fat[a] = mod(fat[a-1]*a); 
    }
    inv[n] = expo(fat[n], modn-2);
    for(int a=n-1;a>=0;a--){
        inv[a] = mod(inv[a+1]*(a+1));
    }
    assert(inv[0] == 1);
	for(int a=0;a<n;a++){
        int l, r;
        scanf("%d%d", &l, &r);
        ev[l].fst++;
        ev[r].snd++;
	}
    ll cnt = 0;
    ll ans = 0;
    for(auto it: ev){
        pii here = it.snd; 
        ans = mod(ans + ch(here.fst + cnt) - ch(cnt));     
        cnt += here.fst - here.snd;
    }
    ans = mod(ans + modn);
    printf("%lld\n", ans);
}

