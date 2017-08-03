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

vector<int> adj[MAXN];

struct ares{
	int i, j, k;
} ar[MAXN];

struct qry{
	int u, v, k;
	int i;
} s[MAXN];

struct arv{
	int x, lz;
} tree[4*MAXN];

bool cmp2(ares a, ares b){
	return a.k < b.k;
}

bool cmp(qry a, qry b){
	return a.k < b.k;
}

int pre[MAXN], pos[MAXN], deg, h[MAXN];

void dfs(int u, int p){
	pre[u] = deg++;
	h[u] = h[p] + 1;
	for(int nxt: adj[u]){
		if(nxt == p) continue;
		dfs(nxt, u);
	}
	pos[u] = deg-1;
}

void upd(int idx, int i, int j, int l, int r, int x){
	if(i > r || j < l) return;
	if(tree[idx].lz != 0){
		int aux = tree[idx].lz;
		tree[idx].lz = 0;
		if(i != j){
			tree[idx*2].x ^= aux;
			tree[idx*2].lz ^= aux;
			tree[idx*2+1].x ^= aux;
			tree[idx*2+1].lz ^= aux;
		}
	}
	if(i >= l && j <= r){
		tree[idx].x ^= x;
		tree[idx].lz ^= x;
		return ;
	}
	int m = (i+j)>>1;
	upd(idx*2, i, m, l, r, x);
	upd(idx*2+1, m+1, j, l, r, x);
	tree[idx].x = tree[idx*2].x^tree[idx*2+1].x;
}

int qry(int idx, int i, int j, int l){
	if(l > j || l < i) return 0;
	if(tree[idx].lz != 0){
		int aux = tree[idx].lz;
		tree[idx].lz = 0;
		if(i != j){
			tree[idx*2].x ^= aux;
			tree[idx*2].lz ^= aux;
			tree[idx*2+1].x ^= aux;
			tree[idx*2+1].lz ^= aux;
		}
	}
	if(i == j)
		return tree[idx].x;
	int m = (i+j)>>1;
	return qry(idx*2, i, m, l) ^ qry(idx*2+1, m+1, j, l);
}

void refresh(int idx, int i, int j){
	tree[idx].x = tree[idx].lz = 0;
	if(i >= j) return;
	int m = (i+j)>>1;
	refresh(idx*2, i, m);
	refresh(idx*2+1, m+1, j);
}

int res[MAXN];

int main (){
	for_tests(t, tt){
		deg = 0;
		scanf("%d", &n);
		for(int a=0;a<n-1;a++){
			int i, j, k;
			scanf("%d %d %d", &i, &j, &k);
			adj[i].pb(j);
			adj[j].pb(i);
			ar[a].i = i;
			ar[a].j = j;
			ar[a].k = k;
		}
		scanf("%d", &m);
		for(int a=0;a<m;a++){
			scanf("%d %d %d", &s[a].u, &s[a].v, &s[a].k);
			s[a].i = a;
		}
		sort(ar, ar+n-1, cmp2);
		sort(s, s+m, cmp);
		h[1] = -1;
		dfs(1, 1);
		int j = 0;
		for(int i=0;i<m;i++){
			while(j < n-1 && ar[j].k <= s[i].k){
				int u = ar[j].i;
				if(h[ar[j].j] > h[ar[j].i])
					u = ar[j].j;
				debug("upd %d %d %d\n", pre[u], pos[u], ar[j].k);
				upd(1, 0, deg-1, pre[u], pos[u], ar[j].k); 
				j++;
			}
			res[s[i].i] = qry(1, 0, deg-1, pre[s[i].u]) ^ qry(1, 0, deg-1, pre[s[i].v]);
		}
		for(int a=0;a<m;a++){
			printf("%d\n", res[a]);
		}
		refresh(1, 0, deg-1);
		for(int a=1;a<=n;a++){
			adj[a].clear();
		}
	}
}

