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

const int MAXN = 645;

int n, m, k;
int M[MAXN][MAXN];
int dp[MAXN][MAXN];

stack<pii> q; 

int main (){
	while(scanf("%d%d", &n, &m) && n+m != 0){
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				scanf("%d", &M[a][b]);
			}
		}
		for(int a=0;a<n;a++){
			M[a][m] = INT_MIN;
			dp[a][m] = 0;
			for(int b=m-1;b>=0;b--){
				if(M[a][b] >= M[a][b+1])
					dp[a][b] = 0;
				else
					dp[a][b] = dp[a][b+1] + 1;
			}
		}
		int res =0;
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				int h = dp[a][b];
				res = max(h+1, res);
				for(int c=a+1;c<n;c++){
					h = min(h, dp[c][b]);
					while(h >= 0 && M[c-1][b+h] >= M[c][b])
						h--;
		//			debug("a %d b %d c %d h %d\n", a, b, c, h);
					if(h < 0) break;
					res = max(res, (h+1)*(c - a + 1));
				}
			}
		}
		printf("%d\n", res);
	}
}
