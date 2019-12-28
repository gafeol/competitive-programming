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

const int MAXN = 312345;

int n, m, k;
int s[MAXN];

int main (){
	scanf("%d", &n);
    ll tot = 0, x = 0;
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        tot += s[a];
        if(a&1)
            x += s[a]/2;
        else
            x += (s[a]+1)/2; 
	}
    //debug("%lld %lld\n", x, tot-x);
    printf("%lld\n", min(x, tot-x));
}

