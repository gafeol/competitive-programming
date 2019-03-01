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

int mrk[MAXN][2];

vector<pii> adj[MAXN];

bool go(int u, int pai, int p){
	if(mrk[u][p] != -1)
		return mrk[u][p];
	int t = p;
	mrk[u][p] = false;
	int &ok = mrk[u][p];
	for(auto ar: adj[u]){
		int v = ar.fst;
		if(v == pai) continue;
		bool t0 = go(v, u, 0), t1 = go(v, u, 1);	
		if(t0 && t1)
			ok = true;
		if(t0) 
			t ^= 1;
	}

	if(t == 0)
		ok = true;
	//printf("%d pai %d p %d: %d\n", u, pai, p, mrk[u][p]);
	return ok;
}

pii res[MAXN];

bool re(int u, int pai, int p){
	int both = -1, bid;
	for(auto ar: adj[u]){
		int v = ar.fst;
		int id = ar.snd;
		if(v == pai) continue;
		bool t0 = go(v, u, 0), t1 = go(v, u, 1);	
		if(t0 && t1){
			both = v;
			bid = id;
		}
	}

	for(auto ar: adj[u]){
		int v = ar.fst;
		int id = ar.snd;
		if(v == pai || v == both) continue;
		bool t0 = go(v, u, 0), t1 = go(v, u, 1);	
		if(t0){
			res[id] = {v, u};
			p ^= 1;
			re(v, u, 0);
		}
		else{
			res[id] = {u, v};
			re(v, u, 1);
		}

	}
	if(both != -1){
		res[bid] = (p ? pii(both, u) : pii(u, both));
		re(both, u, 1-p);
	}
}


pii ar[MAXN];

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &m);
		memset(mrk, -1, sizeof(mrk));
		for(int a=0;a<n;a++)
			adj[a].clear();
		for(int a=0;a<m;a++){
			int i, j;
			scanf("%d%d", &i, &j);
			i--;j--;
			ar[a] = {i, j};
			adj[i].pb({j, a});
			adj[j].pb({i, a});
		}
		if(go(0, 0, 0)){
			re(0, 0, 0);
			for(int a=0;a<m;a++){
				printf("%d ", (ar[a] != res[a]));
			}
		}
		else
			puts("-1");
	}
}

