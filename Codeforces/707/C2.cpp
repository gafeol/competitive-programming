
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

	int res = 0;
	if(!res){
		ll k = 1;
		while((clock() - clk)/CLOCKS_PER_SEC < 0.7){
			ll x = ll(n*n - k*k)/(2ll*k);
			ll del = 2ll*n*n - k*k;
			if(x * 2ll*k == (n*n - k*k) && x > 0){
				res = 1;
				printf("%lld %lld\n", x, x+k);
			}
			else if(x > 0 && per(del) && !((-k + (ll)sqrt(del))&1ll)){
				res = 1;
				printf("%lld %lld\n", x, x+k);
			}
			k++;
			if(res)
				break;
		}
	}
	if(res == 0)
		puts("-1");
}
