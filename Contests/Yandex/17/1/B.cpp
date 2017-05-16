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
const ll modn = 500;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

// 100000000000000000
// 012345678901234567

ll n, m, k;

ll go(ll x){
	return mod(mod(x) + modn); 
}

int main (){
	ll res =0;
	scanf("%lld %lld", &n, &k);
	for(ll i = 0;i <= 10000;i++){
		if(k + i <= n && n - (k+i) >= k)
			res = max(res, go(-(k+i)) + go(k+i - n));
		else
			break;
	}
	printf("%lld\n", res);
}
