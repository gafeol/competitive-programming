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

const int MAXN = 51234;

int n, m, k;
int s[MAXN];
int mrk[MAXN];

int fodeu = 0;

vector<pii> adj[MAXN];

void dfs(int u, int p, int c){
	mrk[u] = 1;
	for(pii ar: adj[u]){
		int nxt = ar.snd;
		if(nxt == p) continue;
		int cn = ar.fst;	
		if(cn == c){
			puts("0");
			exit(0);
		}
		dfs(nxt, u, cn);
	}
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<n;a++){
		int i, j, c;
		scanf("%d%d%d", &i, &j, &c);
		adj[i].pb(pii(c, j));
		adj[j].pb(pii(c, i));
	}
	vector<int> ans;
	for(int a=1;a<=n;a++){
		if(mrk[a]) continue;
		sort(adj[a].begin(), adj[a].end());
		for(int b=1;b<adj[a].size();b++){
			if(adj[a][b-1].fst == adj[a][b].fst){
				dfs(adj[a][b-1].snd, a, adj[a][b-1].fst);
				if(b == adj[a].size()-1 || adj[a][b+1].fst != adj[a][b].fst)
					dfs(adj[a][b].snd, a, adj[a][b].fst);
			}
		}
	}
	for(int a=1;a<=n;a++)
		if(!mrk[a])
			ans.pb(a);
	printf("%d\n", (int)ans.size());
	for(int u: ans)
		printf("%d\n", u);
}

