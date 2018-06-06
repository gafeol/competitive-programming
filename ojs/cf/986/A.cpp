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

const int MAXN = 100345, MAXC = 102;
const int INF = 0x3f3f3f3f;

int n, m, k, ds;
int s[MAXN];
int d[MAXN][MAXC];

vector<int> adj[MAXN];

int main (){
	scanf("%d%d%d%d", &n, &m, &k, &ds);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		s[a]--;
	}
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		i--;
		j--;
		adj[i].pb(j);
		adj[j].pb(i);
	}
	queue<int> q;
	for(int a=0;a<n;a++){
		for(int b=0;b<k;b++){
			d[a][b] = INF;
		}
	}
	for(int c=0;c<k;c++){
		for(int a=0;a<n;a++){
			if(s[a] == c){
				q.push(a);
				d[a][s[a]] = 0;
			}
		}

		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int nxt: adj[u]){
				if(d[nxt][c] > d[u][c] + 1){
					d[nxt][c] = d[u][c] + 1;
					q.push(nxt);
				}
			}
		}
	}

	for(int a=0;a<n;a++){
		vector<int> cl;
		for(int c=0;c<k;c++)
			cl.pb(d[a][c]);
		sort(cl.begin(), cl.end());
		int res = 0;
		for(int b=0;b<ds;b++)
			res += cl[b];
		printf("%d ", res);
	}
	puts("");
}
