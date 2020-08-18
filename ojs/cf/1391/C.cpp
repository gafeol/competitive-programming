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

const int MAXN = 2000006;

int n, m, k;
int s[MAXN];
ll pot[MAXN];
ll f[MAXN];

int main (){
    pot[0] = 1;
    f[0] = 1;
    for(int a=1;a<MAXN;a++){
        pot[a] = mod(pot[a-1]*2ll);
        f[a] = mod(a*f[a-1]);
    }
	scanf("%d", &n);
    ll ans = mod(f[n] - pot[n-1]);
    ans = mod(ans + modn);
    printf("%lld\n", ans);
}

