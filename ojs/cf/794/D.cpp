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

const int MAXN = 312345;

int n, m, k;
int s[MAXN];

map<vector<int>, int> ind;
vector<int> adj[MAXN], adj2[MAXN];

int mrk[MAXN], cor[MAXN], c, cv[MAXN];

void go(int u){
	cor[u] = c++;
	for(int nxt: adj[u]){
		if(cor[nxt] == 0)
			go(nxt);
	}
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		adj2[i].pb(j);
		adj2[j].pb(i);
	}
	int deg = 1;
	for(int a=1;a<=n;a++){
		adj2[a].pb(a);
		sort(adj2[a].begin(), adj2[a].end());
		if(ind.find(adj2[a]) == ind.end())
			ind[adj2[a]] = deg++;
		debug("u %d comp %d\n", a, ind[adj2[a]]);
	}
	for(int a=1;a<=n;a++){
		for(int nxt: adj2[a]){
			if(ind[adj2[a]] != ind[adj2[nxt]])
				adj[ind[adj2[a]]].pb(ind[adj2[nxt]]);
		}
	}
	int has = 0;
	for(int a=1;a<deg;a++){
		sort(adj[a].begin(), adj[a].end());
		adj[a].erase(unique(adj[a].begin(), adj[a].end()), adj[a].end());
		if(adj[a].size() > 2){
			printf("NO\n");
			return 0;
		}
		else
			has = 1;
	}
	if(!has){
		puts("NO");
		return 0;
	}
	c = 1;
	for(int a=1;a<deg;a++){
		if(cor[a] == 0 && adj[a].size() < 2){
			debug("go(%d)\n", a);
			go(a);
		}
	}
	puts("YES");
	for(int a=1;a<=n;a++){
		printf("%d ", cor[ind[adj2[a]]]);
	}
	printf("\n");
}
