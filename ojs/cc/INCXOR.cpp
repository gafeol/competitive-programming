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

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			scanf("%d", s+a);
		}
		ll res = 0;
		for(int a=0;a<(1<<5);a++){
			int fodeu = 0;
			int bm = 0;
			for(int i=0;i<4;i++){
				int b = ((a&(1<<i))>>i);
				int b1 = ((a&(1<<(i+1)))>>(1+i));
				if((s[a]>>30)^b > (s[a+1]>>30)^b1){
					fodeu = 1;
					break;
				}
				else if((s[a]>>30)^b < (s[a+1]>>30)^b1){
					bm |= 1;

				}
			}
			if(!fodeu)
				go(30, 
		}
		res = mod(res + go(30, 
	}
}
