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
const ll modn = 998244353;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 5123;

int n, m, k;

ll s[3];

ll fat[MAXN][MAXN];

ll expo(ll base, ll e){
	if(e == 0) return 1;
	ll ans = expo(base, e/2ll);
	ans = mod(ans*ans);
	if(e&1)
		ans = mod(ans*base);
	return ans;
}

int main (){
	for(ll i=0;i<=5000;i++){
		fat[i][i] = 1;
		for(ll j=i+1;j<=5000;j++){	
			fat[i][j] = mod(j*fat[i][j-1]);
		}
	}
	for(int a=0;a<3;a++)
		scanf("%lld", s+a);
	ll ans = 1;
	for(int a=0;a<3;a++){
		for(int b=a+1;b<3;b++){
			ll res = 0;
			for(int i=0;i<=min(s[a], s[b]);i++){
				res = mod(res + mod(fat[s[a]-i][s[a]]*fat[s[b]-i][s[b]])*expo(fat[0][i], modn-2));	
			}
			debug("\nentre %d e %d %lld jeitos\n", a, b, res);
			ans = mod(ans*res);
		}
	}
	printf("%lld\n", ans);
}

