#include <bits/stdc++.h>
using namespace std;

const int MAXN = 77;

typedef long long ll;

int n, m;

ll d[MAXN][MAXN];
ll nd[MAXN][MAXN];

const ll INF = 1123456789012LL;


ll go(int u, int v, ll c){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			nd[i][j] = d[i][j];
	ll mx = LLONG_MIN;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			nd[i][j] = min(nd[i][j], min(nd[i][u] + c + nd[v][j], nd[i][v] + c + nd[u][j]));
			mx = max(mx, nd[i][j]);
		}
	}
	return mx;
}

int main(){
	for(int a=0;a<MAXN;a++){
		for(int b=0;b<MAXN;b++){
			d[a][b] = INF;
		}
	}
	scanf("%d %d", &n, &m);
	if(n == 1){
		puts("0.00000 -1.00000");
		return 0;
	}
	for(int a=0;a<m;a++){
		int u, v;
		ll dis;
		scanf("%d %d %lld", &u, &v, &dis); 
		d[u][v] = min(d[u][v], dis);
		d[v][u] = min(d[v][u], dis);
	}
	for(int a=1;a<=n;a++) d[a][a] = 0;

	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
			}
		}
	}
	ll res = INF;
	ll resd = -1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ll l = 0, r = 8e9;
			ll bfg = go(i, j, 0);
			if(bfg == INF || bfg > res) continue;
			while(l < r){
				ll mi = (l + r + 1)/2;	
				if(bfg < go(i, j, mi))
					r = mi-1;
				else
					l = mi;
			}
			assert(bfg == go(i, j, l));
			if(l >= 8e9){
				l = INF;
			}
			if(bfg < res || (bfg == res && l > resd)){
				res = bfg;
				resd = l;
			}
		}
	}
	if(res == INF) res = -1;
	if(resd == INF) resd = -1;
	printf("%lld.00000 %lld.00000\n", res, resd);
}
