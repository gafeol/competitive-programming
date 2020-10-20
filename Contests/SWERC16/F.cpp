#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) // fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 112345;
const int LOGN = 20;

int n, m, k;
int r[MAXN], t[MAXN];
int root;
int pai[MAXN][LOGN], chainNo[MAXN], chainInd[MAXN], sz[MAXN], nchain, degs, inichain[MAXN], h[MAXN];
vector <int> adj[MAXN];

struct arv{ 
    ll val = 0;
    bool active=false;
    ll lz = 0;
} tree[8*MAXN];

void dfs(int v,int ant){
    //printf("dfs %d %d\n", v, ant);
	pai[v][0] = ant;
	h[v] = h[ant]+1;
	for(int a=1;a<LOGN;a++){
		pai[v][a] = pai[pai[v][a-1]][a-1];
	}
	sz[v] = 1;
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt != ant){
			dfs(nxt,v);
			sz[v] += sz[nxt];
		}
	}
}

void HLD(int v){
    //printf("v %d degs %d\n", v, degs);
	chainInd[v] = degs++;
	chainNo[v] = nchain;
    if(inichain[nchain] == -1){
        inichain[nchain] = v;
    }
	int mai=-1, ind=-1;
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt == pai[v][0]) continue;
		if(mai < sz[nxt]){
			mai = sz[nxt];
			ind = nxt;
		}
	}
	if(mai != -1){
		HLD(ind);
	}
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt == pai[v][0] || nxt == ind) continue;
		nchain++;
		HLD(nxt);
	}
}

void build(int idx,int i,int j){
    //printf("build %d %d %d\n", idx, i, j);
    tree[idx].active = false;
    tree[idx].val = 0;
    tree[idx].lz = 0;
	if(i==j)
		return;
	int m = (i+j)/2;
	build(idx*2,i,m);
	build(idx*2+1,m+1,j);
}


// soma x se no da seg  for folha e estiver ativo
void add(int idx, int i, int j, ll x){
    if(i != j){
        tree[idx].lz += x;
    }
    else{
        if(tree[idx].active)
            tree[idx].val += x;
    }

}

void unlaze(int idx, int i, int j){
    if(tree[idx].lz != 0){
        ll aux = tree[idx].lz;
        tree[idx].lz = 0;
        if(i != j){
            int m = (i + j)/2;
            add(idx*2, i, m, aux);
            add(idx*2+1, m+1, j, aux);
        }
    }
}

ll qry(int idx,int i,int j,int l){
	if(i > l || j < l) return 0;
    unlaze(idx, i, j);
	if(i == j)
		return tree[idx].val;
	int m = (i+j)/2;
    return qry(idx*2,i,m,l) + qry(idx*2+1,m+1,j,l);
}

void upd(int idx,int i, int j, int l, int r, ll x){
	if(i>r || j<l) return ;
    unlaze(idx, i, j);
	if(i >= l && j <= r){
        add(idx, i, j, x);
		return ;
	}
	int m = (i+j)/2;
	upd(idx*2,i,m,l,r,x);
	upd(idx*2+1,m+1,j,l,r,x);
}

void updUp(int u, ll x){
    while(chainNo[u] != chainNo[root]){
        int p = inichain[chainNo[u]];
        int ii = chainInd[u], jj = chainInd[p];
        upd(1, 1, degs-1, jj, ii, x);
        u = pai[p][0];
    }
    int i = chainInd[u], j = chainInd[root];
    upd(1, 1, degs-1, j, i, x);
}


void updAct(int idx,int i, int j, int l){
	if(i>l || j<l) return ;
    unlaze(idx, i, j);
	if(i == j){
		tree[idx].active = true;
		return ;
	}
	int m = (i+j)/2;
	updAct(idx*2,i,m,l);
	updAct(idx*2+1,m+1,j,l);
}

void reset(){
	degs=1;
	nchain = 0;
	memset(inichain,-1,sizeof(inichain));
	memset(tree,0,sizeof(tree));
	for(int a=0;a<=n;a++)
		adj[a].clear();
}

void buildHLD() {
	// assumindo 1..n
	h[root] = -1;
	dfs(root, root);
    debug("fez dfs\n");
	HLD(root);
    debug("fez hld - degs %d\n", degs);
	build(1,1,degs-1);
    debug("buildou\n");
}

void activate(int u){
    int l = chainInd[u];
    updAct(1, 1, degs-1, l);
}

int main (){
	scanf("%d", &n);
    root = -1;
    reset();
    map<int, vector<int>> ev;
	for(int a=1;a<=n;a++){
        int p;
        scanf("%d%d%d", &p, r+a, t+a);
        ev[r[a]].pb(a);
        if(p == -1)
            root = a;
        else{
            adj[p].pb(a);
            adj[a].pb(p);
        }
	}
    buildHLD();

    for(auto it = ev.rbegin();it != ev.rend();it++){
        for(int u: it->snd){
            // sum its value for active parents
            updUp(u, t[u]);
        }
        for(int u: it->snd){
            activate(u);
        }
    }
    for(int a=1;a<=n;a++){
        printf("%lld\n", qry(1, 1, degs-1, chainInd[a]));
    }
}

