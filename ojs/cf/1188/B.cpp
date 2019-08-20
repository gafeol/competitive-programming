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

const int MAXN = 312345;

int n;
ll k, p;

map<ll, int> cnt;

int main (){
	scanf("%d%lld%lld", &n, &p, &k);
    modn = p;
    ll res = 0;
	for(int a=0;a<n;a++){
        ll x;
        scanf("%lld", &x);
        ll som = mod(mod(mod(x*x)*mod(x*x)) - mod(x*k) + modn);
        res += cnt[som]++;
	} 
    printf("%lld\n", res);
}

