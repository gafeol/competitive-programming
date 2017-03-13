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

map<pii, int> ind;
pii pos[MAXN];
int deg;

vector<pii> adj[MAXN];

inline int dist(int a, int b){
	if(pos[a].fst > pos[b].fst)
		swap(a, b);
	int i = pos[a].fst;
	int j = pos[a].snd;
	int ii = pos[b].fst;
	int jj = pos[b].snd;

	return min(ii - i, n-ii + i) + abs(jj-j); 
}

int main (){
	for_tests(t, tt){
		int f;
		scanf("%d %d %d", &n, &f, &m);
		for(int a=0;a<m;a++){
			int i, j, ii, jj, t;
			scanf("%d %d %d %d %d %d", &i, &j, &ii, &jj, &t); 
			if(ind.find(pii(i, j)) == ind.end()){
				ind[pii(i, j)] = deg++;
				pos[deg-1] = pii(i, j):
			}
			if(ind.find(pii(ii, jj)) == ind.end()){
				ind[pii(ii, jj)] = deg++;
				pos[deg-1] = pii(ii, jj);
			}
			int u = ind[pii(i, j)];
			int v = ind[pii(ii, jj)];
			adj[u].pb(pii(v, t));
			adj[v].pb(pii(u, t));
		}
		for(int a=0;a<deg;a++){
			for(int b=0;b<deg;b++){
				if(a == b) continue;
				adj[a].pb(pii(b, dist(a, b)));
			}
		}
		scanf("%d", &q);
		for(int a=0;a<q;a++){
			int i, j, ii, jj;
			scanf("%d %d %d %d", &i, &j, &ii, &jj);
			int cnt = 0;
			if(ind.find(pii(i, j)) == ind.end()){
				cnt++;
				ind[pii(i, j)] = deg++;	
				pos[deg-1] = pii(i, j);
				for(int a=0;a<deg-1;a++){
					adj[a].pb(pii(deg-1, dist(a, deg-1)));
					adj[deg-1].pb(pii(a, dist(a, deg-1)));
				}
			}
		}
	}
}
