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

int n;
ll l, A, B;
ll s[MAXN];

ll go(ll x){
	ll ans = 0;
	for(int a=0;a<n;a++)
		ans += abs(s[a] - (x + l*a));
	return ans;
}

int main (){
	for_tests(t, tt){
		scanf("%d%lld %lld %lld", &n, &l, &A, &B);
		for(int a=0;a<n;a++){
			scanf("%lld", s+a);
		}
		sort(s, s+n);
		ll i = A, j = B - n*l;
		while(j - i >= 3){
			ll mi = i + (j - i)/3;
			ll mj = j - (j - i)/3;
			if(go(mi) > go(mj))
				i = mi;
			else
				j = mj;
		}
		ll res = LLONG_MAX;
		for(ll a=i;a<=j;a++){
			res = min(res, go(a));
		}
		printf("%lld\n", res);
	}
}
