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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 41234;

int n, m, k;

int is[MAXN][2];
int mrk[MAXN], tempo, mx[MAXN];
int deg[MAXN], res[MAXN];
set<int> s[MAXN];

char u[MAXN], op[10], v[MAXN]; 

map<string, int> ind;

int cnt;


struct qry{
	int id, op, v;
	qry(int idd, int opp, int vv){
		id = idd;
		op = opp;
		v = vv;
	}
	qry(){}
};

vector<qry> qr[MAXN];

vector<int> adj[MAXN][2];
vector<int> inv[MAXN];

int id(string u){
	if(ind.find(u) == ind.end()){
		ind[u] = cnt;
		cnt++;
	}
	return ind[u];
}

void add(int i, int j, int t){
	adj[i][t].pb(j);
	inv[j].pb(i);
	deg[i]++;
}

void dfs(int u, int t){
	mrk[u] = tempo;
	for(int tt=t;tt>=0;tt--){
		for(int nxt: adj[u][tt]){
			if(mrk[nxt] == tempo) continue;
			dfs(nxt, t);
		}
	}
}

set<pii> st;

void dij(int u){
	st.insert(pii(0, u));
	mrk[u] = tempo;
	mx[u] = 0;
	while(!st.empty()){
		pii p = *st.begin();
		st.erase(st.begin());
		int u = p.snd;
		int t = p.fst;
		for(int tt=1;tt>=0;tt--){
			for(int nxt: adj[u][tt]){
				if(mrk[nxt] != tempo){
					mrk[nxt] = tempo;
					mx[nxt] = -1;
				}
				if(mx[nxt] < max(t, tt)){
					mx[nxt] = max(t, tt);
					st.insert(pii(mx[nxt], nxt));
				}
			}
		}
	}
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf(" %s %s %s", u, op, v);
		int i = id(u);
		int j = id(v);
		if(op[0] == 'i')
			add(i, j, 0);
		else
			add(i, j, 1);
	}
	for(int a=0;a<m;a++){
		scanf(" %s %s %s", u, op, v);
		qr[id(u)].pb(qry(a, (op[0] == 'h'), id(v)));	
	}
	queue<int> q;
	tempo = 0;
	for(int a=0;a<cnt;a++){
		tempo++;
		dfs(a, 0);
		int u = a;
		for(qry x: qr[u]){
			int id = x.id;				
			int v = x.v;
			int t = x.op;
			if(t == 1) continue;
			if(mrk[v] == tempo){
				debug("TRUE\n");
				res[id] = 1;
			}
			else{
				debug("FALSE\n");
				res[id] = 0;
			}
		}
		tempo++;
		dij(a);
		for(qry x: qr[u]){
			int id = x.id;				
			int v = x.v;
			int t = x.op;
			if(t == 0) continue;
			if(mrk[v] == tempo && mx[v] == 1){
				debug("TRUE\n");
				res[id] = 1;
			}
			else{
				debug("FALSE\n");
				res[id] = 0;
			}
		}
	}
	for(int a=0;a<m;a++)
		printf("Query %d: %s\n", a+1, (res[a] ? "true" : "false"));
}

