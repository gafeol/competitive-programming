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

const int MAXN = 112;

int n, m, k;
int s[MAXN], M[MAXN][MAXN];
int dp[MAXN][MAXN][2], dp2[MAXN][MAXN][2];

int go(int i, int base, int t){
	if(i == n)
		return 0;
	if(dp[i][base][t] != -1)
		return dp[i][base][t];

	int &r = dp[i][base][t];

	int cus = 0;
	for(int a=0;a<m;a++){
		cus += (M[i][a] != (M[base][a]^t));	
		//	debug("M[%d][%d](%d) != M[%d][%d](%d)^%d eh %d\n", i, a, M[i][a], base, a, M[base][a], t, (M[i][a] != (M[base][a]^t)));
	}
	r = cus + min(go(i+1, base, 0), go(i+1, base, 1));	
	//debug("dp[%d][%d][%d] = %d (cus %d)\n", i, base, t, r, cus);
	return r;
}

int go2(int i, int base, int t){
	if(i == m)
		return 0;
	if(dp2[i][base][t] != -1)
		return dp2[i][base][t];

	int &r = dp2[i][base][t];

	int cus = 0;
	for(int a=0;a<n;a++){
		cus += (M[a][i] != (M[a][base]^t));	
		//	debug("M[%d][%d](%d) != M[%d][%d](%d)^%d eh %d\n", i, a, M[i][a], base, a, M[base][a], t, (M[i][a] != (M[base][a]^t)));
	}
	r = cus + min(go2(i+1, base, 0), go2(i+1, base, 1));	
	//debug("dp[%d][%d][%d] = %d (cus %d)\n", i, base, t, r, cus);
	return r;
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			scanf("%d", &M[a][b]);
		}
	}
	int res = INT_MAX;
	if(m <= k){
		for(int bm = 0;bm < (1<<m);bm++){
			int aux = bm;
			for(int a=0;a<m;a++){
				M[n][a] = (aux&1);
				aux >>= 1;
			}
			memset(dp, -1, sizeof(dp));
			res = min(res, min(go(0, n, 0), go(0, n, 1)));
		}
		if(res > k){
			puts("-1");
		}
		else
			printf("%d\n", res);
		return 0;
	}
	memset(dp, -1, sizeof(dp));
	memset(dp2, -1, sizeof(dp2));
	for(int a=0;a<n;a++){
		for(int b=0;b<2;b++)
			res = min(res, go(0, a, b));
	}

	for(int a=0;a<m;a++){
		for(int b=0;b<2;b++)
			res = min(res, go2(0, a, b));
	}
	debug("%d\n", res);
	if(res > k){
		puts("-1");
	}
	else
		printf("%d\n", res);
}
