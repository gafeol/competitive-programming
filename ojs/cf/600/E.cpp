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

vector<int> adj[MAXN];

map<int, int> fc[MAXN], fq[MAXN];

int res[MAXN];

void go(int v, int p){
	ind[v] = deg++;
	fc[ind[v]][c[v]] = 1;
	fq[ind[v]][1] = c[v];
	int mx = 1;
	for(int nxt: adj[v]){
		if(nxt == p) continue;
		go(nxt, v);
		if(fc[ind[nxt]].size() > fc[ind[v]].size())
			swap(ind[nxt], ind[v]);
	//	printf("junta de %d para %d\n", ind[nxt], ind[v]);
		for(auto& x: fc[ind[nxt]]){
			if(x.snd == 0) continue;
			int cor = x.fst;
			int qtd = x.snd;
	//		printf("junto cor %d em qtd %d\n", cor, qtd);
			if(fc[ind[v]].find(cor) != fc[ind[v]].end() && fc[ind[v]][cor] != 0)
				fq[ind[v]][fc[ind[v]][cor]] -= cor;
			fc[ind[v]][cor] += x.snd;
	//		printf("fc[%d][%d] = %d\n", ind[v], cor, fc[ind[v]][cor]);
			fq[ind[v]][fc[ind[v]][cor]] += cor;
	//		printf("fq[%d][%d] %d\n", ind[v], fc[ind[v]][cor], fq[ind[v]][fc[ind[v]][cor]]);
			mx = max(mx, fc[ind[v]][cor]);
		}
	}
	//printf("junto cor %d em qtd %d\n", c[v], 1);
//	printf("fc[%d][%d] = %d\n", ind[v], c[v], fc[ind[v]][c[v]]);
//	printf("fq[%d][%d] %d\n", ind[v], fc[ind[v]][c[v]], fq[ind[v]][fc[ind[v]][c[v]]]);

	res[v] = fq[ind[v]][mx];
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
	go(1, -1);
	for(int a=1;a<=n;a++){
		printf("%d ", res[a]);
	}
}
