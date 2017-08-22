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

const int MAXN = 2123;

int n, m, k;
int s[MAXN];
int c[MAXN], degc, mrk[MAXN];

int vi[MAXN], vj[MAXN];

vector<int> adj[MAXN];

int id(int x, int t){
	return x*2 + t;
}

void add_edge(int x, int t, int y, int tt){
	adj[id(x, t)].pb(id(y, tt));
}

bool valid(int a, int b){
	return ((vi[a] == vi[b] && abs(vj[a] - vj[b]) <= k) || (vj[a] == vj[b] && abs(vi[a] - vi[b]) <= k));
}

stack<int> q;

int mn[MAXN], pre[MAXN], degp;

int tarjan(int u){
	mrk[u] = 1;
	q.push(u);
	mn[u] = degp;
	pre[u] = degp++;
	for(int nxt: adj[u]){
		if(!mrk[nxt])
			mn[u] = min(mn[u], tarjan(nxt));
		else if(c[nxt] == c[u])
			mn[u] = min(mn[u], pre[nxt]);
	}

	if(mn[u] == pre[u]){
		c[u] = degc++;
	//	debug("Comp %d ", u);
		while(q.top() != u){
	//		debug("%d ", q.top());
			c[q.top()] = c[u];
			q.pop();
		}
	//	puts("");
		q.pop();
	}

	return mn[u];
}

int main (){
	scanf("%d%d%d", &n, &k, &m);
	degp  = 1;
	memset(c, -1, sizeof(c));
	for(int a=0;a<m;a++){
		scanf("%d %d", &vi[a], &vj[a]);	
		for(int b=0;b<a;b++){
			if(valid(a, b)){
				if(vi[a] == vi[b]){
					add_edge(a, 0, b, 1);
					add_edge(b, 0, a, 1);
				}
				else{
					add_edge(a, 1, b, 0);
					add_edge(b, 1, a, 0);
				}
			}
		}
	}
	for(int a=0;a<2*m;a++){
		if(!mrk[a]){
	//		printf("call %d\n", a);
			tarjan(a);
		}
	}
	for(int a=0;a<m;a++){
		if(c[id(a, 0)] == c[id(a, 1)]){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}

