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
int s[MAXN];

ll dp[MAXN][2];

vector<int> adj[MAXN];
vector<ll> pr[MAXN], sf[MAXN];

ll go(int u, int p, int fnd){
	if(dp[u][fnd] != -1) return dp[u][fnd];

	ll &r = dp[u][fnd];
	if(adj[u].size() == 1 && p != -1){
		debug("go(%d %d %d) %d\n", u, p, fnd, (s[u] == fnd));
		return r = (s[u] == fnd);
	}

	if(!fnd && s[u]){
		debug("go(%d %d %d) 0\n", u, p, fnd);
		return r = 0;
	}


	ll mult = 1;
	pr[u].pb(1);
	for(int nxt: adj[u]){
		pr[u].pb(pr[u][pr[u].size()-1]);
		sf[u].pb(1);
		if(nxt == p) continue;
		go(nxt, u, 0);
		go(nxt, u, 1);
		mult = mod(mult * (dp[nxt][0] + dp[nxt][1]));
		pr[u][pr[u].size()-1] = mult;
	}
	mult = 1;
	sf[u].pb(1);
	for(int i =adj[u].size()-1;i >=0;i--){
		int nxt = adj[u][i];
		if(nxt == p) continue;
		mult = mod(mult * (dp[nxt][0] + dp[nxt][1]));
		sf[u][i] = mult;
	}
	r = 0;

	if((fnd && s[u]) || (!fnd && !s[u]))
		r = mult;
	else{

		for(int i = 0;i < adj[u].size();i++){
			int nxt = adj[u][i];
			if(nxt == p) continue;
			r = mod(r +	mod(dp[nxt][1]*mod(pr[u][i]*sf[u][i+1])));
		}
	}
	debug("go %d %d %d -> %lld\n", u, p, fnd, r);
	return r;
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int a=0;a<n-1;a++){
		int p;
		scanf("%d", &p);
		adj[p].pb(a+1);
		adj[a+1].pb(p);
	}
	for(int a=0;a<n;a++)
		scanf("%d", &s[a]);
	printf("%lld\n", go(0, -1, 1));
}
