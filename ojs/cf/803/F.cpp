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

const int MAXN = 212345, LOGN = 18;

int n, m, k;
int s[MAXN];
int dp[MAXN][LOGN];

ll res;

int gcd(int a, int b){
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

int find(int i){
	int j = i;
	if(s[i] == 1)
		return j;
	int sob = 0;
	for(int p = LOGN-1;p >= 0;p--){
		if(gcd(dp[j][p], sob) != 1){
			sob = gcd(dp[j][p], sob);
			j = j + (1<<p);
		}
		if(j > n)
			break;
	}
	return j-1;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		dp[a][0] = s[a];
	}
	for(int b=1;b<LOGN;b++){
		for(int a=0;a<n;a++){
			if((1<<b) + a < n)
				dp[a][b] = gcd(dp[a][b-1], dp[a+(1<<b)][b-1]);
			else
				dp[a][b] = 1;
		}
	}
	for(int i = 0;i<n;i++){
		int p = 0;
		int j = find(i);
		debug("i %d j %d\n", i, j);
		res = mod(res + (ll)n-j);
	}
	printf("%lld\n", res);
}
