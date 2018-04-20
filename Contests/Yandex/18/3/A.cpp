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

#define int ll

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

set<int> q;

map<int, int> dp;

main (){
	scanf("%lld", &n);
	q.insert(-n);
	dp[n] = 0;
	while(!q.empty()){
		int u = -*q.begin();
		q.erase(q.begin());
		if(u == 0) continue;
		for(int i=1;i<=30;i++){
			int m = (1<<i);
			int r = (u%m);
			int v = u/m;
			if(2ll*((ll)r) > (ll)m)
				dp[v] = max(dp[v], dp[u] + 1);
			else
				dp[v] = max(dp[v], dp[u]);
			q.insert(-v);
		}
	}
	printf("%lld\n", dp[0]);
}

