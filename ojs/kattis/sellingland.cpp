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

const int MAXN = 1003;

int n, m;
pii dp[MAXN][MAXN];
char M[MAXN][MAXN];
int up[MAXN][MAXN], sum[MAXN][MAXN];

int res[MAXN*4];


inline int soma(int i, int j, int ii, int jj){
	return sum[ii][jj] - sum[ii][j-1] - sum[i+1][jj] + sum[i+1][j-1];
}

inline int bb(int pi, int pj, int h){
	int i = pj, j = m;
	while(i < j){
		int mid = (i+j+1)/2;
		if(soma(pi, pj, h, mid) == 0)
			i = mid;
		else
			j = mid-1;
	}
	return i;
}

inline int dist(int i, int j, int ii, int jj){
	return abs(i - ii) + abs(j - jj);
}

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &m);
		for(int a=0;a<=n+1;a++){
			for(int b=0;b<=m+1;b++){
				sum[a][b] = 0;
				up[a][b] = 0;
				M[a][b] = ' ';
			}
		}
		for(int a=1;a<=n;a++){
			for(int b=m;b>0;b--){
				scanf(" %c", &M[a][b]);
				sum[a][b] = 0;
				sum[a][b] = (M[a][b] == '#');
				if(M[a-1][b] != '.')
					up[a][b] = a;
				else
					up[a][b] = up[a-1][b];

			}
		}
		for(int a=n;a>0;a--){
			for(int b=1;b<=m;b++){
				sum[a][b] += sum[a+1][b] + sum[a][b-1] - sum[a+1][b-1];
			}
		}

		for(int a=1;a<=n;a++){
			for(int b=m;b>0;b--){
				if(M[a][b] == '#') continue;
				int j = bb(a, b, up[a][b]);	
				dp[a][b] = pii(up[a][b], j);
				if(M[a][j+1] == '.' &&  dist(a, b, up[a][b], j) < dist(a, b, dp[a][j+1].fst, dp[a][j+1].snd))
					dp[a][b] = dp[a][j+1];

				//debug("para cara %d %d res %d %d per %d\n", a, b, dp[a][b].fst, dp[a][b].snd, 2*(dist(a, b, dp[a][b].fst, dp[a][b].snd) + 2));

				res[2*(dist(a, b, dp[a][b].fst, dp[a][b].snd)+2)]++;
			}
		}
		for(int a=4;a<=(n+m+2)*2;a++){
			if(res[a] != 0){
				printf("%d x %d\n", res[a], a);
				res[a] = 0;
			}
		}
	}
}
