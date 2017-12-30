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

ll count(ll x){
	if(x - 1 <= n)
		return (x - 1)/2ll;    
	else
		return (n - (x - n) + 1)/2ll; 
}

int main (){
	scanf("%lld", &n);
	ll sum = n + n - 1ll;
	ll mx = 0, cnt = 0;
	ll pot = 1;
	while(cnt*10ll + 9ll <= sum){
		cnt = cnt*10ll + 9ll;
		mx++;
		pot *= 10ll;
	}
	debug("count %lld = %lld\n", cnt, res);
	for(ll a=0;a<9;a++){
		cnt += pot*a;
		debug("testa cnt %lld\n", cnt);
		if(cnt > sum) break;
		res += count(cnt);
		debug("count %lld = %lld\n", cnt, count(cnt));
		cnt -= pot*a;
	}
	printf("%lld\n", res);
}

