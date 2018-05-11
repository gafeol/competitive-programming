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

ll n, m, v, k;

set<ll> esc, ele;

ll go(ll x, ll y, ll xx, ll yy){
	ll pos;
	ll ans = LLONG_MAX;
	if(y == yy){
		return abs(x - xx);
	}
	if(esc.lower_bound(x) != esc.end()){
		pos = *esc.lower_bound(x);
		ans = min(ans, abs(x - pos) + abs(yy - y) + abs(xx - pos));	
	}
	if(esc.lower_bound(x) != esc.begin()){
		pos = *(--esc.lower_bound(x));
		ans = min(ans, abs(x - pos) + abs(yy - y) + abs(xx - pos));	
	}

	if(ele.lower_bound(x) != ele.end()){
		pos = *ele.lower_bound(x);
		ans = min(ans, abs(x - pos) + (abs(yy - y)+v-1)/v + abs(xx - pos));	
	}
	if(ele.lower_bound(x) != ele.begin()){
		pos = *(--ele.lower_bound(x));
		ans = min(ans, abs(x - pos) + (abs(yy - y)+v-1)/v + abs(xx - pos));	
	}
	return ans;
}
int es, el;

int main (){
	scanf("%lld%lld%d%d%lld", &n, &m, &es, &el, &v);
	for(int a=0;a<es;a++){
		int x;
		scanf("%d", &x);
		esc.insert(x);
	}
	for(int a=0;a<el;a++){
		int x;
		scanf("%d", &x);
		ele.insert(x);
	}
	scanf("%lld", &k);
	for(int a=0;a<k;a++){
		ll x, y, xx, yy;
		scanf("%lld %lld %lld %lld", &y, &x, &yy, &xx);
		printf("%lld\n", go(x, y, xx, yy));	
	}
}

