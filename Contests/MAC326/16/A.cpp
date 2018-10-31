#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)

template <typename T> void write(ostream& out, T t) {
	out << t << "\n";
}
template <typename T, typename... Args>
void write(ostream& out, T t, Args... args) {
	out << t << ' ';
	write(out, args...);
}

template <typename... Args>
void debug(Args... args) {
	#ifdef LOCAL
		write(cerr, args...);
	#endif
}


template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 300345, LOGN = 24;

int n, m, k;

int pai[MAXN][LOGN], chainNo[MAXN], subsize[MAXN], nchain, inichain[MAXN];

vector <int> adj[MAXN], pes[MAXN];

int tree[8*MAXN];

int h[MAXN];

int res;

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
	chainNo[v] = nchain;
	int mai=-1, ind=-1;
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt == pai[v][0]) continue;
		if(mai < subsize[nxt]){
			mai = subsize[nxt];
			ind = nxt;
		}
	}
	if(mai != -1){
		if(inichain[nchain] == -1)
			inichain[nchain] = v;
		HLD(ind);
	}
	else{
		// eh uma folha
		if(inichain[nchain] == -1)
			inichain[nchain] = v;
	}
	for(int a =0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt == pai[v][0] || nxt == ind) continue;
		nchain++;
		HLD(nxt);
	}
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

void qryup(int i,int j){
	while(chainNo[i] != chainNo[j]){
		int j2 = inichain[chainNo[i]];
		int ii = chainInd[i], jj = chainInd[j2];
		if(ii!=jj)
			qry(1,1,degs-1,jj,ii-1);
		res = max(res, custopai[j2]);
		i = pai[j2][0];
	}
	int ii = chainInd[i], jj = chainInd[j];
	if(ii==jj) return;
	qry(1,1,degs-1,jj,ii-1);
}

void upd(int u, int v, int c){
	int lst = u;
	while(chainNo[u] != chainNo[v]){
		int ini = inichain[chainNo[u]];
		add_edge(ini, u			
	}
}

void reset(){
	nchain = 0;
	memset(inichain,-1,sizeof(inichain));
	memset(tree,0,sizeof(tree));
	for(int a=0;a<=n;a++){
		adj[a].clear();
		pes[a].clear();
	}
	// Vertices de 1 ... n
	h[1] = -1;
	dfs(1);
	nchain = 0;
	HLD(1);

}

int main (){
	scanf("%d%d", &n, &m);
	reset();
	for(int a=1;a<n;a++){
		int i, j;
		scanf("%d%d",&i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	for(int a=0;a<m;a++){
		int i, j, c;
		scanf("%d%d%d", &i, &j, &c);
		if(h[i] > h[j]) swap(i, j);
		upd(j, i, c);
	}
}

