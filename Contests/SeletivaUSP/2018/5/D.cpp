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

const int MAXN = 505;

int n, m, k;
int s[MAXN];

double p, q;
double dp[MAXN][MAXN][MAXN];
int t[MAXN][MAXN][MAXN];
int tempo;

int main (){
	tempo = 1;
	while(scanf("%d %lf", &n, &p) != EOF){
		if(n == 0) return 0;
		for(int a=1;a<=n;a++)
			for(int mx=0;mx<=a;mx++)
				for(int lst=0;lst<=mx;lst++)
					dp[a][mx][lst] = 0;
		q = 1.-p;
		dp[0][0][0] = 1;
		for(int a=1;a<=n;a++){
			for(int mx=0;mx<=a;mx++){
				for(int lst=0;lst<=mx;lst++){
					dp[a][mx][0] += q*dp[a-1][mx][lst];
					dp[a][max(mx, lst+1)][lst+1] += p*dp[a-1][mx][lst];
				}
			}
		}
		double res = 0;
		for(int mx=0;mx<=n;mx++){
			for(int cnt=0;cnt<=mx;cnt++){
				res += dp[n][mx][cnt]*mx;
			}
		}
		printf("%.10f\n", res);
	}
}

