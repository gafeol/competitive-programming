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

const int MAXN = (1<<19) + 10;

int n,  k;
int s[MAXN];
double dp[MAXN][19], m[19][19];

double go(int bm, int u){
	if(dp[bm][u] != -1.)	
		return dp[bm][u];
	debug("go (%d %d)\n", bm , u);
	if(bm == (1<<n)-1)
		return dp[bm][u] = (u == 0);
		double &r = dp[bm][u];
	r = 0;
	for(int i=0;i<n;i++){
		int bit = (1<<i);
		if(bit&bm) continue;
		r = max(r, go(bm|bit, i)*m[i][u] + go(bm|bit, u)*m[u][i]);
	}
	return r;
}

int main (){
	for(int a=0;a<MAXN-2;a++){
		for(int b=0;b<19;b++){
			dp[a][b] = -1.;
		}
	}
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			scanf("%lf", &m[a][b]);	
		}
	}
	double res = -1;
	for(int a=0;a<n;a++){
		res = max(res, go((1<<a), a));
	}
	printf("%.10f\n", res);
}
