// testar com https://www.codechef.com/viewsolution/35182871


int pai[MAXN][LOGN], chainNo[MAXN], chainInd[MAXN], sz[MAXN], nchain, degs, inichain[MAXN], h[MAXN];
vector <int> adj[MAXN];

typedef int num;
num tree[8*MAXN], base[MAXN];

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
	chainInd[v] = degs;
    base[degs++] = s[v];
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
	if(i==j){
		tree[idx] = base[i];
		return;
	}
	int m = (i+j)/2;
	build(idx*2,i,m);
	build(idx*2+1,m+1,j);
	tree[idx] = max(tree[idx*2],tree[idx*2+1]);
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
	if(i > r || j < l) return /* LLONG_MIN */;
	if(i>=l && j<=r){
		return tree[idx];
	}
	int m = (i+j)/2;
    return max(qry(idx*2,i,m,l,r), qry(idx*2+1,m+1,j,l,r));
}

num qryup(int i,int j){
    num ans = /* LLONG_MIN; */
	while(chainNo[i] != chainNo[j]){
		int j2 = inichain[chainNo[i]];
		int ii = chainInd[i], jj = chainInd[j2];
        ans = max(ans, qry(1,1,degs-1,jj,ii));
		i = pai[j2][0];
	}
	int ii = chainInd[i], jj = chainInd[j];
	ans = max(ans, qry(1,1,degs-1,jj,ii));
    return ans;
}

void upd(int idx,int i, int j, int l, num val){
	if(i>l || j<l) return ;
	if(i == j){
		tree[idx] = val;
		return ;
	}
	int m = (i+j)/2;
	upd(idx*2,i,m,l,val);
	upd(idx*2+1,m+1,j,l,val);
	tree[idx] = max(tree[idx*2],tree[idx*2+1]);
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
	h[1] = -1;
	dfs(1, 1);
	HLD(1);
	build(1,1,degs-1);
}
