#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

const double INF = DBL_MAX - 1e7;

int n, m, k;
ll s[MAXN];
double inv[MAXN], sum[MAXN], sinv[MAXN], v[MAXN];
	
double dp[MAXN][60];

double cus(int i, int j){
	return v[i] - v[j+1] - sinv[j+1]*(sum[i] - sum[j+1]);
}

void build(int i, int j, int l, int r, int kk){
	if(i > j)
		return ;
	int m = (i+j)/2;
	int opt = l;
	for(int a=l;a<=min(m-1, r);a++){
		if(dp[m][kk] > dp[a][kk-1] + cus(a+1, m)){
			dp[m][kk] = dp[a][kk-1] + cus(a+1, m);
			opt = a;
		}
	}
	build(i, m-1, l, opt, kk);
	build(m+1, j, opt, r, kk);
}

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<=n+1;a++){
		for(int b=0;b<=k+1;b++){
			dp[a][b] = INF;
		}
	}
	for(int a=1;a<=n;a++){
		scanf("%lld", &s[a]);
		inv[a] = (double)(1./s[a]);
	}
	for(int a=n;a>0;a--){
		sinv[a] = sinv[a+1] + inv[a];
		sum[a] = sum[a+1] + s[a];
		v[a] = v[a+1] + sinv[a]*s[a];
	}
	k--;
	for(int a=1;a<=n;a++){
		dp[a][0] = cus(1, a);
	}
	for(int a=1;a<=k;a++){
		build(1, n, 1, n, a);
	}
	printf("%.20f\n", dp[n][k]);

}
