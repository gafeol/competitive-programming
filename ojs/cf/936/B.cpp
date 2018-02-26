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
int mrk[MAXN][3];
int pre[MAXN][3];

vector<int> adj[MAXN];
int ini;

void go(int u, int t){
	mrk[u][t] = 1;
	int tt = t^1;
	for(int nxt: adj[u]){
		if(mrk[nxt][tt]) continue;
		pre[nxt][tt] = u;
		go(nxt, tt);
	}
}

stack<int> res;

void print(int u){
	int t = 1;
	while(u != -1){
		res.push(u);	
		u = pre[u][t];
		t = 1 - t;
	}
	puts("Win");
	while(!res.empty()){
		printf("%d ", res.top());
		res.pop();
	}
	puts("");
}

int dp[MAXN][2];

vector<int> inv[MAXN];
queue<int> q;
int deg[MAXN];
int los[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n;a++){
		int t;
		scanf("%d", &t);
		while(t--){
			int v;
			scanf("%d", &v);
			adj[a].pb(v);
			inv[v].pb(a);
			deg[a]++;
		}
	}
	scanf("%d", &ini);
	pre[ini][0] = -1;
	go(ini, 0);
	for(int a=1;a<=n;a++){
		if(adj[a].size() == 0){
			if(mrk[a][1]){
				print(a);
				return 0;
			}
			else if(mrk[a][0])
				q.push(a);
		}
	}
	while(!q.empty()){
		int u = q.front();
		los[u] = 1;
		q.pop();
		for(int nxt: inv[u]){
			deg[nxt]--;
			if(deg[nxt] == 0)
				q.push(nxt);
		}
	}
	if(los[ini])
		puts("Lose");
	else
		puts("Draw");
}

