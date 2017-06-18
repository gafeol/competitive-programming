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

const int MAXN = 55, MASK = 8, INF = 0x3f3f3f3f;

int n, m, k;
int dp[MAXN][MASK][MASK][MASK][MASK];

inline int bits(int x){
	return __builtin_popcount(x);
}

int go(int i, int bm1, int bm2, int bm, int nxt){
	int &r = dp[i][bm1][bm2][bm][nxt];

	if(r != -1)
		return r;
	if(i == m){
		if(bm + nxt == 0)
			return r = 0;
		else
			return r = INF;
	}

	r = INF;

	int mrk = 0;
	mrk = bm;
	if((bm1&1) || (bm1&4))
		mrk |= 2;
	if((bm1&2))
		mrk |= 5;
	if((bm2&1))
		mrk |= 4;
	if((bm2&4))
		mrk |= 1;
	if((nxt&1))
		mrk |= 4;
	if((nxt&4))
		mrk |= 1;

	for(int nbm = 0;nbm < 8;nbm++){
		int pode = mrk;

		if((nbm&1) || (nbm&4))
			pode |= 2;
		if((nbm&2))
			pode |= 5;
		
		int novo = bm;
		
		int cus = 0;

		for(int a=0;a<3;a++){
			if((pode&(1<<a)) == 0){
				cus++;
				novo |= (1<<a);
			}
		}
	//	debug("com %d %d %d %d %d meu custo é %d e o novo bm e %d\n", bm1, bm2, bm, nxt, nbm, cus, novo);
	//	
		r = min(r, cus + bits(nbm) + go(i+1, bm2, novo, nxt, nbm)); 
	}
	//debug("dp[%d][%d][%d][%d][%d] = %d\n", i, bm1, bm2, bm, nxt, r);

	return r;
}

int main (){
	for_tests(t, tt){
		memset(dp, -1, sizeof(dp));
		scanf("%d%d", &n, &m);
		if(n == 1){
			printf("%d\n", m);
			continue;
		}
		else if(n == 2){
			int res = 4*(m/6);
			if(m%6 == 1)
				res += 2;
			else if(m%6 >= 2)
				res += 4;
			printf("%d\n", res); 
		}
		else{
			int res = n*m;
			for(int b = 0;b < 8;b++){
				res = min(res, bits(b) + go(0, 0, 0, 0, b)); 
			}
			printf("%d\n", res);
		}
	}
}
