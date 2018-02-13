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

const int MAXN = 513;

int n, m, k;
int s[MAXN];
int proi[MAXN][MAXN];

vector<int> adj[MAXN];

vector<pii> ar;

int mrk[MAXN], prv[MAXN], deg[MAXN];

void go(){
	queue<int> q;
	for(int a=1;a<=n;a++){
		if(deg[a] == 0)
			q.push(a);
	}
	int cnt = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		cnt++;
		for(int nxt: adj[u]){
			if(proi[u][nxt]) continue;
			deg[nxt]--;
			if(deg[nxt] == 0)
				q.push(nxt);
		}
	}
	if(cnt == n){
		puts("YES");
		exit(0);
	}
}

vector<int> cic;

void dfs(int u, int ini){
	mrk[u] = ini;
	for(int nxt: adj[u]){
		if(mrk[nxt] != ini){
			prv[nxt] = u;
			dfs(nxt, ini);
			if(!cic.empty())
				return ;
		}
		if(nxt == ini){
			int v = u;
			cic.pb(u);
			while(v != ini){
				v = prv[v];
				cic.pb(v);
			}
			return ;
		}
	}

}

int ideg[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		ar.pb(pii(i, j));
		adj[i].pb(j);
		ideg[j]++;
	}
	for(int a=1;a<=n && cic.empty();a++){
		dfs(a, a);
	}
	if(cic.empty()){
		puts("YES");
		return 0;
	}
	int tc = cic.size();
	for(int i=tc-1;i>=0;i--){
		int u = cic[i];
		int v = cic[(i+tc-1)%tc];
		debug("tenta %d - %d\n", u, v);
		for(int a=1;a<=n;a++){
			deg[a] = ideg[a];
			debug("%d - %d\n", a, deg[a]);
		}
		deg[v]--;
		debug("deg[%d]--\n", v);
		proi[u][v] = 1;
		go();
		proi[u][v] = 0;
	}
	puts("NO");
}

