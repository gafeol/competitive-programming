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
const ll INF = 300000000000LL;

int n, m, k;
int s[MAXN];
int dp[MAXN][MAXN*MAXN];

vector<ll> pos;

int find(int x){
	return lower_bound(pos.begin(), pos.end(), x) - pos.begin();
}

ll go(int i, int p){
	int l = find(pos[p] - d);
	int r = find(pos[p] + d + 1);

	if(dp[i][p] != -1)
		return dp[i][p];

	if(i + 1 == n-1){
		int m = find(s[i+1]);
		if(i <= m && j >= m)
			return 0;
		return INF;
	}

	for(int a=l;a<r;a++){
		dp[i][p] = min(dp[i][p], go(i+1, a) + abs(s[i+1]);
	}

	return dp[i][p];
}

int main (){
	for_tests(t, tt){
		memset(dp, -1, sizeof(dp));
		scanf("%d %lld", &n, &d);
		for(int a=0;a<n;a++){
			scanf("%d", &s[a]);
			pos.pb(s[a]);
			pos.pb(s[a] + d);
			pos.pb(s[a] - d);
		}
		sort(pos.begin(), pos.end());
		pos.erase(unique(pos.begin(), pos.end()), pos.end());
		go(0, find(s[0]));
	}
}
