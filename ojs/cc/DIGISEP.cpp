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

const int MAXN = 312;

int n, m, x, y;
ll dp[MAXN][MAXN][11], sum[MAXN][MAXN];
char s[MAXN];

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

ll go(int i, int k, int d){
	if(dp[i][k][d] != -1)
		return dp[i][k][d];
	ll &r = dp[i][k][d];
	
	if(i == n-1){
		if(k >= x && k <= y)
			return r = sum[i-d][i];
		return r = -2;
	}
		

}

int main (){
	for_tests(t, tt){
		memset(dp, -1, sizeof(dp));
		scanf("%d", &n);
		scanf(" %s", s);
		for(int a=0;a<n;a++){
			ll val = 0;
			for(int b=a;b<n;b++){
				if(b - a > 11) break;
				val *= 10ll;
				val += s[b]-'0';
				sum[a][b] = val;
			}
		}
		scanf("%d %d %d", &m, &x, &y);
		printf("%lld\n", go(0, 0, 0)); 
	}
}
