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

const int MAXN = 5123;

int n[2], k;
char s[2][MAXN];

int dp[MAXN][MAXN];

int go(int i, int j){
	if(dp[i][j] != -1) return dp[i][j];
	if(i == n[0] && j == n[1])
		return dp[i][j] = 0;

	int &r = dp[i][j];
	r = INT_MAX;
	if(s[0][i] == s[1][j])
		r = min(r, go(i+1, j+1) + 1);
	if(i < n[0])
		r = min(r, go(i+1, j) + 1);
	if(j < n[1])
		r = min(r, go(i, j+1) + 1);

	debug("dp %d %d = %d\n", i, j, dp[i][j]);
	return r;
}

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n[0], &n[1]);
		int deg[2];
		for(int i=0;i<2;i++){
			deg[i] = 0;
			for(int a=0;a<n[i];a++){
				char c;
				scanf(" %c", &c);	
				if(deg[i] != 0 && c == s[i][deg[i]-1])
					continue;
				s[i][deg[i]++] = c;
			}
			n[i] = deg[i];
		}

		for(int a=0;a<=n[0];a++){
			for(int b=0;b<=n[1];b++){
				dp[a][b] = -1;
			}
		}
		printf("%d\n", go(0, 0)); 
	}
}

