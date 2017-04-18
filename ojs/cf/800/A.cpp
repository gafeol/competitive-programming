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

int n, m, k, p;
int s[MAXN], c[MAXN];

bool go(double t){
	double has = t*p;
	for(int a=0;a<n;a++){
		if(c[a]*t > s[a])
			has -= (c[a]*t) - s[a];
	}
	return (has >= 0);
}

int main (){
	clock_t clk = clock();
	scanf("%d%d", &n, &p);
	for(int a=0;a<n;a++){
		scanf("%d %d", &c[a], &s[a]);
	}
	double i = 0, j = 1e10 + 1;
	while(((double)clock() - clk)/CLOCKS_PER_SEC < 1.8){
		double m = (i + j)/2.;
		if(go(m))
			i = m; 
		else
			j = m;
	}
	if(i > 1e10)
		puts("-1");
	else
		printf("%.10f\n", i);
}
