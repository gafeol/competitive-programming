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
ll s[MAXN][2];
ll d;

void fail(){
	puts("impossible");
	exit(0);
}

ll res[2], resi[2];

void test(int i, int t){
	if(lim[0][t] <= i && i <= lim[1][t]){
		ll ans = 0;
		for(int a=0;a<n;a++){
			ans += abs(s[a][t] - i);	
		}
		if(ans < res[t]){
			res[t] = ans;
			resi[t] = i;
		}
	}
}

int main (){
	res[0] = LLONG_MAX;
	res[1] = LLONG_MAX;
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld%lld", &s[a][0], &s[a][1]);	
	}
	scanf("%lld", &d);
	ll lim[2][2];
	for(int t=0;t<2;t++){
		lim[0][t] = LLONG_MIN;
		lim[1][t] = LLONG_MAX;
		for(int a=0;a<n;a++){
			if(s[a][t] - d > lim[1][t])
				fail();
			if(s[a][t] + d < lim[0][t])
				fail();
			lim[0][t] = max(lim[0][t], s[a][t] - d);
			lim[1][t] = min(lim[1][t], s[a][t] + d);
		}
	}
	for(int a=0;a<n;a++){
		test(s[a][0], 0);
		test(s[a][1], 1);
	}
}
