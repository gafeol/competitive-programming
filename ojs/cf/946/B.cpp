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
int s[MAXN];

int main (){
	scanf("%lld%lld", &n, &m);
	while(n != 0 && m != 0){
		debug("n %lld m %lld\n", n, m);
		if(n >= 2ll*m){
			n = n%(2ll*m);
		}
		if(n == 0 || m == 0) break;
		if(m >= 2ll*n){
			m = m%(2ll*n);
		}
		if(n < 2ll*m) break;
	}
	printf("%lld %lld\n", n, m);
}

