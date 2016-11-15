#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#define debug(args...) //fprintf(stderr,args)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k, deg, tempo;
int s[MAXN];

int ne;
struct ed{
	int u, v, cp, f;
	ed(int uu, int vv, int ff, int cc){
		u = uu;
		v = vv;
		cp = cc;
		f = ff;
	}
	ed(){}
};

vector<ed> eds;
vector<int> adj[MAXN];

void add_edge(int u, int v, int cp){
	adj[u].pb(ne++);
	eds.pb(ed(u, v, 0, cp));
	adj[v].pb(ne++);
	eds.pb(ed(v, u, cp, cp));
}

map<char, int> ind;

int num(char c){
	if(ind.find(c) == ind.end()){
		ind[c] = deg++;
	}
	debug("num %c  %d\n", c, ind[c]);
	return ind[c];
}

int mrk[MAXN], flow;

int dfs(int u, int fl, int t){
	debug("%d %d %d\n", u, fl, t);
	if(u == t)
		return fl;
	int ans = 0, ansi;
	mrk[u] = tempo;
	for(int i: adj[u]){
		int nxt = eds[i].v;
		int cp = eds[i].cp;
		int f = eds[i].f;
		if(mrk[nxt] < tempo && f < cp){
			ans = dfs(nxt, min(fl, (cp-f)), t);
			if(ans != 0){
				eds[i].f += ans;
				eds[i^1].f -= ans;
				return ans;
			}
		}
	}
	debug("retorna %d\n", ans);
	return ans;
}

int max_flow(int s, int t){
	while(int f = dfs(s, INT_MAX, t)){
		flow += f;
		tempo++;
	}
	return flow;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int u, v; 
		char c, cc;
		int k;
		scanf(" %c %c %d", &c, &cc, &k);	
		u = num(c);
		v = num(cc);
		add_edge(u, v, k);
	}
	tempo = 1;
	printf("%d\n", max_flow(num('A'), num('Z')));
}
