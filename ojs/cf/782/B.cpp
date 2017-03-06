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
int s[MAXN], v[MAXN];

bool go(double t){
	double mnu = DBL_MAX, mxd = -1;
	for(int a=0;a<n;a++){
		mnu = min((double)s[a] + v[a]*t, mnu);
		mxd = max((double)s[a] - v[a]*t, mxd);
	}
	return (mxd <= mnu);
}	

int main (){
	clock_t clk = clock();
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	for(int a=0;a<n;a++){
		scanf("%d", &v[a]);
	}

	double i = 0, j = 1e9;
	while(((double)clock() - clk)/CLOCKS_PER_SEC < 4.5){
		double m = (i+j)/2.;
		if(go(m))
			j = m;
		else
			i = m;
	}
	printf("%.10f\n", i);
}
