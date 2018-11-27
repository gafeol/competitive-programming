#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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
ll k;
int s[MAXN];

int main (){
	scanf("%lld%d", &k, &n);
	multiset<pll> st;
	for(int a=0;a<n;a++){
		ll q, v;
		scanf("%lld%lld", &q, &v);
		st.insert({v, q});
	}
	ll ans = 0;
	while(!st.empty()){
		pll top = *st.rbegin();
		st.erase(st.find(top));
		ans += min(k, top.snd)*top.fst;
		k -= min(k, top.snd);
	}
	printf("%lld\n", ans);
}

