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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

const int MAXE = 212345 * 2;

int n, m;

int fl[MAXE], cp[MAXE];
int to[MAXE];
int dege;

vector<int> ar[MAXN];

void add_edge(int u, int v, int c){
	fl[dege] = 0; cp[dege] = c; to[dege] = v;
	ar[u].pb(dege++);
	fl[dege] = 0; cp[dege] = 0; to[dege] = u;
	ar[v].pb(dege++);
}

queue<int> q;

int lv[MAXN];
int ai[MAXN];

bool bfs(int s, int t){
	while(!q.empty())
		q.pop();
	q.push(s);
	memset(lv, -1, sizeof(int)*n); // n being the real number of vertexes
	memset(ai, 0x3f3f3f3f, sizeof(int)*n);
	ai[s] = 0;
	lv[s] = 0;
	debug("lv %d: %d\n", s, 0);
	while(!q.empty()){
		int u = q.front();
		debug("u %d lv %d\n", u, lv[u]);
		q.pop();
		assert(lv[u] > -1);
		for(int a: ar[u]){
			int nxt = to[a];
			if(fl[a] < cp[a] && lv[nxt] == -1){
				lv[nxt] = lv[u] + 1;
				ai[nxt] = 0;
				debug("u %d lv %d -> nxt %d lv %d\n", u, lv[u], nxt, lv[nxt]);
				debug("ar fl %d cp %d\n", fl[a], cp[a]);
				q.push(nxt);
				if(nxt == t) return true;
			}
		}
	}
	return false;
}

int dfs(int u, int t, int mx){
	debug("dfs %d %d %d\n", u, t, mx);
	if(u == t){
		debug("cheguei no t com %d\n", mx);
		return mx;
	}
	debug("ai[%d] = %d\n", u, ai[u]);
	while(ai[u] < ar[u].size()){
		int i = ai[u];
		int a = ar[u][i];
		int nxt = to[a];
		debug("vizinho no %d = %d\n", i, nxt);
		if(lv[nxt] == lv[u] + 1 && cp[a] > fl[a]){
			if(int f = dfs(nxt, t, min(mx, cp[a] - fl[a]))){
				fl[a] += f;
				fl[a^1] -= f;
				debug("soma fluxo %d em ares %d -> %d\n", f, u, nxt);
				return f;
			}
		}
		ai[u]++;
	}

	return 0;
}

int max_flow(int s, int t){
	int ans = 0, f;
	while(bfs(s, t)){
		while(f = dfs(s, t, INT_MAX))
			ans += f;
	}
	return ans;
}

int id(char c){
	if(c >= 'A' && c <= 'Z')
		return c - 'A';
	return c - 'a' + 26;
}

int main(){
	scanf("%d\n", &m);
	n = 70;
	for(int a=0;a<m;a++){
		char u, v;
		int c;
		scanf(" %c %c %d", &u, &v, &c); 
		add_edge(id(u), id(v), c);
	}
	printf("%d\n", max_flow(id('A'), id('Z')));
}
