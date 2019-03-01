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

const int MAXN = 252345;

int n, m, k;
int pai[MAXN], chainNo[MAXN], chainInd[MAXN], subsize[MAXN], nchain, degs, inichain[MAXN];

vector <int> adj[MAXN];

struct arv{
	int s, lz;
} tree[8*MAXN];

int h[MAXN];

int res;

void dfs(int v,int ant){
	pai[v] = ant;
	h[v] = h[ant]+1;
	subsize[v] = 1;
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt != ant){
			dfs(nxt,v);
			subsize[v] += subsize[nxt];
		}
	}
}

void HLD(int v){
	chainInd[v] = degs;
	chainNo[v] = nchain;
	int mai=-1, ind=-1;
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt == pai[v]) continue;
		if(mai < subsize[nxt]){
			mai = subsize[nxt];
			ind = nxt;
		}
	}

	if(inichain[nchain] == -1)
		inichain[nchain] = v;

	degs++;

	if(mai != -1)
		HLD(ind);

	for(int a =0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt == pai[v] || nxt == ind) continue;
		nchain++;
		HLD(nxt);
	}
}

void build(int idx,int i,int j){
	tree[idx].s = 0;
	tree[idx].lz = 0;
	if(i==j)
		return;
	int m = (i+j)/2;
	build(idx*2,i,m);
	build(idx*2+1,m+1,j);
}



void upd(int idx,int i, int j, int l, int r){
	if(i>r || j<l) return ;
	if(tree[idx].lz != 0){
		int m = (i + j)/2;
		tree[idx].lz = 0;
		if(i != j){
			tree[idx*2].s = m - i + 1 - tree[idx*2].s;
			tree[idx*2].lz ^= 1;
			tree[idx*2+1].s  = j - m - tree[idx*2+1].s;
			tree[idx*2+1].lz ^= 1;
		}
	}
	if(i >= l && j <= r){
		tree[idx].s = j - i + 1 - tree[idx].s;
		tree[idx].lz ^= 1;
		return ;
	}
	int m = (i+j)/2;
	upd(idx*2,i,m,l, r);
	upd(idx*2+1,m+1,j,l, r);
	tree[idx].s = tree[idx*2].s + tree[idx*2+1].s;
	return ;
}

void reset(){
	degs=1;
	nchain = 0;
	memset(inichain,-1,sizeof(inichain));
}


void updup(int u){
	int iniv = inichain[chainNo[u]];
	do{
		iniv = inichain[chainNo[u]];
		upd(1, 1, degs-1, chainInd[iniv], chainInd[u]);
		u = pai[iniv];
	} while(iniv != 1);
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<n;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	reset();
	h[1] = -1;
	dfs(1, 1);
	HLD(1);
	build(1,1,degs-1);

	scanf("%d", &m);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		updup(i);
		updup(j);
		printf("%d\n", tree[1].s);
	}
}

