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

const int MAXN = 2123;

int n, m, k;
int s[MAXN];

int nxt[MAXN], pos[MAXN];

int dp[MAXN][MAXN];

int go(int i, int j){
	if(i == j) return dp[i][j] = 0; 
	if(dp[i][j] != -1) return dp[i][j];
	dp[i][j] = INT_MAX;
	if(i < n-1 && s[i] == s[i+1])
		dp[i][j] = go(i+1, j);
	if(s[j] == s[j-1])
		dp[i][j] = go(i, j-1);
	for(int k = i+2;k<=j;k++){
		if(s[k] != s[i]) continue;
		dp[i][j] = min(go(i+1, k-1) + 1 + go(k, j), dp[i][j]); 
	}
	dp[i][j] = min(dp[i][j], go(i+1, j)+1);
	return dp[i][j];
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &m);
	for(int a=0;a<=m;a++)
		pos[a] = n;
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		nxt[a] = pos[s[a]];
		pos[s[a]] = a;
	}
	printf("%d\n", go(0, n-1));
}
