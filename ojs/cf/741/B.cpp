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

const int MAXN = 2123;

int n, m, k;
int s[MAXN], w[MAXN], pai[MAXN], sz[MAXN];
ll dp[MAXN][2];

int cs[MAXN], cw[MAXN];

vector<int> hos[MAXN];

int raiz(int i){
	if(pai[i] == i)
		 return i;
	return pai[i] = raiz(pai[i]);
}

void join(int i, int j){
	i = raiz(i);
	j = raiz(j);
	if(i == j) return;
	if(sz[i] < sz[j]) swap(i, j);
	sz[i] += sz[j];
	pai[j] = i;
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
	for(int a=1;a<=n;a++){
		pai[a] = a;
		sz[a] = 1;
		scanf("%d", &w[a]);
	}
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
	}
	for(int a=1;a<=m;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		join(i, j);
	}
	for(int a=1;a<=n;a++){
		hos[raiz(a)].pb(a);
		cw[raiz(a)] += w[a];
		cs[raiz(a)] += s[a];
		debug("bota %d no grupo %d\n", a, raiz(a));
	}
	int inv = 0;
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for(int a=1;a<=n;a++){
		if(hos[a].empty()) continue;
		for(int i=0;i<=k;i++){
			if(dp[i][inv] != -1){
				dp[i][inv^1] = max(dp[i][inv^1], dp[i][inv]);
				if(i + cw[a] <= k){
					dp[i+cw[a]][inv^1] = max(dp[i+cw[a]][inv^1], dp[i][inv] + cs[a]);
					debug("group %d cw %d cs %d\n", a, cw[a], cs[a]);
					debug("dp[%d + %d] = %lld\n", i, cw[a], dp[i+cw[a]][inv^1]);
				}
				for(int h: hos[a]){
					if(i + w[h] <= k)
						dp[i+w[h]][inv^1] = max(dp[i+w[h]][inv^1], dp[i][inv]+s[h]);
				}
			}
		}
		for(int i=0;i<=k;i++){
			dp[i][inv] = -1;
		}
		inv^=1;
	}
	ll res = 0;
	for(int a=0;a<=k;a++){
		res = max(res, dp[a][inv]);
		debug("dp[%d] = %lld\n", a, dp[a][inv]);
	}
	printf("%lld\n", res);
}
