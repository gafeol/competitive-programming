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

double go(double t){
	double mn  = 1e15;
	double mx = -1;
	for(int a=0;a<n;a++){
		double d = (t - s[a])*((double)v[a]);

		mn = min(mn, d);	
		mx = max(mx, d);
	}
	return mx-mn; 
}

int main (){
	while(scanf("%d", &n) != EOF && n != 0){
		double mint = -1;
		for(int a=0;a<n;a++){
			scanf("%lld %lld", &s[a], &v[a]);
			mint = max(mint, (double)s[a]);
		}
		double i = (double)mint, j = 1e12, eps = 1e-4;
		while(i < j && j - i > eps){
			double l = i + (j - i)/((double)3.);
			double r = j - (j - i)/((double)3.);
			if(r - l < eps) break;
			if(go(l) < go(r)){
				j = r;
			}
			else{
				i = l;
			}
		}
		printf("%.9f\n", go(i));
	}
}
