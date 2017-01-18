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

const int MAXN = 77, BIT = (1<<20)+10;

int n, m, k;
int s[MAXN];

int dp[MAXN][BIT];

int go(int i, int bm){
	if(dp[i][bm] != -1)
		return dp[i][bm];

	dp[i][bm] = (bm != 0 && __builtin_popcount(bm + 1) == 1);

	if(i == n)
		return dp[i][bm];


	int j = i;
	int val = 0;
	while(j < n){
		val *= 2;
		val += s[j];
		if(val > 20) break;
		if(val != 0){
			dp[i][bm] = mod(dp[i][bm] + go(j+1, bm|(1<<(val-1))));
		}

		j++;
	}
	return dp[i][bm];
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		char c;
		scanf(" %c", &c);
		s[a] = c - '0';
	}
	ll res = 0;
	for(int a=0;a<n;a++)
		res = mod(res + go(a, 0));
	printf("%lld\n", res);
}
