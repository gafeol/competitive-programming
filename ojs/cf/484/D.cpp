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

const int MAXN = 1123456;

int n, m, k;
ll s[MAXN];
ll dp[MAXN];
int up[MAXN];

ll go(int i){
	ll &r = dp[i];
	if(r != -1)
		return r;
	if(i == n) return 0;
	dp[i] = max(dp[i], go(i+1));
	dp[i] = max(dp[i], go(up[i]+1) + abs(s[up[i]] - s[i]));
	if(up[i] > i)
		dp[i] = max(dp[i], go(up[i]) + abs(s[up[i]-1] - s[i]));
	return r;
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
	}
	int j = 0, d = -1;
	for(int i=0;i<n-1;i++){
		if(i == j)
			d = (s[i+1] >= s[i]);
		if(d == 1){
			while(j+1 < n && s[j+1] >= s[j])
				j++;
		}
		else if(d == 0){
			while(j+1 < n && s[j+1] <= s[j])
				j++;
		}
		up[i] = j;
	}
	up[n-1] = n-1;
	printf("%lld\n", go(0));
}

