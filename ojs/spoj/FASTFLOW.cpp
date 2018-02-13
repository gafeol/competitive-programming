#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 5123;
const int MAXV = 5123, MAXE = 31234*2*2;

int n, m, k;

vector<int> ar[MAXV];

int dege;
int to[MAXE], cp[MAXE], fl[MAXE], lv[MAXN];

void add_edge(int u, int v, int c){
	to[dege] = v; fl[dege] = 0; cp[dege] = c;
	ar[u].pb(dege++);
	to[dege] = u; fl[dege] = 0; cp[dege] = 0;
	ar[v].pb(dege++);
}

int ai[MAXN];

int qu[MAXN];

bool bfs(int s, int t){
	queue<int> q;
	q.push(s);
	memset(lv, -1, sizeof(int)*n);
	lv[s] = 0;
	ai[s] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int a: ar[u]){
			int nxt = to[a];
			if(lv[nxt] == -1 && cp[a] > fl[a]){
				lv[nxt] = lv[u] + 1;
				ai[nxt] = 0;
				if(nxt == t) return true;
				q.push(nxt);
			}
		}
	}
	return false;
}

int dfs(int u, int t, int mx){
	if(u == t) return mx;
	while(ai[u] < ar[u].size()){
		int a = ar[u][ai[u]];
		int nxt = to[a];
		if(lv[nxt] == lv[u] + 1 && cp[a] > fl[a]){
			if(int f = dfs(nxt, t, min(mx, cp[a] - fl[a]))){
				fl[a] += f;
				fl[a^1] -= f;
				return f;
			}
		}
		ai[u]++;
	}
	return 0;
}

ll max_flow(int s, int t){
	ll ans = 0;
	while(bfs(s, t))
		while(int f = dfs(s, t, INT_MAX))
			ans += f;
	return ans;
}

 main (){
	memset(ai, 0x3f3f3f3f, sizeof(int)*n);
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
		int i, j, c;
		scanf("%d %d %d", &i, &j, &c);	
		i--;j--;
		add_edge(i, j, c);
		add_edge(j, i, c);
	}
	printf("%lld\n", max_flow(0, n-1));
}

