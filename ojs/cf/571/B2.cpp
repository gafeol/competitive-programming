
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second

#define int ll

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 312345, INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];

bool cmp(int a, int b){
	return a > b;
}

main (){
	scanf("%lld %lld", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
	}
	sort(s, s+n);
	ll res = 0;
	if(2*k <= n){
		int ini = 0, pos = 0;
		int a = 0;
		debug("\nsem ign\n");
		while(ini < k){
			res -= s[a];
			int inc = (n-1 - pos)/k;
			debug("ini %lld s[%lld] %lld s[%lld] %lld\n", ini, a, s[a], a+inc, s[a+inc]);
			a += inc;
			res += s[a];
			a++;
			ini++;
			pos = ini;	
		}
	}
	else{
		int cnt = k-1 - (n-k) + 1;
		for(int ign=0;ign<=cnt;ign++){
			debug("\ncom ign %lld\n", ign);
			int ini = ign, pos = ign;
			int a = ign;
			while(ini < n-k){
				res -= s[a];
				int inc = (n-1 - pos)/k;
				debug("ini %lld s[%lld] %lld s[%lld] %lld\n", ini, a, s[a], a+inc, s[a+inc]);
				a += inc;
				res += s[a];
				a++;
				ini++;
				pos = ini;	
			}
		}
	}

	ll ans = res;

	sort(s, s+n, cmp);
	res = 0;
	if(2*k <= n){
		int ini = 0, pos = 0;
		int a = 0;
		debug("\nsem ign\n");
		while(ini < k){
			res -= s[a];
			int inc = (n-1 - pos)/k;
			debug("ini %lld s[%lld] %lld s[%lld] %lld\n", ini, a, s[a], a+inc, s[a+inc]);
			a += inc;
			res += s[a];
			a++;
			ini++;
			pos = ini;	
		}
	}
	else{
		int cnt = k-1 - (n-k) + 1;
		for(int ign=0;ign<=cnt;ign++){
			debug("\ncom ign %lld\n", ign);
			int ini = ign, pos = ign;
			int a = ign;
			while(ini < n-k){
				res -= s[a];
				int inc = (n-1 - pos)/k;
				debug("ini %lld s[%lld] %lld s[%lld] %lld\n", ini, a, s[a], a+inc, s[a+inc]);
				a += inc;
				res += s[a];
				a++;
				ini++;
				pos = ini;	
			}
		}
	}
	res = -res;

	ans = min(ans, res);
	printf("%lld\n", ans);
}
