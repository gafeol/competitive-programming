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

const int MAXN = 22, MASK = (1<<21);

int n, m, k;

ll dp[MAXN][MASK];
int vis[MAXN][MASK];;

int adj[MAXN][MAXN];
int deg[MAXN];

ll go(int u, int bm){
	if(vis[u][bm] != 0)
		return dp[u][bm];
	vis[u][bm] = 1;
	if(__builtin_popcount(bm) > 1)
		dp[u][bm] = (u==n-1) + 1;
	for(int i=0;i < deg[u];i++){
		int v = adj[u][i];
		if(bm&(1<<v)) continue;
		dp[u][bm] += go(v, bm|(1<<v));
	}
	return dp[u][bm];
}

vector<int> pos;

vector<int> v;

bool cmp(int a, int b){
	return __builtin_popcount(a) > __builtin_popcount(b);
}

int main (){
	scanf("%d %d", &n, &m);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		adj[i][deg[i]++] = j;
		adj[j][deg[j]++] = i;
	}
	for(int a=1;a<(1<<n)-1;a++){
		v.pb(a);
	}
	for(int a=0;a<n;a++)
		dp[a][(1<<n)-1] = 1;

	sort(v.begin(), v.end(), cmp);
	for(int bm: v){
		for(int u=0;u<n;u++){
			if(__builtin_popcount(bm) > 1)
				dp[u][bm] = 1;
			if(bm&(1<<u)){
				for(int a=0;a<deg[u];a++){
					int nxt = adj[u][a];
					if(bm&(1<<nxt)) continue;
					dp[u][bm] += dp[nxt][bm|(1<<nxt)];
				}
			}
		}
	}
	ll res=0;
	for(int a=0;a<n;a++){
		res += dp[a][(1<<a)];
	}
	printf("%lld\n", res);
}
