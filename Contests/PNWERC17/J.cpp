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

const int MAXN = 41;

int n, m, k;
int s[MAXN];

ll dp[MAXN][MAXN][MAXN];

char M[MAXN][MAXN];

ll go(int i, int j, int lm){
	if(dp[i][j][lm] != -1) return dp[i][j][lm];
	if(i == n+1) return 1;
	ll &r = dp[i][j][lm];
	r = 0;
	if(j > lm) return r = go(i+1, 1, lm);
	if(M[i][j] != '.'){
		int ni = i, nj = j+1;
		if(nj > lm){
			ni = i+1;
			nj = 1;
		}
		r = go(ni, nj, lm);
	}
	else{
		r = go(i+1, 1, j-1);
		int ni = i, nj = j+1;
		if(nj > lm){
			ni = i+1;
			nj = 1;
		}
		r += go(ni, nj, lm);
	}
	return r;
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			scanf(" %c", &M[a][b]);
		}
	}
	int res = 0;
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			if(M[a-1][b] == 'R' || M[a][b-1] == 'R'){
				if(M[a][b] == 'B')
					res = -1;
				M[a][b] = 'R';
			}
		}
	}
	for(int a=n;a>=1;a--){
		for(int b=m;b>=1;b--){
			if(M[a+1][b] == 'B' || M[a][b+1] == 'B'){
				if(M[a][b] == 'R')
					res = -1;
				M[a][b] = 'B';
			}
		}
	}
	memset(dp, -1, sizeof(dp));
	if(res == -1) 
		puts("0");
	else
		printf("%lld\n", go(1, 1, m));
}

