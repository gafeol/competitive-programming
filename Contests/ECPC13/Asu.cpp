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
long double s[MAXN];

long double pi = acos(-1.), EPS = 1e-8;

int main (){
	freopen("zeriba.in", "r", stdin);
	for_tests(t, tt){
		scanf("%d", &n);
		long long mxl = 0;
		long long sum = 0;
		for(int a=0;a<n;a++){
			scanf("%Lf", &s[a]);
			mxl = max(mxl, ll(s[a]));
			sum += ll(s[a]);
		}
		printf("Case %d: ", tt);
		if(sum - ll(mxl) <= ll(mxl)){
			puts("can't form a convex polygon");
			continue;
		}
		long double i = mxl/2., j = 1e8;
		int cnt = 500;
		while(cnt--){
			long double r = (i+j)/2.;
			long double ang = 0;
			long double mx = 0;
			for(int a=0;a<n;a++){
				long double the = acos(1. - (s[a]*s[a])/(2.*r*r));
				if(isnan(the)){
					i = r;
					continue;
				}
				mx = max(mx, the);
				ang += the;
			}
			if(ang > 2*pi || mx > pi)
				i = r;
			else
				j = r;
		}
		printf("%.4Lf\n", i);
	}
}

