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

ll n, m, k;
int s[MAXN];

int main (){
	scanf("%lld %lld", &n, &k);
	ll i = 0, j = (n/2)/k + 1;
	while(i < j){
		ll m = (i + j + 1)/2;
		if(m + m*k <= n/2)
			i = m;
		else
			j = m-1;
	}
	printf("%lld %lld %lld\n", i, i*k, n - i*(k+1));
}
