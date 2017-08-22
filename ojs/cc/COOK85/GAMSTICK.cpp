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

inline ll ti(ll i, ll j, ll im, ll m){
	return abs(j - m) + abs(im - i);
}

int main (){
	for_tests(t, tt){
		ll i, j, ii, jj;
		scanf("%lld %lld %lld %lld %lld", &n, &i, &j, &ii, &jj);
		if(j == jj || n == 2){
			puts("Draw");
			continue;
		}
		ll m = (n+1ll)/2ll;
		ll m1, m2;
		m1 = m;
		m2 = m;
		if(!(n&1ll)){
			if(j <= m)
				m1 = m+1ll;
			if(jj <= m)
				m2 = m+1ll;
		}
		if(ti(i, j, ii, m1) <= ti(ii, jj, ii, m1))
			puts("Miron");
		else if(ti(ii, jj, i, m2) < ti(i, j, i, m2))
			puts("Slava");
		else
			puts("Draw");
	}
}

