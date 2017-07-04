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

vector<ll> s[4];


struct pd{
	ll x;
	int i[3];

	pd(ll xx, int ii, int iii){
		x = xx;
		i[1] = ii;
		i[2] = iii;
	}
	pd(){}

	bool operator < (const struct pd &o) const {
		return (x < o.x || (x == o.x && i[1] < o.i[1]));
	}
} dp[MAXN];

bool cmp(int a, int b){
	return a > b;
}

int main (){
	scanf("%d %d", &n, &m);
	ll res=0;
	for(int a=0;a<n;a++){
		ll w, val;
		scanf("%lld %lld", &w, &val);
		s[w].pb(val);
		if(w == 3)
			res+= val;
	}

	for(int i=1;i<=3;i++)
		sort(s[i].begin(), s[i].end(), cmp);

	dp[0] = (pd){0, 0, 0};
	for(int i=0;i<m;i++){
		dp[i+1] = max(dp[i], dp[i+1]);
		if(dp[i].i[1] != s[1].size())
			dp[i+1] = max(dp[i+1], pd(dp[i].x + s[1][dp[i].i[1]], dp[i].i[1] + 1, dp[i].i[2]));
		if(dp[i].i[2] != s[2].size())
			dp[i+2] = max(dp[i+2], pd(dp[i].x + s[2][dp[i].i[2]], dp[i].i[1], dp[i].i[2] + 1));
		debug("i %d dp %lld %d %d\n", i, dp[i].x, dp[i].i[1], dp[i].i[2]);
	}

	int i = 0, j = 0;
	ll ans = 0;
	for(int k=s[3].size();k >= 0;k--){
		if(m < 3*k){
			if(k > 0){
				res -= s[3][k-1];
			}
			continue;
		}
		int sob = m - 3*k;
		ans = max(ans, res + dp[sob].x);
		if(k > 0)
			res -= s[3][k-1];
	}
	printf("%lld\n", ans);
}
