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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 201;

int n, m, k;
ll M[MAXN][MAXN];
ll dp[2*MAXN][2*MAXN][2];
ll ac[2*MAXN][2*MAXN][2];

inline pii conv(int i, int j){
	return pii(i+j, i - j + m-1);
}

bool valid(pii c){
	return (c.fst >= 0 && c.snd >= 0 && c.fst < 2*(n+m) && c.snd < 2*(n+m));
}

inline void go(int i, int j, int tempo){
	int t = (tempo&1);
	int ii = i + j, jj = i - j + m - 1;
	pii c = conv(i+tempo, j);
	dp[ii][jj][t] = ac[c.fst][c.snd][t^1]; 
	int cnt = 0;
	c = conv(i, j-tempo);
	c.fst--;
	if(valid(c)){
		cnt++;
		dp[ii][jj][t] -= ac[c.fst][c.snd][t^1];
	}
	c = conv(i, j+tempo);
	c.snd--;
	if(valid(c)){
		cnt++;
		dp[ii][jj][t] -= ac[c.fst][c.snd][t^1];
	}
	c = conv(i-tempo, j);
	c.fst--;c.snd--;
	if(valid(c) && cnt == 2){
		dp[ii][jj][t] += ac[c.fst][c.snd][t^1];
	}
	dp[ii][jj][t] = mod(mod(dp[ii][jj][t]) + modn);
}

ll acc(int t){
	for(int a=0;a<2*(n+m);a++){
		for(int b=0;b<2*(n+m);b++){
			ac[a][b][t] = dp[a][b][t];
			if(a > 0)
				ac[a][b][t] += ac[a-1][b][t];
			if(b > 0)
				ac[a][b][t] += ac[a][b-1][t];
			if(a > 0 && b > 0)
				ac[a][b][t] -= ac[a-1][b-1][t];
			ac[a][b][t] = mod(ac[a][b][t]);

		}
	}
	for(int a=0;a<2*(n+m);a++){
		for(int b=0;b<2*(n+m);b++){
			debug("%lld ", dp[a][b][t]);
		}
		debug("\n");
	}
	debug("\n");
	for(int a=0;a<2*(n+m);a++){
		for(int b=0;b<2*(n+m);b++){
			debug("%lld ", ac[a][b][t]);
		}
		debug("\n");
	}
}

int main (){
	freopen("treasures.in", "r", stdin);
	for_tests(t, tt){
		int T, i, j;
		scanf("%d%d%d%d%d", &n, &m, &T, &i, &j);
		i--;j--;
		memset(dp, 0, sizeof(dp));
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				scanf("%lld", &M[a][b]);
				dp[a+b][a-b+m-1][0] = M[a][b];
			}
		}
		acc(0);
		for(int tempo = 1;tempo < T;tempo++){
			for(int a=0;a<n;a++){
				for(int b=0;b<m;b++){
					go(a, b, tempo);
				}
			}
			acc(tempo);
		}
		printf("Case %d: %lld\n", tt, dp[i+j][i-j+m-1][(T&1)^1]);
	}
}

