#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
random_device rd;     //Get a random seed from the OS entropy device, or whatever
mt19937_64 eng(rd()); //Use the 64-bit Mersenne Twister 19937 generator and seed it with entropy.
//Define the distribution, by default it goes from 0 to MAX(unsigned long long)
uniform_int_distribution<unsigned long long> distr;
unsigned long long getRand() { return distr(eng); }

const int MAXN = 112345;
const int LOGN = 22;
int pai[MAXN][LOGN], chainNo[MAXN], chainInd[MAXN], sz[MAXN], nchain, degs, inichain[MAXN], h[MAXN];
vector <int> adj[MAXN];

int n, m, k;
struct num {
    ull h,hh;

    num () : h(0), hh(0) {}
    num (ull a, ull b) : h(a), hh(b) {}

    num operator ^ (num o) {
        return {h^o.h, hh^o.hh};
    }
} tree[8*MAXN];

bool zer(num o){
    return (o.h == o.hh && o.h == 0);
}

void dfs(int v,int ant){
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
    tree[idx] = num();
	if(i==j)
		return;
	int m = (i+j)/2;
	build(idx*2,i,m);
	build(idx*2+1,m+1,j);
}

int LCA(int i,int j){
	if(h[i] != h[j]){
        if(h[j] > h[i]) swap(i,j);
		for(int a = LOGN-1;a>=0;a--){
			if(h[pai[i][a]] > h[j]){
				i = pai[i][a];
			}
		}
		i = pai[i][0];
	}
	if(i==j) return i;
	for(int a=LOGN-1;a>=0;a--){
		if(pai[i][a] != pai[j][a]){
			i = pai[i][a];
			j = pai[j][a];
		}
	}
	return pai[i][0];
}

num qry(int idx,int i,int j,int l, int r){
	if(i > r || j < l) return num();
	if(i >= l && j <= r)
		return tree[idx];
	int m = (i+j)/2;
    return (qry(idx*2,i,m,l,r)^qry(idx*2+1,m+1,j,l,r));
}

num qryup(int i,int j){
    num ans;
	while(chainNo[i] != chainNo[j]){
		int j2 = inichain[chainNo[i]];
		int ii = chainInd[i], jj = chainInd[j2];
        ans = (ans ^ qry(1,1,degs-1,jj,ii));
		i = pai[j2][0];
	}
	int ii = chainInd[i], jj = chainInd[j];
	ans = (ans ^ qry(1,1,degs-1,jj,ii));
    return ans;
}

void upd(int idx,int i, int j, int l, num val){
	if(i>l || j<l) return ;
	if(i == j){
		tree[idx] = (tree[idx]^val);
		return ;
	}
	int m = (i+j)/2;
	upd(idx*2,i,m,l,val);
	upd(idx*2+1,m+1,j,l,val);
	tree[idx] = (tree[idx*2]^tree[idx*2+1]);
}

void reset(){
	degs=1;
	nchain = 0;
	memset(inichain,-1,sizeof(inichain));
	for(int a=0;a<=n;a++)
		adj[a].clear();
}

void buildHLD() {
	// assumindo 1..n
	h[1] = -1;
	dfs(1, 1);
	HLD(1);
	build(1,1,degs-1);
}

int mn[MAXN];

void go(int u, int p){
    int cnt = 0;
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        go(nxt, u);
        cnt += (h[mn[nxt]] <= h[u]);
        mn[u] = (h[mn[u]] < h[mn[nxt]] ? mn[u] : mn[nxt]);
    }
    if(mn[u] < u)
        cnt++;
    debug("u %d mn %d cnt %d\n", u, mn[u], cnt);
    if(cnt >= 3){
        puts("No");
        exit(0);
    }
}

int main (){
    srand(time(NULL));
	scanf("%d%d", &n, &m);
    reset();
    for(int a=1;a<=n;a++)
        mn[a] = a;
	for(int a=1;a<n;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        adj[i].pb(j);
        adj[j].pb(i);
	}
    buildHLD();

    vector<tuple<int, int, int>> qry;
    for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        int lc = LCA(i, j);
        qry.eb(h[i] + h[j] - 2*h[lc], i,j);
    }
    sort(qry.begin(), qry.end());
    for(auto [len, i, j]: qry){
        int lc = LCA(i, j);
        mn[i] = (h[lc] < h[mn[i]] ? lc : mn[i]);
        mn[j] = (h[lc] < h[mn[j]] ? lc : mn[j]);
        debug("i %d j %d lc %d %llu, %llu %llu, %llu %llu, %llu\n", i, j, lc, qryup(i, lc).h, qryup(i, lc).hh, qryup(j, lc).h, qryup(j, lc).hh, qryup(lc, lc).h, qryup(lc, lc).hh);
        if(i != j && !zer(qryup(i, lc)^qryup(j, lc)^qryup(lc,lc))){
            puts("No");
            return 0;
        }
        ull rd = getRand();
        ull rdd = getRand();
        num val = {rd, rdd};
        upd(1, 1, degs-1, chainInd[i], val);
        upd(1, 1, degs-1, chainInd[j], val);
    }
    go(1, 1);
    puts("Yes");
    return 0;
}

