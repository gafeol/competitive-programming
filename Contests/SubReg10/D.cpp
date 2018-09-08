#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)

template <typename T> void write(ostream& out, T t) {
	out << t << "\n";
}
template <typename T, typename... Args>
void write(ostream& out, T t, Args... args) {
	out << t << ' ';
	write(out, args...);
}

template <typename... Args>
void debug(Args... args) {
	#ifdef LOCAL
		write(cerr, args...);
	#endif
}


template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 262;
const int INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];
void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int adj[MAXN][MAXN];

int mrk[MAXN], dc[MAXN];
int d[MAXN];

set<pii> q;

int main (){
	int c;
	while(scanf("%d%d%d%d", &n, &m, &k, &c) && n+m+k+c){
		for(int a=0;a<n;a++){
			mrk[a] = 0;
			dc[a] = 0;
			for(int b=0;b<n;b++)
				adj[a][b] = INF;
		}
			
		for(int a=0;a<m;a++){
			int i, j, cus;
			scanf("%d %d %d", &i, &j, &cus);
			adj[i][j] = cus;
			adj[j][i] = cus;
		}

		int res = INT_MAX;
		for(int a=0;a<n;a++){
			d[a] = INT_MAX;
		}
		mrk[k-1] = 1;
		for(int a=k-2;a>=0;a--){
			mrk[a] = 1;
			dc[a] = dc[a+1] + adj[a][a+1];
			d[a] = INT_MAX;
		}


		q.insert(pii(0, c));
		d[c] = 0;
		while(!q.empty()){
			int u = q.begin()->snd;	
			int dis = q.begin()->fst;
			q.erase(q.begin());
			for(int v=0;v<n;v++){
				if(mrk[v]){
					res = min(res, dis + adj[u][v] + dc[v]);
					continue;
				}
				if(d[v] > d[u] + adj[u][v]){
					if(d[v] != INT_MAX)
						q.erase(pii(d[v], v));
					d[v] = d[u] + adj[u][v];
					q.insert(pii(d[v], v));
				}
			}
		}
		printf("%d\n", res);
	}
}
