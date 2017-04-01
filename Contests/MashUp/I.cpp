#include <bits/stdc++.h>
using namespace std;
#define mk make_pair
#define ii pair<int,int>
#define fi first
#define se second
#define N 550
#define INF 99999999

int n,m;
int grid[N][N];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool vis[N][N];
int d[N][N];

bool go(int t) {
	queue<ii> fila;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			vis[i][j] = 0;
			d[i][j] = INF;
		}
	}
	if(grid[1][1] > t) {
		vis[1][1] = 1;
		d[1][1] = t;
		fila.push(mk(1,1));
	}
	ii now,p;
	while(!fila.empty()) {
		now = fila.front();
		fila.pop();
		for(int i=0;i<4;i++) {
			p = now;
			p.fi += dx[i];
			p.se += dy[i];
			if(vis[p.fi][p.se]==0 && grid[p.fi][p.se] > d[now.fi][now.se]+1) {
				vis[p.fi][p.se] = 1;
				fila.push(p);
				d[p.fi][p.se] = d[now.fi][now.se] + 1;
			}
		}
	}
	return vis[n][m];
}

int bs() {
	int i,f,m;
	i = 0;
	f = 1000010;

	while(f > i) {
		m = (f+i)/2;
		//printf("%d->%d [%d]\n", i,f,m);
		if(go(m)) {
			i=m+1;
		} else f=m;
	}
	return i-1;
}

int main() {

	cin >> n >> m;
	
	for(int i=0;i<=m+10;i++) {
		vis[0][i] = 1;
		vis[n+1][i] = 1;
	}

	for(int i=0;i<=n+10;i++) {
		vis[i][0] = 1;
		vis[i][m+1] = 1;
	}
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++){ 
			cin >> grid[i][j];
		}		
	}

	int res = bs();
	
	if(res == -1) {
		printf("-1\n");
	} else printf("%d\n", res);
	

}

