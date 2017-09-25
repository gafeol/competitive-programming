
#include <bits/stdc++.h>
using namespace std;
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...)// fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, k;
ll m, dp[MAXN][4][11];
ll big;
int s[MAXN];
int pai[MAXN], bro[MAXN], fst[MAXN];
vector<int> adj[MAXN];

ll qtd(int t){
	if(t == 0)
		return big - 1;
	else if(t == 1)
		return 1;
	return m - big;
}

ll go(int u, int t, int cnt, int p){
	if(cnt == -1)
		return 0;
	if(u == -1)
		return (cnt == 0);
	debug("go %d %d %d %d\n", u, t, cnt, p);

	if(dp[u][t][cnt] != -1)
		return dp[u][t][cnt];

	dp[u][t][cnt] = 0; 

	for(int c=0;c<=cnt;c++){
		for(int tt=0;tt<3;tt++){
			if(t == 1 && tt != 0) continue;
			if(t == 2 && tt == 1) continue;
			dp[u][t][cnt] = mod(dp[u][t][cnt] + mod(qtd(tt)*go(fst[u], tt, c-(tt==1), u))*go(bro[u], t, cnt - c, p)); 
		}
	}

	debug("	dp[%d][%d][%d] p %d %lld\n", u, t, cnt, p, dp[u][t][cnt]);

	return dp[u][t][cnt];
}


void dfs(int u, int p){
	fst[u] = -1;
	pai[u] = p;
	int lst = -1;
	for(int nxt: adj[u]){
		if(nxt == p) continue;
		if(fst[u] == -1)
			fst[u] = nxt;
		if(lst != -1)
			bro[lst] = nxt;
		lst = nxt;
		bro[nxt] = -1;
		dfs(nxt, u);
	}
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf("%d%lld", &n, &m);
	int u;
	for(int a=0;a<n-1;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		u = i;
		adj[i].pb(j);
		adj[j].pb(i);
	}
	int c;
	scanf("%lld %d", &big, &c);
	bro[u] = -1;
	dfs(u, -1);
	ll ans = 0;
	for(int cc=0;cc<= c;cc++){
		ans = mod(ans + go(u, 0, cc, 0));
	}
	printf("%lld\n", ans);
}

