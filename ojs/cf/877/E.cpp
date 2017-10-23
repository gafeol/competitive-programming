
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

#define end asdas

const int MAXN = 212345;

int n, m;

int p[MAXN], s[MAXN], cnt[MAXN], sz[MAXN];
int ini[MAXN], end[MAXN], deg;

struct arv{
	int lz, val;
} tree[MAXN*4];

int pos[MAXN];

char t[20];

vector<int> adj[MAXN];

void go(int u){
	pos[deg] = u;
	ini[u] = deg++;
	for(int nxt: adj[u]){
		if(nxt == p[u]) continue;
		go(nxt);
	}
	end[u] = deg-1;
}

void upd(int idx, int i, int j, int l, int r){
	if(i > r || j < l) return ;
	int m = (i + j)/2;
	if(tree[idx].lz != 0){
		tree[idx].lz = 0;
		if(i != j){
			tree[idx*2].val = (m - i + 1) - tree[idx*2].val; 
			tree[idx*2+1].val = (j - m) - tree[idx*2+1].val;
			tree[idx*2].lz ^= 1;
			tree[idx*2+1].lz ^= 1;
		}
	}
	if(i >= l && j <= r){
		tree[idx].val = j - i + 1 - tree[idx].val;
		tree[idx].lz ^= 1;
		return ;
	}
	upd(idx*2, i, m, l, r);
	upd(idx*2+1, m+1, j, l, r);
	tree[idx].val = tree[idx*2].val + tree[idx*2+1].val;
}

int qry(int idx, int i, int j, int l, int r){
	if(i > r || j < l) return 0;
	int m = (i + j)/2;
	if(tree[idx].lz != 0){
		tree[idx].lz = 0;
		if(i != j){
			tree[idx*2].val = (m - i + 1) - tree[idx*2].val; 
			tree[idx*2+1].val = (j - m) - tree[idx*2+1].val;
			tree[idx*2].lz ^= 1;
			tree[idx*2+1].lz ^= 1;
		}
	}
	if(i >= l && j <= r){
		return tree[idx].val;
	}
	return qry(idx*2, i, m, l, r) + qry(idx*2+1, m+1, j, l, r);
}

void build(int idx, int i, int j){
	tree[idx].lz = 0;
	if(i == j){
		tree[idx].val = s[pos[i]];
		return ;
	}
	int m = (i + j)/2;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
	tree[idx].val = tree[idx*2].val + tree[idx*2+1].val;
}

int main(){
	scanf("%d", &n);
	for(int a=2;a<=n;a++){
		scanf("%d", &p[a]);
		adj[p[a]].pb(a);
	}
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
	}
	go(1);
	build(1, 0, deg-1);
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		int u;
		scanf(" %s %d", t, &u);
		if(t[0] == 'p')
			upd(1, 0, deg-1, ini[u], end[u]);
		else
			printf("%d\n", qry(1, 0, deg-1, ini[u], end[u]));
	}
}

