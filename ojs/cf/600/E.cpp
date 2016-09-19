#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 112345;

int n, m, k;
int c[MAXN], ind[MAXN], deg;

set<pii> fq[MAXN];

vector<int> adj[MAXN];

map<int, int> fc[MAXN];

void go(int v){
	for(int nxt: adj[v]){
		go(nxt);
		if(ind[v] == -1)
			ind[v] = ind[nxt];
		else{
			if(fc[ind[nxt]].size() > fc[ind[v]].size())
				swap(ind[nxt], ind[v]);

			for(auto& x: fc[ind[nxt]]){
				if(fc[ind[v]].find(x.fst) != fc[ind[v]].end() && fc[ind[v]][x.fst] != 0)
					fq[ind[v]].erase(pii(x.fst, x.snd));

				fc[ind[v]][x.fst] += x.snd;
				fq[ind[v]].insert(pii(x.fst, fc[ind[v]][x.fst]);
			}
		}
	}
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &c[a+1]);
	}
	for(int a=0;a<n-1;a++){
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	go(1);
}
