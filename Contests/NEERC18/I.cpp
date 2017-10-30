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

const int MAXN = 312345;

int n, m;
ll k;
ll s[MAXN];

int dp[MAXN], ac[MAXN];

int bb(int i, int j, ll val){
	while(i < j){
		int m = (i + j)/2;
		if(s[m] >= val)
			j = m;
		else
			i = m+1;
	}
	return i;
}

bool go(ll d){
//	debug("test %lld\n", d);
	memset(dp, 0, sizeof(dp));
	memset(ac, 0, sizeof(ac));
	if(s[k] - s[1] > d) return 0;
	dp[0] = 1;
	ac[0] = 1;
	for(int a=1;a<k;a++){
		dp[a] = 0;
		ac[a] = ac[a-1];
	}
	dp[k] = 1;
	ac[k] = 2;
	for(int i=k+1;i<=n;i++){
		int jj = bb(0, i-k+1, s[i] - d); 
//		debug("jj %d\n", jj);
		if(s[jj] >= s[i] - d){
			int bef = 0;
			if(jj > 1)
				bef = ac[jj-2];
			dp[i] = (ac[i-k] - bef > 0);
		}
		ac[i]  = ac[i-1] + dp[i];
//		debug("i %d dp %d ac %d\n", i, dp[i], ac[i]);
	}
	return dp[n];
}

int main (){
	scanf("%d%lld", &n, &k);
	for(int a=1;a<=n;a++){
		scanf("%lld", s+a);
	}
	sort(s+1, s+n+1);
	ll i = 0, j = 1000000000LL;
	while(i < j){
		ll m = (i + j)/2;
		if(go(m))
			j = m;
		else
			i = m+1;
	}
	printf("%lld\n", i);
}

