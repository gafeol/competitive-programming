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

int n, m, k;
ll x, y, l, r;

vector<ll> v;

int main (){
	scanf("%lld %lld %lld %lld", &x, &y, &l, &r);
	ll potx = 1;
	ll poty = 1;
	for(ll i = 0;potx <= r;i++){
		for(ll j = 0;potx + poty <= r;j++){	
			if(potx + poty >= l)
				v.pb(potx + poty);
			if(log(poty) + log(y) > log(r)) break;
			poty *= y;
		}
		if(log(potx) + log(x) > log(r)) break;
		potx *= x;
		poty = 1;
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	ll ult = l-1;
	ll res = 0;
	for(ll nxt: v){
		debug("%lld\n", nxt);
		res = max(res, nxt - ult-1);
		ult = nxt;
	}
	res = max(res, r-ult);
	printf("%lld\n", res);
}
