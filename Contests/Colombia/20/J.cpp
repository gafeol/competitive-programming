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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 412345;
const int LOGN = 20;

// testar com https://www.codechef.com/viewsolution/35182871
int pai[MAXN][LOGN], chainNo[MAXN], chainInd[MAXN], sz[MAXN], nchain, degs, inichain[MAXN], h[MAXN];
vector <int> adj[MAXN];

typedef int num;

struct arv{
    int x, act;
} tree[8*MAXN];
num base[MAXN];
num s[MAXN];

arv join(arv a, arv b){
    arv c;
    c.x = (a.x&b.x);
    c.act = (a.act&b.act);
    return c;
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
        if(!base[i])
            tree[idx].act = 0;
        else
            tree[idx].act = 1;
		tree[idx].x = base[i];
		return;
	}
	int m = (i+j)/2;
	build(idx*2,i,m);
	build(idx*2+1,m+1,j);
    tree[idx] = join(tree[idx*2], tree[idx*2+1]);
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

const int NEUTRO = (1<<20)-1;

arv qry(int idx,int i,int j,int l, int r){
	if(i > r || j < l) return {NEUTRO, 1};
	if(i>=l && j<=r)
		return tree[idx];
	int m = (i+j)/2;
    return join(qry(idx*2,i,m,l,r), qry(idx*2+1,m+1,j,l,r));
}

arv qryup(int i,int j){
    arv ans = {NEUTRO, 1}; 
	while(chainNo[i] != chainNo[j]){
		int j2 = inichain[chainNo[i]];
		int ii = chainInd[i], jj = chainInd[j2];
        ans = join(ans,qry(1,1,degs-1,jj,ii));
		i = pai[j2][0];
	}
	int ii = chainInd[i], jj = chainInd[j];
	ans = join(ans, qry(1,1,degs-1,jj,ii));
    return ans;
}

void upd(int idx,int i, int j, int l, num val){
	if(i>l || j<l) return ;
	if(i == j){
        if(val)
            tree[idx].act = 1;
        else
            tree[idx].act = 0;

		tree[idx].x = val;
		return ;
	}
	int m = (i+j)/2;
	upd(idx*2,i,m,l,val);
	upd(idx*2+1,m+1,j,l,val);
	tree[idx] = join(tree[idx*2], tree[idx*2+1]);
}

void reset(){
	degs=1;
	nchain = 0;
	memset(inichain,-1,sizeof(inichain));
}

void HLDroot(int r){
	h[r] = -1;
	dfs(r, r);
	HLD(r);
}

void buildHLD() {
	// assumindo 1..n
	build(1,1,degs-1);
}

int n, m, k;

map<int, int> no;

int ind(int x){
    if(no.find(x) == no.end()){
        no[x] = no.size()+1; // pra comecar do 1
    }
    return no[x];
}

int deg[MAXN];
int ds[MAXN];


int pathQry(int u, int v){
    //printf("paizao u %d: %d  v %d: %d\n", u, pai[u][LOGN-1], v, pai[v][LOGN-1]);
    if(pai[u][LOGN-1] != pai[v][LOGN-1])
        return -1;
    int lc = LCA(u, v);
    arv res = join(qryup(u, lc),qryup(v, lc));
    if(res.act == 0)
        return -1;
    else
        return __builtin_popcount(res.x);
}

void activate(int u){
    upd(1, 1, degs-1, chainInd[u], ds[u]);
}

void deactivate(int u){
    upd(1, 1, degs-1, chainInd[u], 0);
}

int main (){
    reset();
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
        int u, p;
        scanf("%d%d", &u, &p);
        u = ind(u);
        p = ind(p);
        if(p  != u){
            adj[p].pb(u);
            deg[u]++;
        }
        scanf("%d", &k);
        while(k--){
            int b;
            scanf("%d", &b); 
            b--;
            s[u] |= (1<<b);
        }
	}
    scanf("%d", &m);
    vector<tuple<int, int, int>> q(m);
    for(int a=0;a<m;a++){
        int t, x, y;
        scanf("%d%d", &t, &x);
        x = ind(x);
        if(t != 0){
            scanf("%d", &y);
            y = ind(y);
        }
        q[a] = {t, x, y};
        if(t == 2){
            if(y != x){
                adj[y].pb(x);
                deg[x]++;
            }
            scanf("%d", &k);
            while(k--){
                int b;
                scanf("%d", &b); 
                b--;
                ds[x] |= (1<<b);
            }
        }
    }
    for(int a=1;a<=no.size();a++){
        if(deg[a] == 0) {
            HLDroot(a);
        }
    }
    buildHLD();
    for(int a=0;a<m;a++){
        int t, x, y; 
        tie(t, x, y) = q[a];
        if(t == 0)
            deactivate(x);
        else if(t == 1)
            printf("%d\n", pathQry(x, y));
        else
            activate(x);
    }
}
