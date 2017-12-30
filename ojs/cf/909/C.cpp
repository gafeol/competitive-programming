
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

const int MAXN = 5003;

int dp[MAXN][MAXN][2];

int n, m, k;
char s[MAXN];

int go(int i, int h, int st){
	if(h < 0) return 0;
	if(i == n)
		return dp[i][h][st] = (st == 1);
	if(dp[i][h][st] != -1) return dp[i][h][st];

	int &r = dp[i][h][st];

	r = 0;
	if(st)
		r = mod(r + go(i, h-1, st));
	if(s[i] == 's'){
		if(st == 0)
			return r = go(i+1, h, 1);
		else
			r = mod(r + go(i+1, h, 1));
	}
	else
		r = mod(r + go(i+1, h+1, 0));
	return r;	
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf(" %c", &s[a]);
	}
	printf("%d\n", go(0, 0, 1));
}

