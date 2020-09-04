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

ll n, m, k;
ll s[MAXN];

ll q[MAXN];

int main (){
	scanf("%lld", &n);
	for(int a=0;a<n;a++){
        scanf("%lld", s+a);
	}
    printf("1 1\n%lld\n", -s[0]);
    s[0] = 0;
    if(n <= 2){
        printf("%lld %lld\n%lld\n", n, n, -s[n-1]);
        printf("1 1\n0\n");
        return 0;
    }
    memset(q, -1, sizeof(q));
    ll val = 0;
    for(ll mul = 0;;mul++){
        if(q[val] != -1)
            break;
        q[val] = mul;
        val = (val + n-1)%n;
    }
    printf("%d %lld\n", 2, n);
    for(int a=1;a<n;a++){
        ll md = s[a]%n;
        md = (-md + n)%n;
        s[a] += q[md]*(n-1);
        printf("%lld ", q[md]*(n-1));
    }
    puts("");
    printf("%d %lld\n", 1, n);
    for(int a=0;a<n;a++){
        assert(s[a]%n == 0);
        printf("%lld ", -s[a]);
    }
    puts("");


}

