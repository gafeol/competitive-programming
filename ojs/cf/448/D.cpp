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

ll n, m;
ll k;
int s[MAXN];

ll go(ll x){
	ll ans = 0;
	for(ll a=1;a<=n;a++){
		ans += min(m, x/a);	
	}
	return ans;
}

int main (){
	scanf("%lld%lld%lld", &n, &m, &k);
	ll i = 1, j = n*m;
	while(i < j){
		ll m = (i + j)/2;
		if(go(m) < k)
			i = m+1;
		else
			j = m;
	}
	printf("%lld\n", i);
}

