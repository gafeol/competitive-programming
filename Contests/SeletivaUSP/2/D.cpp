#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;

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

const int MAXN = 1123, MAXP = 153, INF = (1<<29);

int n, m, p, t;

vector<pii> adj[MAXN];
vector<int> ps;

int s[MAXN], ind[MAXN], deg;

int d[MAXP][MAXP], dind[MAXN];

set<pii> q2;
set<pip> q;
map<pii, int> cus;

pip mk(int i, int j, int l){
	return pip(i, pii(j, l));
}

void dijks(int st){
	for(int a=0;a<=n;a++){
		dind[a] = INF;
	}
	q2.insert(pii(0, st));
	dind[st] = 0;
	while(!q2.empty()){
		pii top = *q2.begin();
		q2.erase(top);
		int u = top.snd;
		for(pii nxt: adj[u]){
			int v = nxt.fst;
			int c = nxt.snd;
			if(dind[v] > dind[u] + c){
				if(dind[v] != INF)
					q2.erase(pii(dind[v], v));
				dind[v] = dind[u] + c;
				q2.insert(pii(dind[v], v));
			}
		}
	}

	for(int a=0;a<deg;a++)
		d[ind[st]][a] = INF;

	for(int a=1;a<=n;a++){
		if(ind[a] != 0)
			d[ind[st]][ind[a]] = dind[a];
	}
}

void cmp(int u, int g, int v, int g2, int c){
	if(c < 0 || g2 < 0) return ;
	if(cus.find(pii(v, g2)) != cus.end()){
		if(cus[pii(v, g2)] > cus[pii(u, g)] + c){
			q.erase(mk(cus[pii(v, g2)], g2, v));
			cus[pii(v, g2)] = cus[pii(u, g)] + c;
			q.insert(mk(cus[pii(v, g2)], g2, v));
		}
	}
	else{
		cus[pii(v, g2)] = cus[pii(u, g)] + c;
		q.insert(mk(cus[pii(v, g2)], g2, v));
		
	}
}

int main (){
	int t2;
	scanf("%d", &t2);
	while(t2--){
		scanf("%d%d%d", &n, &m, &p);
		scanf("%d", &t);
		for(int a=1;a<=n;a++){
			adj[a].clear();
			ind[a] = 0;
		}
		for(int a=0;a<m;a++){
			int i, j, c;
			scanf("%d %d %d", &i, &j, &c);
			adj[i].pb(pii(j, c));
			adj[j].pb(pii(i, c));
		}
		deg = 1;
		ps.clear();
		for(int a=0;a<p;a++){
			int u,c;
			scanf("%d %d", &u, &c); 
			ps.pb(u);
			ind[u] = deg++;
			s[ind[u]] = c;
		}
		int ini, fim;
		scanf("%d %d", &ini, &fim);
		ind[fim] = deg++;
		dijks(ini);
		for(int u: ps){
			dijks(u);
		}
		dijks(fim);
		s[ind[fim]] = 0;

		q.insert(mk(0, 0, ind[ini]));	
		cus.clear();
		cus[pii(ind[ini], 0)] = 0;
		while(!q.empty()){
			pip top = *q.begin();
			q.erase(top);
			int u = top.snd.snd;
			int gas = top.snd.fst;
		//	debug("to em %d com %d cus %d\n", u, gas, cus[pii(u, gas)]);
			for(int v = 1;v<deg;v++){
				if(s[v] > s[u])
					cmp(u, gas, v, t-d[u][v], s[u]*(t-gas));
				else{
					if(d[u][v] <= t) cmp(u, gas, v, 0, s[u]*(d[u][v] - gas));
				}
			}
		}
		printf("%d\n", cus[pii(deg-1, 0)]);
	}
}
