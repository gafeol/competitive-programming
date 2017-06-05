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

const int MAXN = 512345;

int n, m, k;
int s[MAXN], cnt[MAXN];
ll sum[MAXN];
ll dp[MAXN];

set<int> mex;

void add(int x){
	if(x >= MAXN)
		return ;
	if(cnt[x] == 0)
		mex.erase(x);
	cnt[x]++;
}

void rmv(int x){
	if(x >= MAXN)
		return ;
	if(cnt[x] == 1)
		mex.insert(x);
	cnt[x]--;
}

int main (){
	scanf("%d %d", &n, &k);
	int mn = INT_MAX;
	for(int a=0;a<MAXN;a++)
		mex.insert(a);
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);	
		mn = min(mn, s[a]);
	}
	if(k == 0 && mn == 0){
		puts("0");
		return 0;
	}
	int i = 1, j = 0;
	sum[0] = 1;
	dp[0] = 1;

	while(i <= n){
		add(s[i]);
		while((*mex.begin()) > k){
			rmv(s[j+1]);
			j++;
		}
		dp[i] = sum[i-1];
		if(j > 0)
			dp[i] -= sum[j-1];
		dp[i] = mod(mod(dp[i]) + modn);
		sum[i] = mod(sum[i-1] + dp[i]);
		i++;
	}
	printf("%lld\n", dp[n]);
}
