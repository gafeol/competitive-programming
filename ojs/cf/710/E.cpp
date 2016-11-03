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
ll res;

int main (){
	scanf("%lld%lld%lld", &n, &m, &k);
	clock_t clk = clock();
	res = n*m;
	ll nn = n;
	ll cus = 0;
	for(ll add = 0;((double)(clock() - clk))/CLOCKS_PER_SEC <= 1.8;add++){
		nn = n + add;
		cus = 0;
		for(ll a=0;nn >= 1;a++){
			res = min(res, a*k + nn*m + cus*m + add*m);
			cus += (nn&1);		
			nn /=2;
		}
		nn = n - add;
		if(nn <= 0)
			continue;
		cus = 0;
		for(ll a=0;nn >= 1;a++){
			res = min(res, a*k + nn*m + cus*m + add*m);
			cus += (nn&1);		
			nn /=2;
		}

	}
	printf("%lld\n", res);
}
