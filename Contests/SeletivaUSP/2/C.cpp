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

const int MAXN = 21234, INF = 0x3f3f3f3f;

int n, m, k;
int dp[MAXN];
int deg[MAXN], snk[MAXN];
int mrk[MAXN], mrk2[MAXN], h[MAXN];
queue<int> q;
vector<int> v, adj[MAXN];

void go(int u){
	h[u] = 1;
	mrk[u] = 1;
	int mx = 0;
	for(int i =0;i < adj[u].size();i++){
		int nxt = adj[u][i];
		if(mrk[nxt]) continue;
		go(nxt);
		mx = max(h[nxt], mx);
	}
	h[u] += mx;
}

void add(int u, int d){
	mrk2[u] = 1;
	int mx = 0, im = -1;
	for(int i =0;i < adj[u].size();i++){
		int nxt = adj[u][i];
		if(mrk2[nxt]) continue;
		if(h[nxt] > mx){
			mx = h[nxt];
			im = nxt;
		}
	}
	if(im != -1)
		add(im, d+1);
	for(int i =0;i < adj[u].size();i++){
		int nxt = adj[u][i];
		if(mrk2[nxt] || nxt == im) continue;
		add(nxt, 1);
	}

	if(im == -1){
		v.pb(d);
		debug("no %d bota val %d\n", u, d);
	}
}

int main (){
	for_tests(t, tt){
		v.clear();
		memset(mrk, 0, sizeof(mrk));
		memset(mrk2, 0, sizeof(mrk2));
		memset(snk, 0, sizeof(snk));
		scanf("%d%d%d", &n, &m, &k);
		for(int a=0;a<=n;a++){
			adj[a].clear();
			deg[a] = 0;
		}
		for(int a=0;a<m;a++){
			int i, j;
			scanf("%d %d", &i, &j);
			adj[i].pb(j);
			adj[j].pb(i);
			deg[i]++;
			deg[j]++;
		}

		for(int a=1;a<=n;a++){
			debug("deg[%d] %d\n", a, deg[a]);
			if(deg[a] <= 1)
				q.push(a);
		}
		while(!q.empty()){
			int u = q.front();
			snk[u] = 1;
			q.pop();
			debug("sink %d\n", u);
			for(int i =0;i < adj[u].size();i++){
				int nxt = adj[u][i];
				deg[nxt]--;
				if(deg[nxt] == 1){
					q.push(nxt);
					debug("sinks %d\n", nxt);
				}
			}
		}
		int res = 0;
		for(int a=1;a<=n;a++){
			if(!snk[a]){
				res++;
				mrk[a] = 1;
				mrk2[a] = 1;
				for(int i =0;i < adj[a].size();i++){
					int nxt = adj[a][i];
					if(!snk[nxt]) continue;
					go(nxt);
					debug("to no u %d chamo %d snk[] %d\n", a, nxt, snk[nxt]);
					add(nxt, 1);
				}
			}
		}
		memset(dp, INF, sizeof(dp));
		dp[0] = 0;
		for(int a=0;a<v.size();a++){
			int val = v[a];
			for(int i=MAXN-1;i>=0;i--){
				if(dp[i] != INF)
					dp[i+val] = min(dp[i] + 1, dp[i+val]);
			}
		}
		for(int i=MAXN-1;i>=0;i--){
			if(dp[i] <= k){
				res += i;
				break;
			}
		}
		printf("%d\n", n-res);
	}
}

