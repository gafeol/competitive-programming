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

const int MAXN = 1023;

int n, m, k;
int s[MAXN];
char M[5][MAXN];

int dp[MAXN][6][6][6][6];

int go(int i, int f1, int f2, int f3, int f4){
	int &r = dp[i][f1][f2][f3][f4];
	if(r != -1) return r;
	if(i == n) return r = 0;
	r = INT_MAX;
	int cost = 0;
	int f[5];
	for(int a=0;a<5;a++){
		cost += s[a];
		f[0] = max(f1, a);
		for(int b=0;b<5;b++){
			cost += s[b];
			f[1] = max(f2, b);
			if(a > 1)
				f[1] = max(f[1], a);
			for(int c=0;c<5;c++){
				cost += s[c];
				f[2] = max(f3, c);
				if(a > 2)
					f[2] = max(a, f[2]);
				if(b > 1)
					f[2] = max(b, f[2]);
				for(int d=0;d<5;d++){
					cost += s[d];
					f[3] = max(f4, d);
					if(a > 3)
						f[3] = max(a, f[3]);
					if(b > 2)
						f[3] = max(b, f[3]);
					if(c > 1)
						f[3] = max(c, f[3]);

					int ok = 1;
					for(int j=0;j<4;j++){
						if(M[j][i] == '*' && f[j] == 0)
							ok = 0;
					}

					if(ok)
						r = min(r, cost + go(i+1, max(0, f[0]-1), max(0,f[1]-1), max(0, f[2]-1), max(0, f[3]-1)));

					cost -= s[d];	
				}
				cost -= s[c];	
			}
			cost -= s[b];	
		}
		cost -= s[a];	
	}
	return r;
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int a=1;a<=4;a++)
		scanf("%d", s+a);
	for(int a=0;a<4;a++){
		for(int b=0;b<n;b++){
			scanf(" %c", &M[a][b]);
		}
	}
	printf("%d\n", go(0, 0, 0, 0, 0));	
}

