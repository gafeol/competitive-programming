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
#define debug(args...)// fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, k;
ll m;
ll s[MAXN], e[MAXN];

int main (){
	scanf("%d%lld", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%lld", &s[a]);
	}
	for(int a=0;a<n;a++){
		scanf("%lld", e+a);
	}
	double i = 0, j = 1e9+1;
	clock_t clk = clock();
	while(((double)(clock() - clk))/CLOCKS_PER_SEC < 0.7){
		double mid = (i + j)/2.;
		debug("i %.3f j %.3f\n", i, j);
		double k = mid;
		int ok = 1;
		for(int a=0;a<n;a++){
			double pes = m + k;
			debug("a %d\n", a);
			double cost = pes/((double)s[a]);
			debug("pes %.3f cos %.3f\n",  pes, cost);
			if(cost > k){
				ok = 0;
				break;
			}
			k -= cost;	
			pes = m + k;
			cost = pes/((double)e[((a+1)%n)]);
			debug("pes %.3f cos %.3f\n",  pes, cost);
			if(cost > k){
				ok = 0;
				break;
			}
			k -= cost;
		}
		debug("OK %d\n", ok);

		if(ok)
			j = mid;
		else
			i = mid;
	}
	double res = (i + j)/2.;
	if(res > 1e9)
		puts("-1");
	else
		printf("%.10f\n", res);
}

