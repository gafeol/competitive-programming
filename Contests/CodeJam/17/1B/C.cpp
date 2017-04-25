#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
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

const int MAXN = 212;
const ll INF = 10000000000000LL;
const double INFD = 100000000000000.;

int n, m, k;
double s[MAXN];
ll adj[MAXN][MAXN], mxd[MAXN];

double d[MAXN];

set<pdi> q;

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &m);
		for(int a=0;a<n;a++){
			scanf("%lld %lf", &mxd[a], &s[a]);
		}
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				scanf("%lld", &adj[a][b]);
				if(a == b)
					adj[a][b] = 0;
				if(adj[a][b] == -1)
					adj[a][b] = INF;
			}
		}
		for(int k = 0;k < n;k++){
			for(int i =0;i< n;i++){
				for(int j=0;j<n;j++){
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}
		printf("Case #%d: ", tt); 
		for(int a=0;a<m;a++){
			int ini, fim;
			scanf("%d %d", &ini, &fim);
			ini--;
			fim--;

			for(int a=0;a<n;a++){
				d[a] = INFD;
			}
			d[ini] = 0;
			q.insert(pdi(0, ini));
			while(!q.empty()){
				pdi top = *q.begin();
				q.erase(top);
				int u = top.snd;
				for(int nxt=0;nxt<n;nxt++){
					if(adj[u][nxt] <= mxd[u] && d[nxt] > d[u] + ((double)adj[u][nxt])/s[u]){
						if(d[nxt] != INFD)
							q.erase(pdi(d[nxt], nxt));
						d[nxt] = d[u] + ((double)adj[u][nxt])/s[u];
						q.insert(pdi(d[nxt], nxt));
					}	
				}
			}
			printf("%.10f ", d[fim]);
		}
		printf("\n");
	}
}
