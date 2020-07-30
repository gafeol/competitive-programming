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

int n, m, k;

int main (){
    ll ans = 0;
    ll sum[2];
    ll acc[2];
    sum[0] = sum[1] = 0;
    acc[0] = acc[1] = 0;
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        int t = (a&1);
        sum[t] = mod(acc[1-t] + 1ll);
        acc[t] += sum[t];
        ans = mod(ans + sum[t]);
	}
    printf("%lld\n", ans);
}
