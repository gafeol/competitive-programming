#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define int ll
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 512345;

int n, m, k;
int s[MAXN];
int L[MAXN];
int bit[MAXN], res[MAXN];
int tempo;

vector<int> adj[2][MAXN]; 

void lin(int u, int p){
	L[u] = tempo++;
	assert(tempo < MAXN);

	for(int nxt: adj[0][u]){
		if(nxt == p) continue;
		lin(nxt, u);
	}
}

int qry(int i){
	i += 2;
	int ans = 0;
	while(i > 0){
		ans += bit[i];
		i -= (i&-i);
	}
	return ans;
}

void upd(int i, int val){
	i += 2;
	while(i < MAXN){
		bit[i] += val;
		i += (i&-i);
	}
}

void go(int u, int p){
	assert(L[u] != 0);
	res[u] = qry(L[u]);
	upd(L[u], 1);
//	debug("liga L[%lld] %lld 1\n", u, L[u]);
	for(int nxt: adj[1][u]){
		if(nxt == p) continue;
		go(nxt, u);
	}
//	debug("liga R[%lld] %lld -1\n", u, R[u]);
	upd(L[u], -1);
}

main (){
	for_tests(t, tt){
		tempo = 1;
		scanf("%lld", &n);
		for(int tp=0;tp<2;tp++){
			for(int a=0;a<n-1;a++){
				int i, j;
				scanf("%lld %lld", &i, &j);
				adj[tp][i].pb(j);
				adj[tp][j].pb(i);
			}
		}

		lin(1, 0);
		go(1, 0);

		for(int a=1;a<=n;a++){
			adj[0][a].clear();
			adj[1][a].clear();
			assert(L[a] != 0);
			printf("%lld ", res[a]);
		}
		printf("\n");
	}
}
