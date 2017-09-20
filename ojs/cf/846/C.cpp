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
ll s[MAXN];
ll dp[MAXN][4];

ll val(int i, int t){
	if(t&1) return s[i];
	return -s[i];
}

ll go(int i, int t){
	if(dp[i][t] != -1)
		return dp[i][t];
	if(i == n)
		return dp[i][t] = 0;
	ll &r = dp[i][t];
	r = go(i+1, t) + val(i, t);
	if(t > 0)
		r = max(r, go(i, t-1));
	return r;
}

void build(int i, int t){
	if(i == n){
		while(t > 0){
			printf("%d ", i);
			t--;
		}
		return ;
	}
	ll &r = dp[i][t];
	if(r == go(i+1, t) + val(i, t)){
		build(i+1, t);
	}
	else if(t > 0 && r == go(i, t-1)){
		printf("%d ", i);
		build(i, t-1);
	}
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);	
	}
	go(0, 3);
	build(0, 3);
	puts("");
}

