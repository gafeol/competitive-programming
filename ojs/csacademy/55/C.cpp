
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

int n, m;
ll s[MAXN];
ll k;

ll go(ll h){
	ll ans = 0;
	for(int a=0;a<n;a++){
		ans += s[a]/h;	
	}
	return ans;
}

int main (){
	scanf("%d%lld", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
	}
	ll i = 0, j = 1000000001LL;
	while(i < j){
		ll m = ( i + j +1)/2ll;
		if(go(m) >= k)
			i = m;
		else
			j = m - 1;
	}
	printf("%lld\n", i);
}

