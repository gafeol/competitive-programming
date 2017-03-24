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

ll go(int bit, int lox, int lo){
	debug("go(%d %d %d):\n", bit, bm, w);
	if(bit == -1)
		return (lo == (1<<(n-1))-1 && lo == lox);

	ll &r = dp[bit][bm][w];

	if(r != -1)
		return r;

	for(int a=0;a<(1<<n);a++){
		int fodeu = 0;
		int bm = 0;
		for(int i=0;i<n-1;i++){
			if(lo|(1<<i) && lox|(1<<i)) continue;

			int b = ((a&(1<<i))>>i);
			int b1 = ((a&(1<<(i+1)))>>(1+i));
			if((s[i]>>bit)^b > (s[i+1]>>bit)^b1 || b > b1){
				fodeu = 1;
				break;
			}
			else if((s[i]>>bit)^b < (s[i+1]>>bit)^b1){
				bm |= (1<<i);

			}
		}
		if(!fodeu){
			debug("	go(%d %d %d) -> go(%d %d %d)\n", bit, bm, w, bit-1, bm, a);
			r = mod(r + go(bit-1, bm, a)); 
		}
	}

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
			int bm = 0;
			for(int i=0;i<n-1;i++){
				int b = ((a&(1<<i))>>i);
				int b1 = ((a&(1<<(i+1)))>>(1+i));
				if((s[i]>>30)^b > (s[i+1]>>30)^b1){
					fodeu = 1;
					break;
				}
				else if((s[i]>>30)^b < (s[i+1]>>30)^b1){
					bm |= (1<<i);

				}
			}
			if(!fodeu)
				res = mod(res + go(29, bm, a)); 
		}
		printf("%lld\n", res);
	}
}
