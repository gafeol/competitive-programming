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
ll s[MAXN];
ll v[MAXN];

long double go(long double t){
	long double mn  = DBL_MAX;
	long double mx = DBL_MIN;
	for(int a=0;a<n;a++){
		long double d = (t - s[a])*((long double)v[a]);

		mn = min(mn, d);	
		mx = max(mx, d);
	}
	return mx-mn; 
}

int main (){
	while(scanf("%d", &n) != EOF && n != 0){
		clock_t clk = clock();
		ll mint = LLONG_MIN;
		for(int a=0;a<n;a++){
			scanf("%lld %lld", &s[a], &v[a]);
			mint = max(mint, s[a]);
		}
		long double i = (long double)mint, j = 1e12;
		while(j - i > 0.000000001){
			long double l = i + (j - i)/3.;
			long double r = j - (j - i)/3.;
			if(go(l) < go(r)){
				j = r;
			}
			else{
				i = l;
			}
		}
		printf("%.9Lf\n", go(i));
	}
}
