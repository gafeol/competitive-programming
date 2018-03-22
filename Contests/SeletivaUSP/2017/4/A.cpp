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

const int MAXN = 512345;

int s[MAXN];
ll n;
int m, res[MAXN];
ll nc[MAXN];

int adj[MAXN][2], deg[MAXN];
queue<int> q;
ll sum[2];

int main (){
	scanf("%lld %d", &n, &m);
	for(int a=1;a<=m;a++){
		int i, j;
		char c;
		scanf(" %c %d %d", &c, &i, &j);	
		s[a] = (c == 'R');
		adj[a][0] = i;
		adj[a][1] = j;
		deg[i]++;
		deg[j]++;
	}
	nc[1] = n;
	for(int a=1;a<=m;a++){
		debug("deg[%d] %d\n", a, deg[a]);
		if(deg[a] == 0)
			q.push(a);
	}
	while(!q.empty()){
		int u = q.front();
		debug("to em %d\n", u);
		q.pop();
		res[u] = ((nc[u]&1ll)^s[u]);
		sum[0] = nc[u]/2ll;
		sum[1] = nc[u]/2ll;
		if((nc[u]&1))
			sum[s[u]]++;
		debug("cara %d divide %d %lld e %d %lld\n", u, adj[u][0], sum[0], adj[u][1], sum[1]); 
		for(int a=0;a<2;a++){
			int nxt = adj[u][a];
			deg[nxt]--;
			if(deg[nxt] == 0 && nxt != 0)
				q.push(nxt);
			nc[nxt] += sum[a];
		}
	}
	for(int a=1;a<=m;a++){
		printf("%c", (res[a] == 0ll ? 'L':'R'));
	}
	putchar('\n');
}
