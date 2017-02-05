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

vector<ll> f;

int main (){
	scanf("%lld %lld", &n, &k);
	for(ll a=1;a<=sqrt(n);a++){
		if(n%a == 0){
			f.pb(n/a);
			k--;
			if(k == 0){
				printf("%lld\n", a);
				return 0;
			}
			
		}
	}
	int i = f.size()-1;
	ll sq = sqrt(n);
	if(sq*sq== n)
		i--;
	while(i >= 0){
		k--;
		if(k == 0){
			printf("%lld\n", f[i]);
			return 0;
		}
		i--;
	}
	puts("-1");
}
