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

const int MAXN = 1123;

int n, k;
ll t;
int s[MAXN];

int opt[MAXN][MAXN];
ll dp[MAXN][MAXN];



int main (){
	while(scanf("%lld%d", &t, &n)!= EOF && t+n){
		for(int a=1;a<=n;a++){
			scanf("%d", &s[a]);
		}
		n++;
		s[n] = t;
		s[0] = 0;
		opt[0][0] = 0;
		opt[n][n] = n;
		for(int a=0;a<=n;a++){
			for(int b=0;b<=n;b++){
				dp[a][b] = 1e15;
				opt[a][b] = -1;
				if(a >= b){
					dp[a][b] = 0;
					opt[a][b] = a;
				}
				if(b == a+1){
					dp[a][b] = 0;
					opt[a][b] = a;
				}
				if(b == a+2){
					dp[a][b] = s[b] - s[a];
					opt[a][b] = a+1;
				}
			}
		}

		for(int tam = 3;tam <= n;tam++){
			for(int i =0;i+tam <= n;i++){
				//printf("calculando dp[%d][%d]:\n", i, i+tam);
				for(int k = opt[i][i+tam-1];k<= opt[i+1][i+tam];k++){
					//	printf("	testa k %d\n	testa %lld + %lld + s[%d] %d - s[%d] %d + 1\n", k, dp[i][k], dp[k][i+tam], i+tam, s[i+tam], i, s[i]);
					if(dp[i][i+tam] > dp[i][k] + dp[k][i+tam] + s[i+tam] - s[i]){
						dp[i][i+tam] = dp[i][k] + dp[k][i+tam] + s[i+tam] - s[i];
						opt[i][i+tam] = k;
					}
				}
				//	printf("CALCULEI\ndp[%d][%d] %lld\nopt[%d][%d] %d\n\n", i, i+tam, dp[i][i+tam], i, i+tam, opt[i][i+tam]);
			}
		}
		printf("%lld\n", dp[0][n]);


	}
}
