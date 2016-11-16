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

int n, m, k;
ll cnt[MAXN];
int s[MAXN];

int main (){
	scanf("%lld%lld%lld%lld", &cnt[2], &cnt[3], &cnt[5], &cnt[6]);
	ll res = min(min(cnt[2], cnt[5]), cnt[6]);
	cnt[2] -= res;
	res *= 256ll;
	res += 32*min(cnt[2], cnt[3]);
	printf("%lld\n", res);
}
