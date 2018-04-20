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
vector<int> p;

vector<ll> ans;

int main (){
	scanf("%lld%lld", &n, &k);
	for(ll i=30;i>=0;i--){
		if((1LL<<i) <= n){
			p.pb(i);
			n -= (1LL<<i);
		}
	}
	ll val = 1;
	for(int a=0;a<p.size();a++){
		while(p[a]--){
			ans.pb(val);
		}
		val += k;
		ans.pb(val);
		val += k;
	}
	printf("%d\n", (int)ans.size());
	for(ll u: ans){
		printf("%lld ", u);
	}
	puts("");
}
