#include <bits/stdc++.h>
using namespace std;
#define int ll
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 3123, INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];

map<pii, int> ind;
pii pos[MAXN];
int deg;

int adj[MAXN][MAXN];

vector<int> tow[MAXN];

void build(int i, int j){
	if(ind.find(pii(i, j)) != ind.end())
		return;

	tow[i].pb(j);
	pos[deg] = pii(i, j);
	adj[deg][deg] = 0;
	ind[pii(i, j)] = deg++;
}

void add(int i, int j, int d){
	adj[i][j] = min(adj[i][j], d);
	adj[j][i] = min(adj[j][i], d);
}

main (){
	int ti;
	scanf("%lld", &ti);
	deg = 1000;
	while(ti--){
		for(int a=0;a<deg;a++){
			for(int b=0;b<deg;b++){
				adj[a][b] = 1e8;
			}
			adj[a][a] = 0;
		}
		deg = 0;
		ind.clear();
		int f;
		scanf("%lld %lld %lld", &n, &f, &m);
		for(int a=1;a<=n;a++)
			tow[a].clear();
		for(int a=1;a<=n;a++)
			build(a, 1);

		for(int a=1;a<=n;a++){
			int u = ind[pii(a, 1)];
			int v;
			if(a == n)
				v = ind[pii(1, 1)];
			else
				v = ind[pii(a+1, 1)];
			add(u, v, 1);
		}
		for(int a=0;a<m;a++){
			int i, j, ii, jj, t;
			scanf("%lld %lld %lld %lld %lld", &i, &j, &ii, &jj, &t); 
			build(i, j);
			build(ii, jj);
			int u = ind[pii(i, j)];
			int v = ind[pii(ii, jj)];
			add(u, v, t);
		}
		for(int i=1;i<=n;i++){
			sort(tow[i].begin(), tow[i].end());
			for(int a = 1;a<tow[i].size();a++){
				int u = ind[pii(i, tow[i][a-1])];
				int v = ind[pii(i, tow[i][a])];
				debug("liga (%lld %lld) (%lld %lld) com dist %lld\n", i, tow[i][a-1], i, tow[i][a], tow[i][a]-tow[i][a-1]);
				add(u, v, abs(tow[i][a] - tow[i][a-1]));
			}
		}

		for(int k = 0;k < deg;k++){
			for(int i = 0;i < deg;i++){
				for(int j = 0;j < deg;j++){
					add(i, j, adj[i][k] + adj[k][j]);
				}
			}
		}

		for(int i=0;i<deg;i++){
			for(int j=0;j<deg;j++){
				debug("(%lld, %lld) -> (%lld, %lld) costs %lld\n", pos[i].fst, pos[i].snd, pos[j].fst, pos[j].snd, adj[i][j]);
			}
		}

		pii ini[2];
		pii fim[2];
		int q;
		scanf("%lld", &q);
		for(int a=0;a<q;a++){
			int i, j, ii, jj;
			scanf("%lld %lld %lld %lld", &i, &j, &ii, &jj);
			int cnt = 0;
			if(ind.find(pii(i, j)) == ind.end()){
				auto it = lower_bound(tow[i].begin(), tow[i].end(), j);
				ini[0] = ini[1] = pii(i, 1);
				if(it != tow[i].end())
					ini[0] = pii(i, *it);
				if(it != tow[i].begin())
					ini[1] = pii(i, *(--it));
			}
			else{
				ini[0] = ini[1] = pii(i, j);
			}

			if(ind.find(pii(ii, jj)) == ind.end()){
				auto it = lower_bound(tow[ii].begin(), tow[ii].end(), jj);
				fim[0] = fim[1] = pii(ii, 1);
				if(it != tow[ii].end())
					fim[0] = pii(ii, *it);
				if(it != tow[ii].begin())
					fim[1] = pii(ii, *(--it));
			}
			else{
				fim[0] = fim[1] = pii(ii, jj);
			}
			debug("ini:\n	ini[0] %lld %lld\n	ini[1] %lld %lld\nfim:\n	fim[0], %lld %lld\n	fim[1] %lld %lld\n", ini[0].fst, ini[0].snd, ini[1].fst, ini[1].snd, fim[0].fst, fim[0].snd, fim[1].fst, fim[1].snd);
			
			int res = LLONG_MAX;
			for(int x=0;x<2;x++){
				for(int y=0;y<2;y++){
					res = min(res, adj[ind[ini[x]]][ind[fim[y]]] + abs(j - ini[x].snd) + abs(jj - fim[y].snd));
					debug("res = min( %lld + %lld + %lld)\n", adj[ind[ini[x]]][ind[fim[y]]], abs(j - ini[x].snd), abs(jj - fim[y].snd));
				}
			}

			if(i == ii)
				res = min(res, abs(j - jj));
			printf("%lld\n", res);
		}
	}
}
