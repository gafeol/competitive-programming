#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
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

int n, m, k;
ll s[MAXN];
ll sum[MAXN];
ll bst[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%lld", s+a);
        sum[a] = (a > 0 ? sum[a-1] : 0) + s[a];
        bst[a] = max((a>0?bst[a-1]:0), sum[a]);
	}
    ll pos = 0;
    ll ans = 0;
    for(int a=0;a<n;a++){
        ans = max(ans, pos + bst[a]);
        pos += sum[a];
    }
    printf("%lld\n", ans);
    return 0;
}

