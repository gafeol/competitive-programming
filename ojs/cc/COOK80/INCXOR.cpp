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

const int MAXN = 6, BM = (1<<5) + 10;


int n, m, k;
int s[MAXN];
ll dp[31][BM][BM];
ll res = 0;

int bv(int x, int i){
	return ((x>>i)&1);
}

ll go(int bit, int lox, int lo){
	//debug("go(%d %d %d):\n", bit, lox, lo);
	int loxx = lox, loo = lo;
	if(bit == -1)
		return 1;

	ll &r = dp[bit][lox][lo];

	if(r != -1)
		return r;

	r = 0;

	for(int a=0;a<(1<<n);a++){
		int fodeu = 0;
		lox = loxx;
		lo = loo;
		for(int i=0;i<n-1;i++){
			int b = bv(a, i);
			int b1 = bv(a, i+1);
			
			if(!bv(lo, i)){
				if(b > b1){
					fodeu = 1;
					break;
				}
				else if(b < b1)
					lo |= (1<<i);
			}

			if(!bv(lox, i)){
				if((bv(s[i],bit)^b) > (bv(s[i+1], bit)^b1)){
					fodeu = 1;
					break;
				}
				else if((bv(s[i], bit)^b) < (bv(s[i+1], bit)^b1))
					lox |= (1<<i);
			}
		}
		if(!fodeu){
	//		debug("	go(%d %d %d) -> go(%d %d %d)\n", bit, loxx, loo, bit-1, lox, lo);
			r = mod(r + go(bit-1, lox, lo)); 
		}
	}
	return r;
}

int main (){
	for_tests(t, tt){
		memset(dp, -1, sizeof(dp));
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			scanf("%d", s+a);
		}
		res = 0;
		for(int a=0;a<(1<<n);a++){
			int fodeu = 0;
			int bit = 30, lo = 0, lox = 0;
			for(int i=0;i<n-1;i++){
				int b = bv(a, i);
				int b1 = bv(a, i+1);

				if(b > b1){
					fodeu = 1;
					break;
				}
				else if(b < b1)
					lo |= (1<<i);

				if((bv(s[i],bit)^b) > (bv(s[i+1], bit)^b1)){
					fodeu = 1;
					break;
				}
				else if((bv(s[i], bit)^b) < (bv(s[i+1], bit)^b1))
					lox |= (1<<i);
			}
			if(!fodeu){
				res = mod(res + go(bit-1, lox, lo)); 
			}
		}
		printf("%lld\n", res);
	}
}
