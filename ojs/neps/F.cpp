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
const int LOGN = 20;

int pai[MAXN][LOGN], chainNo[MAXN], chainInd[MAXN], subsize[MAXN], nchain, degs, inichain[MAXN];
int cor[MAXN], C[MAXN];

vector <int> adj[MAXN];

ll tree[8*MAXN];

int h[MAXN];

ll res;

void dfs(int v,int ant){
	pai[v][0] = ant;
	h[v] = h[ant]+1;
	for(int a=1;a<LOGN;a++){
		pai[v][a] = pai[pai[v][a-1]][a-1];
	}
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
		if(nxt == pai[v][0]) continue;
		if(mai < subsize[nxt]){
			mai = subsize[nxt];
			//maip = cus;
			ind = nxt;
		}
	}
	if(mai != -1){
		if(inichain[nchain] == -1){
			inichain[nchain] = v;
		}
		cor[degs++] = C[v];
		HLD(ind);
	}
	else{ // eh uma folha
		if(inichain[nchain] == -1){
			inichain[nchain] = v;
		}
        cor[degs++] = C[v];
	}
	for(int a =0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt == pai[v][0] || nxt == ind) continue;
		nchain++;
		HLD(nxt);
	}
}

void build(int idx,int i,int j){
	if(i==j){
		tree[idx] = (1ll << (ll)cor[i]);
		return;
	}
	int m = (i+j)/2;
	build(idx*2,i,m);
	build(idx*2+1,m+1,j);
	tree[idx] = (tree[idx*2] | tree[idx*2+1]);
}

int LCA(int i,int j){
	if(h[j] > h[i]) swap(i,j);

	if(h[i] > h[j]){
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

void qry(int idx,int i,int j,int l, int r){
	if(i > r || j < l) return ;
	if(i>=l && j<=r){
		res |= tree[idx];
		return;
	}
	int m = (i+j)/2;
	qry(idx*2,i,m,l,r);
	qry(idx*2+1,m+1,j,l,r);
}

void qryup(int i,int j){
	while(chainNo[i] != chainNo[j]){
		int j2 = inichain[chainNo[i]];
		int ii = chainInd[i], jj = chainInd[j2];
        qry(1,1,degs-1,jj,ii);
		i = pai[j2][0];
	}
	int ii = chainInd[i], jj = chainInd[j];
	qry(1,1,degs-1,jj,ii);
}

void upd(int idx,int i, int j, int l, int val){
	if(i>l || j<l) return ;
	if(i == j){
		tree[idx] = (1ll << (ll)val);
		return ;
	}
	int m = (i+j)/2;
	upd(idx*2,i,m,l,val);
	upd(idx*2+1,m+1,j,l,val);
	tree[idx] = (tree[idx*2]|tree[idx*2+1]);
}

int n, m, k;

void reset(){
	degs=1;
	nchain = 0;
	memset(inichain,-1,sizeof(inichain));
	// assumindo 1..n
	h[1] = -1;
	dfs(1, 1);
	nchain = 0;
	HLD(1);
	build(1,1,degs-1);
}


int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++)
        scanf("%d", C+a);
    for(int a=0;a<n-1;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        adj[i].pb(j);
        adj[j].pb(i);
    }
    reset();
    scanf("%d", &m);
    for(int a=0;a<m;a++){
        int t;
        scanf("%d", &t);
        if(t == 1){
            int i, x;
            scanf("%d%d", &i, &x);
            upd(1, 1, degs-1, chainInd[i], x);
        }
        else{
            int i, j;
            scanf("%d%d", &i, &j);
            int lc = LCA(i, j);
            //printf("i%d j %d lc %d\n", i, j, lc);
            res = 0;
            qryup(i, lc);
            qryup(j, lc);
            printf("%d\n", __builtin_popcountll(res));
        }
    }
}

