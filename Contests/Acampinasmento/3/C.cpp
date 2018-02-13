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

const int MAXN = 262, INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN*MAXN];

bool cmp(int a, int b){
	return a > b;
}

int dp[MAXN][MAXN];

int go(int i, int j){
	if(i > n || j > m) return INF;
	if(dp[i][j] != -1) return dp[i][j];
	if(i*j == n*m) return 0;
	int a = i*j;
	dp[i][j] = 2*s[a] + min(go(i, j+1), go(i+1, j));	
	return dp[i][j];
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &m);
	for(int a=0;a<n*m;a++){
		scanf("%d", s+a);
	}
	sort(s, s+n*m, cmp);
	printf("%d\n", 4*s[0]+go(1, 1));
}
