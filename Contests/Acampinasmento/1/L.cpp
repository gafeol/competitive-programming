
#include<bits/stdc++.h>

using namespace std;

const int MAXN = 112, INF = 0x3f3f3f3f;

int n, m;

int adj[MAXN][MAXN];

int main(){
	memset(adj, INF, sizeof(adj));
	scanf("%d %d", &n, &m);
	for(int a=1;a<=n;a++)
		adj[a][a] = 0;
	for(int a=0;a<m;a++){
		int i, j, c;
		scanf("%d %d %d", &i, &j, &c);
		adj[i][j] = min(adj[i][j], c);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
	int cnt = 0;
	long long sum = 0;
	for(int a=1;a<=n;a++){
		for(int b=1;b<=n;b++){
			if(a == b) continue;
			if(adj[a][b] != INF){
				cnt++;
				sum += adj[a][b];
			}
		}
	}
	double ans = (double)sum/((double)cnt);
	printf("%.10f\n", ans);
}
