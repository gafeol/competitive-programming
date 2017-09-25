
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

long long inf = modn*modn;

const int MAXN = 6123;

long long n, b, c;
long long s[MAXN];
long long cR[MAXN][MAXN], cL[MAXN][MAXN];
long long memo[MAXN][MAXN], dp[MAXN][MAXN];

long long custoL(int i, int j) {
	if (j < i) return 0;
	else return cL[i][j];
}
long long custoR(int i, int j) {
	if (j < i) return 0;
	else return cR[i][j];
}
long long calc(int i, int j, int p) {
	return custoR(i, p-1) + custoL(p+1, j) + b;
}
long long memoCalc(int i, int j) {
	if (j < i) return inf;
	else return memo[i][j];
}
long long solve(int pos, int n2) {
	if (pos == -1) {
		if (n2 == 1) return b;
		else return inf;
	}
	if (dp[pos][n2] != -1) return dp[pos][n2];
	if (n2 == 1) return memo[0][pos];
	long long mn = inf;
	for (int i=pos-1;i>=-1;i--) {
		mn = min(mn, solve(i, n2-1) + memo[i+1][pos]);
	}
	return dp[pos][n2] = mn;
}

int main (){
	scanf("%lld %lld %lld", &n, &b, &c);
	for(int i=0;i<n;i++){
		scanf("%lld", &s[i]);
	}
	memset(dp, -1, sizeof(dp));
	for (int i=0;i<n;i++) {
		long long sum = 0;
		for (int j=i;j<n;j++) {
			sum += s[j];
			cR[i][j] = custoR(i, j-1) + c*sum;
		}
	}
	for (int i=n-1;i>=0;i--) {
		long long sum = 0;
		for (int j=i;j>=0;j--) {
			sum += s[j];
			cL[j][i] = custoL(j+1, i) + c*sum;
		}
	}
	for (int i=0;i<n;i++) {
		int p = i;
		for (int j=i;j<n;j++) {
			int flag = 1;
			while(flag) {
				if (p == j) break;
				long long k1 = calc(i, j, p);
				long long k2 = calc(i, j, p+1);
				if (k2 <= k1) {
					p++;
				}
				else flag = 0;
			}
			memo[i][j] = calc(i, j, p);
		}
	}
	for (int i=1;i<=n;i++) {
		printf("%lld%c", solve(n-1, i), " \n"[i==n]);
	}
}

