#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<pii, ppi> ppp;
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

const int MAXN = 100001;

const ll INF = LLONG_MIN + 10000000000;

int n, m, k;
ll M[4][MAXN];
ll dp[4][MAXN][8][8];

ll go(int i, int j, int bef, int act){
	if(dp[i][j][bef][act] != INF) return dp[i][j][bef][act];
	ll &r = dp[i][j][bef][act];
	if(i == 2 && j == n)
		return r = 0;

	if(!(bef&(1<<i))){
		if(i < 2 && !(bef&(1<<(i+1))) && !(act&(1<<(i+1))))
			r = max(r, go(i+1, j, bef|((1<<i) + (1<<(i+1))), act|(1<<(i+1))) + M[i][j-1] + M[i+1][j-1] + M[i+1][j]);
		if(i > 0 && !(bef&(1<<(i-1))) && !(act&(1<<(i-1))))
			r = max(r, go(i-1, j, bef|((1<<i) + (1<<(i-1))), act|(1<<(i-1))) + M[i][j-1] + M[i-1][j-1] + M[i-1][j]);
	}

	if(i != 0 && !(act&(1<<(i-1))))
		r = max(r, go(i-1, j, bef, act|(1<<(i-1))) + M[i-1][j]);
	if(i != 2 && !(act&(1<<(i+1))))
		r = max(r, go(i+1, j, bef, act|(1<<(i+1))) + M[i+1][j]);
	if(j < n)
		r = max(r, go(i, j+1, act, (1<<i)) + M[i][j+1]);
	return r;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<3;a++){
		for(int b=0;b<=n;b++){
			for(int c=0;c<8;c++){
				for(int d=0;d<8;d++){
					dp[a][b][c][d] = INF;
				}
			}
		}
	}
	for(int a=0;a<3;a++){
		for(int b=1;b<=n;b++){
			scanf("%lld", &M[a][b]);
		}
	}
	printf("%lld\n", go(0, 0, 7, 7));
}
