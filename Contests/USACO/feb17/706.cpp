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

const int MAXN = 1123;

int n, m, k;
int s[MAXN][2], pos[MAXN][2];
int dp[MAXN][MAXN];

int go(int i, int j){
	if(dp[i][j] != -1)
		return dp[i][j];
	int &r = dp[i][j];

	if(i == n || j == n)
		return r = 0;
	
	r = max(r, go(i+1, j));
	r = max(r, go(i, j+1));
	if(abs(s[i][0] - s[j][1]) <= 4)
		r = max(r, go(i+1, j+1)+1);
	return r;
}

int main (){

	freopen("nocross.in", "r", stdin);
	freopen("nocross.out", "w", stdout);
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int b=0;b<2;b++){
		for(int a=0;a<n;a++){
			scanf("%d", &s[a][b]);
			pos[s[a][b]][b] = a;
		}
	}
	printf("%d\n", go(0, 0));
}
