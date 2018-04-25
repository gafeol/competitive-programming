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

#define set asda

const int MAXN = 65*2;

int n, m, k;
int cy[MAXN];
int s[MAXN], v[MAXN];

vector<int> adj[MAXN];

void add_edge(int a, int i, int b, int j){
	int u = a*2 + i;
	int v = b*2 + j;
	debug("(%d %d) -> (%d %d)\n", a, i, b, j);
	adj[u].pb(v);
}

int pre[MAXN], mrk[MAXN], mn[MAXN], dege, deg;

stack<int> q;

void set(int a, int p){
	debug("SET %d to %d\n", a, p);
	add_edge(a, 1-p, a, p);
}

int tarjan(int u){
	q.push(u);
	mrk[u] = 1;
	pre[u] = dege++; 
	mn[u] = pre[u];
	for(int nxt: adj[u]){
		if(!mrk[nxt])
			mn[u] = min(mn[u], tarjan(nxt));
		else if(cy[u] == cy[nxt])
			mn[u] = min(mn[u], pre[nxt]);
	}
	if(mn[u] == pre[u]){
		cy[u] = deg++;
		while(q.top() != u){
			cy[q.top()] = cy[u];
			q.pop();
		}
		q.pop();
	}
	return mn[u];
}

int id(int i, int t){
	return i*2+t;
}

void zera(){
	while(!q.empty()) q.pop();
	dege = 0;
	deg =  0;
	for(int a=0;a<2*n+10;a++){
		mrk[a] = 0;
		adj[a].clear();
		cy[a] = -1;
	}
}

int go(double t){
	for(int a=0;a<n;a++){
		for(int b=a+1;b<n;b++){
			if((double)(abs(s[b] - s[a])) <= t*(abs((double)(v[b] - v[a])))){
				if(s[a] < s[b]){
					if(v[a] > v[b])
						set(a, 0);
					else
						set(b, 1);
				}
				else{
					if(v[a] > v[b])
						set(a, 1);
					else
						set(b, 0);
				}
			}
			if((double)abs(s[b] - s[a]) <= t*((double)v[a] + (double)v[b])){
				if(s[a] < s[b]){
					add_edge(a, 1, b, 1);
					add_edge(b, 0, a, 0);
				}
				else{
					add_edge(a, 0, b, 0);
					add_edge(b, 1, a, 1);
				}
			}
		}
	}
	for(int a=0;a<2*n;a++){
		if(!mrk[a])
			tarjan(a);
	}
	int fodeu = 0;
	for(int a=0;a<n;a++){
		if(cy[id(a, 0)] == cy[id(a, 1)]){
			fodeu = 1;
			break;
		}
	}
	return (!fodeu);
}

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			scanf("%d %d", s+a, v+a); 
		}
		clock_t clk = clock();
		double i = 0, j = 2000000000LL;
		while(j - i > 1e-6){
			debug("i %.8f j %.8f\n", i, j);
			double m = (i + j)/2.;	
			zera();
			if(go(m))
				i = m;	
			else
				j = m;
		}
		double ans = (i + j)/2.;
		if(ans > 1000000010LL)
			puts("-1");
		else
			printf("%.10f\n", ans);
	}
}
