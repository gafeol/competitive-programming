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

int n, m, k;
int s[MAXN];

struct ed{
	int u, v;
	ll cp, f;
	ed(int uu, int vv, ll cc, ll ff){
		u = uu;
		v = vv;
		cp = cc;
		f = ff;
	}
	ed(){}
};

int ne;
vector<ed> eds;

vector<int> adj[MAXN];

void add_edge(int u, int v, ll cp){
	eds[ne] = ed(u, v, 0, cp);
	adj[u].pb(ne++);
	eds[ne] = ed(v, u, cp, cp);
	adj[v].pb(ne++);
}

ll go(int u, ll flow, int t){
	if(u == t)
		return 0;
	for(int i: adj[u]){
		int nxt = eds[i].v;
		ll cp = eds[i].cp;
		ll f = eds[i].f;
		if(mrk[nxt] >= tempo || cp - f
		if(int fl = go(nxt, v)){
				
		}
	}
}

void max_flow(int s, int t){
	while(int f = go(s, t)){
		flow += f;
		tempo++;
	}
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int i, j;
		ll k;
		scanf("%d %d %lld", &i, &j, &k);
		add_edge(i, j, k);
	}
	max_flow(1, 2);
}

