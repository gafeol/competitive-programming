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

int t, tc, lim;

ull f(ull x) { return (x + ull(1))*x*(ull(2)*x + ull(1))/ull(6); }
ull g(ull k, ull i){
	if(!i) return 0;
	if(i <= k) return ull(i+1)*i/ull(2);
	i -= k;
	return ull(k+1)*k/ull(2) + i*k - ull(i+1)*i/ull(2);
}

int main (){
	lim = 1.5e6;
	freopen("army.in", "r", stdin);
	ll ans = 0;
	ll acu = 0;
	scanf(" %d", &t);
	while(t--){
		int lo, hi, mid, k;
		ull n, ans;

		scanf(" %llu", &n);

		if(n == 1){
			printf("Case %d: %d\n", ++tc, 1);
			continue;
		}

		lo = 0, hi = lim;
		while(hi > lo){
			int mid = (1 + lo + hi)/2;
			if(f(mid) < n) lo = mid;
			else           hi = mid -1;
		}

		ans = ull(lo)*ull(lo);
		k   = lo + 1;
		n -= f(lo);

		if(n == 1)
			ans++;
		else {
			lo = 0, hi = 2*k - 1;
			while(hi > lo){
				int mid = (lo + hi)/2;
				if(n <= g(k, mid)) hi = mid;
				else               lo = mid+1;
			}
			ans += lo;
		}

		printf("Case %d: %llu\n", ++tc, ans);
	}
}

