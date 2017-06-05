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

const int MAXN = 212345;

int n, m, k;
int x, y;
char s[MAXN];

vector<int> res;

int dp[MAXN][2];

int go(int i, int lo){
	if(i == n)
		return 1;
	if(dp[i][lo] != -1)
		return dp[i][lo];
		
	dp[i][lo] = 0;
	if(lo){
		// usa y
		dp[i][lo] = max(dp[i][lo], go(i+1, lo));
		if(dp[i][lo] == 1)
			res.pb(y);
	}
	else{
		if(y < s[i]-'0')
			dp[i][lo] = max(dp[i][lo], go(i+1, 1));
		if(y == s[i]-'0')
			dp[i][lo] = max(dp[i][lo], go(i+1, lo));

		if(dp[i][lo] == 1)
			res.pb(y);
		else{
			if(x <  s[i]-'0')
				dp[i][lo] = max(dp[i][lo], go(i+1, 1));
			if(x == s[i]-'0')
				dp[i][lo] = max(dp[i][lo], go(i+1, lo));
			if(dp[i][lo] == 1)
				res.pb(x);
		}
	}
	return dp[i][lo];
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf(" %s %d %d", s, &x, &y);
	n = strlen(s);
	if(x > y)
		swap(x, y);
	if(go(0, 0)){
		int ini = res.size()-1;
		while(res[ini] == 0 && ini >= 0)
			ini--;
		if(ini < 0){
			printf("-1");
		}
		for(int i = ini;i >= 0;i--){
			int x = res[i];
			printf("%d", x);
		}
		printf("\n");
	}
	else{
		if(n > 1){
			debug("cornerzito\n");
			for(int a=0;a<n-1;a++)
				printf("%d", y);
			printf("\n");
		}
		else
			puts("-1");
	}
}
