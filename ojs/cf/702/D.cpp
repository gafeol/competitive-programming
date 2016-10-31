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

ll n, m, k, tc, tw, tr, td, d;
ll res;

void fim(){
	printf("%lld\n", res);
	exit(0);
}

int main (){
	scanf("%lld %lld %lld %lld %lld", &d, &k, &td, &tw, &tr);
	res = LLONG_MAX;
	if(k >= d){
		res = d*td;
		fim();
	}
	res = min(res, d*tw);
	res = min(res, td*k - k*tw + d*tw);
	res = min(res, (td*k + tr - k*tw)*(d/k) -tr + d*tw);
	if(d%k != 0)
		res = min(res, d*td + tr*(d/k));
	printf("%lld\n", res);
	
}
