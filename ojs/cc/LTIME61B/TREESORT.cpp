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
const int INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];

vector<int> adj[MAXN];

int mx[MAXN], mn[MAXN];

void dfs(int u){
	mx[u] = INT_MIN;
	mn[u] = INT_MAX;
	for(int nxt: adj[u]){
		dfs(nxt);
		mx[u] = max(mx[u], mx[nxt]);
		mn[u] = min(mn[u], mn[nxt]);
	}
	if(adj[u].empty()){
		mn[u] = s[u];
		mx[u] = s[u];
	}
}

int go(int u){
	if(adj[u].empty()) return 0;	
	if(mx[adj[u][0]] <= mn[adj[u][1]] || mn[adj[u][0]] >= mx[adj[u][1]]){
		int c = (mn[adj[u][0]] >= mx[adj[u][1]]);
		return max(-INF, c + go(adj[u][0]) + go(adj[u][1]));		
	}
	else
		return -INF;
}

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		for(int a=1;a<=n;a++){
			adj[a].clear();
			int l, r;

			scanf("%d %d", &l, &r);
			if(l == -1){
				s[a] = r;
			}
			else{
				adj[a].pb(l);
				adj[a].pb(r);
			}
		}
		dfs(1);
		int res = go(1);
		res = max(-1, res);
		printf("%d\n", res);
	}
}

