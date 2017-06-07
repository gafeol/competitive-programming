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

const int MAXN = 2123456;

int n, m, k;
int s[MAXN];
int L[MAXN], R[MAXN];
int bit[MAXN], res[MAXN];
int tempo;

vector<int> adj1[MAXN], adj[MAXN]; 

void lin(int u, int p){
	L[u] = tempo++;

	for(int i = 0;i < adj1[u].size();i++){
		int nxt = adj1[u][i];
		if(nxt == p) continue;
		lin(nxt, u);
	}

	R[u] = tempo++;
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
	res[u] = qry(L[u]);

	upd(L[u], 1);
	upd(R[u], -1);

	for(int nxt: adj[u]){
		if(nxt == p) continue;
		go(nxt, u);
	}

	upd(L[u], -1);
	upd(R[u], 1);
}

int main (){
	for_tests(t, tt){
		tempo = 1;
		scanf("%d", &n);
		for(int a=1;a<=n;a++){
			adj[a].clear();
			adj1[a].clear();
		}
		for(int a=0;a<n-1;a++){
			int i, j;
			scanf("%d %d", &i, &j);
			adj[i].pb(j);
			adj[j].pb(i);
		}

		for(int a=0;a<n-1;a++){
			int i, j;
			scanf("%d %d", &i, &j);
			adj1[i].pb(j);
			adj1[j].pb(i);
		}
		lin(1, 1);
		go(1, 1);

		for(int a=1;a<=n;a++)
			printf("%d ", res[a]);
		printf("\n");
	}
}
