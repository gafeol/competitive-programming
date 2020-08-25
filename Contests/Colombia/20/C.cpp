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

const int MAXN = 2123, MAXK = 5123456;

int n, m, k;
int s[MAXN];

ll res[MAXK];
ll pot[MAXK];
ll expo(ll base, ll e){
    if(e == 0)
        return 1;
    ll ans = expo(base, e/2);
    ans = mod(ans*ans);
    if(e&1)
        ans = mod(ans*base);
    return ans;
}

int main (){
	scanf("%d%d", &n, &m);
    ll ans = 0;
    pot[0] = 1;
    ll sub = 0;
	for(int a=1;a<=m;a++){
        pot[a] = mod(pot[a-1]*n);
        res[a] = mod(modn + mod(pot[a] - sub));
        //printf("res[%d] %lld\n", a, res[a]);
        ans = mod(ans + res[a]);
        sub = mod(sub + res[a]);
	}
    assert(ans == pot[m]);
    printf("%lld\n", pot[m]);
}

