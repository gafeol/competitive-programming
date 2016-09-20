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
int ind[MAXN], deg;
ll c[MAXN];

vector<int> adj[MAXN];

map<int, int> fc[MAXN];
map<int, ll> fq[MAXN];

ll res[MAXN];

void go(int v, int p){
	ind[v] = deg++;
	fc[ind[v]][c[v]] = 1;
	fq[ind[v]][1] = c[v];
	for(int nxt: adj[v]){
		if(nxt == p) continue;
		go(nxt, v);
		if(fc[ind[nxt]].size() > fc[ind[v]].size())
			swap(ind[nxt], ind[v]);
		for(auto& x: fc[ind[nxt]]){
			if(x.snd == 0) continue;
			int cor = x.fst;
			int qtd = x.snd;
			if(fc[ind[v]].find(cor) != fc[ind[v]].end() && fc[ind[v]][cor] != 0)
				fq[ind[v]][fc[ind[v]][cor]] -= cor;
			fc[ind[v]][cor] += x.snd;
			fq[ind[v]][fc[ind[v]][cor]] += cor;
		}
	}

	res[v] = fq[ind[v]].rbegin()->snd;
}

int main (){
	deg = 1;
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld", &c[a+1]);
	}
	for(int a=0;a<n-1;a++){
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	go(1, -1);
	for(int a=1;a<=n;a++){
		printf("%lld ", res[a]);
	}
}
