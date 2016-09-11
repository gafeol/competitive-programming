#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

ll n;

bool per(ll x){
	return (((ll)sqrt(x))*((ll)sqrt(x)) == x);
}

int main(){
	clock_t clk = clock();
	scanf("%lld", &n);
	ll p[5];
	p[0] = 3ll;
	p[1] = 4ll;
	p[2] = 5ll;
	int res =0;
	for(int a=0;a<3;a++){
		if(n%p[a] == 0){
			printf("%lld %lld\n", (n/p[a])*(p[(a+1)%3]),  (n/p[a])*(p[(a+2)%3])); 
			res = 1;
			break;
		}
	}
	if(res == 0){
		for(ll a=1;((double)(clock() - clk))/CLOCKS_PER_SEC < 0.9;a++){
			if(n*n - a*a > 0 && per(n*n - a*a)){
				res =1;
				printf("%lld %lld\n", a, (ll)sqrt(n*n - a*a));
			}
			else if(2.*log(n) + 2.*log(a) < 18. && per(n*n + a*a)){
				res = 1;
				printf("%lld %lld\n", a, (ll)sqrt(n*n + a*a));
			}
			if(res) break;
		}
	}
	if(!res){
		ll x = ll(n*n - 1ll)/2ll;
		if(x * 2 == (n*n - 1ll) && x > 0){
			res = 1;
			printf("%lld %lld\n", x, x+1ll);
		}
	}
	if(res == 0)
		puts("-1");
}
