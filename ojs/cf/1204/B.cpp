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

int l, r, n, m, k;
int s[MAXN];

int main (){
	scanf("%d%d%d", &n, &l, &r);
    ll summn = 0, summx = 0;
    ll val = 1;
	for(int a=0;a<l;a++){
        summn += val;
        val *= 2ll;
	}
    summn += (n - l)*1;

    val = 1;
    for(int a=0;a<r;a++){
       summx += val; 
       val *= 2ll;
    }
    summx += (n - r)*(val/2ll);

    printf("%lld %lld\n", summn, summx);
}

