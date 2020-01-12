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
ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 252345;

ll n, m, k;
ll fat[MAXN];

int main (){
	scanf("%lld%lld", &n, &modn);
    fat[0] = 1;
    for(ll a =1;a<=n;a++)
       fat[a] = mod(fat[a-1]*a); 
    ll res = 0;
	for(ll a=1;a<=n;a++)
        res = mod(res + mod(mod(fat[a]*mod(fat[n-a]*(n - a + 1)))*(n-a+1)));
    printf("%lld\n", res);
}

