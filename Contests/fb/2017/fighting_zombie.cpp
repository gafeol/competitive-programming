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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 4123;

const long double DEL = 1e-15;

int n, m, k;
char s[MAXN];

long double dp[7][22][MAXN], acu[7][22][MAXN];

int mx[] = {4, 6, 8, 10, 12, 20};
int inv[30];

void refresh(int d, int r){
	long double cnt = 0;
	for(int i=0;i<MAXN;i++){
		cnt += dp[d][r][i];
		dp[d][r][i] = cnt;
		acu[d][r][i] = dp[d][r][i];
		if(i != 0)
			acu[d][r][i] += acu[d][r][i-1];
	}
}

void pre(){
	for(int d=0;d<6;d++){
		dp[d][0][0] = 1;
	}
	for(int d=0;d<6;d++){
		for(int r=0;r<20;r++){
			for(int i=0;i<MAXN;i++){
				if(dp[d][r][i] > DEL){
					dp[d][r+1][i+1] += dp[d][r][i]/(long double)mx[d];
					dp[d][r+1][i+mx[d]+1] -= dp[d][r][i]/(long double)mx[d];
				}
			}
			refresh(d, r+1);
		}
	}
	inv[4] = 0;
	inv[6] = 1;
	inv[8] = 2;
	inv[10] = 3;
	inv[12] = 4;
	inv[20] = 5;
}

void printt(int i, int j, int h){
	//debug("acu[%d][%d][%d] = %.2Lf\n", i, j, h, acu[i][j][h]);
}

long double prob(int h, int x, int y){
	if(h <= 0) return 1.;
	if(h >= MAXN) return 0.;
	y = inv[y];
	printt(y, x, MAXN-1);
	printt(y, x, h-1);
	return acu[y][x][MAXN-1]-acu[y][x][h-1];
	//return (acu[y][x][MAXN-1] - acu[y][x][h-1])/acu[y][x][MAXN-1];
}

int main (){
	pre();
	for_tests(t, tt){
		scanf("%d%d", &k, &n);
		long double res = 0;
		for(int a=0;a<n;a++){
			char c;
			int x, y, z = 0;
			scanf("%dd%d%c", &x, &y, &c);
			if(c == '+' || c == '-'){
				scanf("%d", &z);
				if(c == '-')
					z = -z;
			}
			//debug("%d %d %d  %.5Lf\n", k-z, x, y, prob(k-z, x, y)); 
			res = max(res, prob(k-z, x, y));
		}
		printf("Case #%d: %.20Lf\n", tt, res);
	}
}
