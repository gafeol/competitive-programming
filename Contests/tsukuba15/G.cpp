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
char s[MAXN];

ll sz[MAXN][MAXN], dp[MAXN][MAXN];

int len(int i, int j){
	if(i == j)
		return sz[i][j] = 1;
	if(i > j)
		return 0;
	if(sz[i][j] != INF)
		return dp[i][j];
	if(s[i] == s[j])
		dp[i][j] = len(i+1, j-1) + 2;
	else
		dp[i][j] = min(len(i+1, j), len(i, j-1)) + 2;
	return dp[i][j];
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){

	}
}

