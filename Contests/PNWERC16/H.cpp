
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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

ll n;
int k;
pll s[MAXN];
ll dp[MAXN];

int nxt[MAXN];

ll go(int i){
	if(dp[i] != -1) return dp[i];
	ll &r = dp[i];
	if(i == k)
		return r = 0;
	r = max(r, go(i+1));
	r = max(r, go(nxt[i]) + s[i].snd - s[i].fst + 1ll);
	return r;
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf("%lld%d", &n, &k);
	for(int a=0;a<k;a++){
		scanf("%lld%lld", &s[a].fst, &s[a].snd);
	}
	s[k] = pll((ll)1e18+1ll, (ll)1e18+1ll);
	sort(s, s+k+1);
	for(int a=0;a<k;a++){
		nxt[a]=upper_bound(s, s+k+1, pll(s[a].snd+1, -1)) - s; 
	}
	printf("%lld\n", n - go(0));
}

