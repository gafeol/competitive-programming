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
typedef ll num;

const int MAXN = 212345;
const int LOGN = 21;

int n, m, k;
ll s[MAXN], alt[MAXN];
int pai[MAXN][LOGN], chainNo[MAXN], chainInd[MAXN], sz[MAXN], nchain, degs, inichain[MAXN], h[MAXN];
int raiz[MAXN];
vector <int> adj[MAXN];
num tree[4*MAXN], base[MAXN];

int tempo, mrk[MAXN], mrkk[MAXN];

void dfs(int v,int ant){
    //assert(mrk[v] != tempo);
    mrk[v] = tempo;
	pai[v][0] = ant;
	h[v] = h[ant]+1;
	for(int a=1;a<LOGN;a++){
		pai[v][a] = pai[pai[v][a-1]][a-1];
	}
	sz[v] = 1;
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
        dfs(nxt,v);
        sz[v] += sz[nxt];
	}
}

void HLD(int v, int r){
    //assert(mrkk[v] != tempo);
    mrkk[v] = tempo;
    raiz[v] = r;
	chainInd[v] = degs;
    base[degs++] = s[v];
	chainNo[v] = nchain;
    if(inichain[nchain] == -1){
        inichain[nchain] = v;
    }
	int mai=-1, ind=-1;
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(mai < sz[nxt]){
			mai = sz[nxt];
			ind = nxt;
		}
	}
	if(mai != -1)
		HLD(ind, r);
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt == ind) continue;
		nchain++;
		HLD(nxt, r);
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
	tree[idx] = tree[idx*2] + tree[idx*2+1];
}

num qry(int idx,int i,int j,int l, int r){
	if(i > r || j < l) return 0;
	if(i>=l && j<=r)
		return tree[idx];
	int m = (i+j)/2;
    return (qry(idx*2,i,m,l,r) + qry(idx*2+1,m+1,j,l,r));
}
//  resolve do vertice i subindo ate o vertice j
inline num qryup(int i,int j){
    num ans = 0;
    //assert(h[i] > h[j]);
	while(chainNo[i] != chainNo[j]){
		int j2 = inichain[chainNo[i]];
		int ii = chainInd[i], jj = chainInd[j2];
        ans += qry(1,1,degs-1,jj,ii);
		i = pai[j2][0];
        //assert(i != pai[j2][0]);
	}
	int ii = chainInd[i], jj = chainInd[j];
	ans += qry(1,1,degs-1,jj,ii);
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
	tree[idx] = tree[idx*2] + tree[idx*2+1];
}

int LCA(int i, int j){
    if(h[i] != h[j]){
        if(h[i] > h[j]) swap(i, j);
        for(int a=LOGN-1;a>=0;a--){
            if(h[pai[j][a]] > h[i])
                j = pai[j][a];
        }
        j = pai[j][0];
    }
    if(i == j)
        return i;
    for(int a=LOGN-1;a>=0;a--){
        if(pai[i][a] != pai[j][a]){
            i = pai[i][a];
            j = pai[j][a];
        }
    }
    assert(pai[i][0] == pai[j][0]);
    return pai[i][0];
}

inline void reset(){
    tempo++;
	degs=1;
	nchain = 0;
	memset(inichain,-1,(n+1)*sizeof(int));
	memset(tree,0,4*(n+1)*sizeof(num));
	for(int a=0;a<=n;a++){
		adj[a].clear();
        raiz[a] = -1;
    }
}

inline void decomp(int u) {
	h[u] = -1;
	dfs(u, u);
	HLD(u, u);
}

inline void buildHLD(){
	build(1,1,degs-1);
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n;a++){
        scanf("%lld", alt+a);
	}
    for(int a=1;a<=n;a++){
        scanf("%lld", s+a);
    }

    vector<tuple<int,int,int>> q;
    vector<ll> ans(m, -1);
    for(int a=0;a<m;a++){
        int t, i, j;
        scanf("%d%d%d", &t, &i, &j);
        q.pb({t, i, j});
    }

    // go right
    reset();
    stack<int> st;
    for(int a=n;a>=1;a--){
        while(!st.empty() && alt[st.top()] < alt[a]){
            adj[a].pb(st.top());
            //printf("go r %d -> %d\n", a, st.top());
            st.pop();
        }
        st.push(a);
    }
    for(int a=1;a<=n;a++){
        if(raiz[a] == -1){
            assert(a == st.top());
            st.pop();
            decomp(a);
        }
    }
    buildHLD();
    for(int a=0;a<m;a++){
        int t, i, j;
        tie(t, i, j) = q[a];
        if(t == 1){
            upd(1, 1, degs-1, chainInd[i], j);
        }
        else{
            if(i > j) continue;
            if(raiz[i] == raiz[j] && h[i] <= h[j] && LCA(i, j) == i){
                ans[a] = qryup(j, i);
                //printf("R ans %d = qryup(%d %d) %lld\n", a, j, i, qryup(j, i));
            }
        }
    }
    // go left
    reset();
    while(!st.empty())
        st.pop();
    for(int a=1;a<=n;a++){
        while(!st.empty() && alt[st.top()] < alt[a]){
            adj[a].pb(st.top());
            //printf("go l %d <- %d\n", st.top(), a);
            st.pop();
        }
        st.push(a);
    }
    for(int a=n;a>=1;a--){
        if(raiz[a] == -1){
            assert(a == st.top());
            st.pop();
            decomp(a);
        }
    }
    buildHLD();
    for(int a=0;a<m;a++){
        int t, i, j;
        tie(t, i, j) = q[a];
        if(t == 1){
            upd(1, 1, degs-1, chainInd[i], j);
        }
        else{
            if(i < j) continue;
            if(raiz[i] == raiz[j] && h[i] <= h[j] && LCA(i, j) == i){
                ans[a] = qryup(j, i);
                //printf("L ans %d = qryup(%d %d) %lld\n", a, j, i, qryup(j, i));
            }
        }
    }
    for(int a=0;a<m;a++){
        if(get<0>(q[a]) == 2)
            printf("%lld\n", ans[a]);
    }
}
