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
const int INF = 0x3f3f3f3f;

int n, m, k;
int dp[MAXN];
int ehp[MAXN][MAXN];

char s[MAXN];

int go(int i){
	if(dp[i] != INF) return dp[i];

	for(int j=i;j<n;j++){
		if(ehp[i][j])
			dp[i] = min(dp[i], go(j+1)+1);
	}

	return dp[i];
}

int main (){
	memset(dp, INF, sizeof(dp));
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf(" %c", &s[a]);
	}
	for(int i=0;i<n;i++)
		ehp[i][i] = 1;
	for(int t=1;t<n;t++){
		for(int i=0;i+t<n;i++){
			if(t == 1)
				ehp[i][i+t] = (s[i] == s[i+t]);
			else
				ehp[i][i+t] = (s[i] == s[i+t] && ehp[i+1][i+t-1]);
		}
	}
	dp[n] = 0;
	printf("%d", go(0));
}
