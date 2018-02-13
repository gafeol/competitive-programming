#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

#define int ll

int n, m, k;
int s[MAXN];

main (){
	scanf("%lld%lld", &n, &m);
	int qn = 0, qm = 0;
	int a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	qn = a*2 + b;
	qm = b + c*3;
	printf("%lld\n", max(0ll, qn-n) + max(0ll, qm -m));
}

