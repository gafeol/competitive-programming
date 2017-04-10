#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define int ll

typedef pair<ll, ll> pii;

#define fst first
#define snd second
#define pb push_back

const int MAXN = 212345;
const ll INF = 212345678901234;

int n, k, m, ini;

ll x, d[MAXN];

vector<pii> adj[MAXN];

set<pii> q;

void cmp(int nxt, int u, ll cus){
	if(d[nxt] > d[u] + cus){
		if(d[nxt] != INF)
			q.erase(pii(d[nxt], nxt));
		d[nxt] = d[u] + cus;
		q.insert(pii(d[nxt], nxt));
	}
}

main (){
	int t;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld%lld%lld%lld%lld", &n, &k, &x, &m, &ini);
		for(int a=0;a<=n+k;a++){
			d[a] = INF;
			adj[a].clear();
		}
		for(int a=0;a<m;a++){
			int i, j;
			ll c;
			scanf("%lld%lld%lld", &i, &j, &c);
			adj[i].pb(pii(j, c));
			adj[j].pb(pii(i, c));
		}
		q.insert(pii(0, ini));
		d[ini] = 0;
		int ja = 0;
		while(!q.empty()){
			pii top = *q.begin();
			q.erase(top);
			int u = top.snd;
			if(!ja && u <= k){
				ja = 1;
				for(int a=1;a<=k;a++)
					cmp(a, u, x);
			}
			for(int i = 0;i < adj[u].size();i++){
				pii ar = adj[u][i];
				int nxt = ar.fst;
				ll cus = ar.snd;
				cmp(nxt, u, cus);
			}
		}
		for(int a=1;a<=n;a++){
			printf("%lld ", d[a]);
		}
		putchar('\n');
	}
}
