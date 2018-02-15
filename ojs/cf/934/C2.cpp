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
int s[MAXN];

int dp[MAXN][4];

int go(int i, int t){
	if(dp[i][t] != -1) return dp[i][t];
	int &r = dp[i][t];
	if(i == n) return r = 0;
	int num = (t&1) + 1;
	r = max(r, go(i+1, t) + (num == s[i]));	
	if(t < 3)
		r = max(r, go(i, t+1));
	return r;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0, 0));
}

