#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pip;
typedef long long ll;

#define fst first
#define snd second
#define pb push_back

const int MAXN = 212345;
const ll INF = 212345678901234;

pip mk(int a, int b, int c){
	return pip(a, pii(b, c));
}

int n, k, m, ini;

ll x, d[MAXN][2];

vector<pii> adj[MAXN];

set<pip> q;

void cmp(int nxt, int tpn, int u, int tp, ll cus){
	if(d[nxt][tpn] > d[u][tp] + cus){
		if(d[nxt][tpn] != INF)
			q.erase(mk(d[nxt][tpn], nxt, tpn));
		d[nxt][tpn] = d[u][tp] + cus;
		q.insert(mk(d[nxt][tpn], nxt, tpn));
	}
}

int main (){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d%d", &n, &k, &x, &m, &ini);
		for(int a=0;a<=n+k;a++){
			d[a][0] = INF;
			d[a][1] = INF;
			adj[a].clear();
		}
		for(int a=0;a<m;a++){
			int i, j, c;
			scanf("%d%d%d", &i, &j, &c);
			adj[i].pb(pii(j, c));
			adj[j].pb(pii(i, c));
		}
		q.insert(mk(0, ini, 0));
		d[ini][0] = 0;
		while(!q.empty()){
			pip top = *q.begin();
			int u = top.snd.fst;
			int ja = top.snd.snd;
			if(!ja && u <= k){
				for(int a=1;a<=k;a++)
					cmp(a, 1, u, 0, x);
			}
			for(int i = 0;i < adj[u].size();i++){
				pii ar = adj[u][i];
				int nxt = ar.fst;
				int cus = ar.snd;
				cmp(nxt, ja, u, ja, cus);
			}
		}
		for(int a=1;a<=n;a++){
			printf("%d ", min(d[a][0], d[a][1]));
		}
		putchar('\n');
	}
}
