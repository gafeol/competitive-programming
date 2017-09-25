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

const int MAXN = 6123, MAXK = 112;

int n, m, k;
int s[MAXN];

ll dp[MAXN][MAXK], b, c;

ll cus(int i, int j){

}

void solve(int i, int j, int l, int r, int k){
	if(i > j) return ;
	int m = (i+j)/2;
	int opt;
	ll best = LLONG_MAX;
	for(int a=max(m, l);a<=min(j, r);a++){
		if(best > dp[a][k-1] + cus(m, a){
			best = dp[a][k-1] + cus(m, a);
		}
	}
}

int main (){
	scanf("%d%lld%lld", &n, &b, &c);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);	
	}
	s[n] = 0;
	
	for(int a=n-1;a>=0;a--){
		dp[a][0] = dp[a+1][0] + s[a];
	}
	printf("%lld ", dp[0][0] + b); 
	for(int a=1;a<n;a++){
		solve(0, n-1, 0, n-1, a);
		printf("%lld%s", dp[0][a] + b*(a+1), " \n"[(a == n-1)]);
	}
}
