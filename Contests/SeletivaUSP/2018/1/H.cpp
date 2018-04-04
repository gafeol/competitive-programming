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

int n, m, k;

vector<int> adj[MAXN];

int prv[MAXN];

int cy[MAXN];

int dege, deg;
int mn[MAXN], pre[MAXN], mrk2[MAXN];
stack<int> q2;

int tarjan(int u){
	q2.push(u);
	mrk2[u] = 1;
	pre[u] = dege++; 
	mn[u] = pre[u];
	for(int nxt: adj[u]){
		if(!mrk2[nxt])
			mn[u] = min(mn[u], tarjan(nxt));
		else if(cy[u] == cy[nxt])
			mn[u] = min(mn[u], pre[nxt]);
	}
	if(mn[u] == pre[u]){
		cy[u] = deg++;
		while(q2.top() != u){
			cy[q2.top()] = cy[u];
			q2.pop();
		}
		q2.pop();
	}
	return mn[u];
}

queue<int> qb;

int dt[MAXN];
int mrkd[MAXN], pred[MAXN];

void dfs(int u){
	mrkd[u] = 1;
	for(int nxt: adj[u]){
		if(mrkd[nxt] || cy[nxt] != cy[u]) continue;
		pred[nxt] = u;
		dfs(nxt);
	}
}

deque<int> path, ans;


void limpapath(){
	//limpa checando se subciclos sao impar
	int inp[MAXN];
	deque<int> auxp;
	deque<int> aux;

	for(int u: path)
		inp[u] = 0;
	for(int u: path){
		while(inp[u]){
			inp[auxp.back()] = 0;
			aux.push_front(auxp.back());
			auxp.pop_back();
		}

		if((aux.size()&1)){
			ans = aux;
			return;
		}
		aux.clear();
		inp[u] = 1;
		auxp.push_back(u);
	}
	path = auxp;
	for(int u: path)
		inp[u] = 0;
}

void findpath(int u, int v){
	//assert(cy[u] == cy[v]);
	//assert(v != 0 && v != -1);
	pred[u] = u;
	dfs(u);
	/*//DEBUG
	for(int a=1;a<=n;a++){
		if(cy[a] == cy[u]){
			assert(mrkd[u]);
			assert(pred[a] != 0);
		}
	}
	*/
	debug("find path betw %d and %d\n", u, v);
	while(v != u){
		if(v == 0){
			printf("AAAAAAAAAAAA\n");
			exit(0);
		}
		assert(v != 0 && v != -1);
		path.push_front(v);
		v = pred[v];
	}
	path.push_front(v);
	limpapath();
}

void rootpath(int u, int ini){
	debug("rootpath %d %d\n", u, ini);
	if(u != ini){
		u = prv[u];
		while(u != ini){
			assert(u != 0 && u != -1);
			path.push_front(u);
			u = prv[u];
		}
	}
	limpapath();
	if(!ans.empty()) return;
	ans = path;
}

void solve(int ini, int u, int v){
	debug("solve %d %d %d\n", ini, u, v);
	findpath(v, ini);
	if(!ans.empty()) return ;

	if((((path.size()-1)&1)^dt[v]))
		rootpath(v, ini);
	else{
		path.push_front(u);
		rootpath(u, ini);
	}
}

void go(int u){
	debug("go %d\n", u);
	int ini = u;
	while(!qb.empty())
		qb.pop();
	qb.push(u);	
	dt[u] = 0;
	while(!qb.empty()){
		u = qb.front();
		qb.pop();
		for(int nxt: adj[u]){
			if(cy[nxt] != cy[u]) continue;
			if(dt[nxt] == 1-dt[u]) continue;
			else if(dt[nxt] == dt[u]){
				solve(ini, u, nxt);
				return ;
			}
			prv[nxt] = u;
			dt[nxt] = 1 - dt[u];
			qb.push(nxt);
		}
	}
}

int mrkc[MAXN];

void zera(){
	ans.clear();
	deg = 0;
	dege = 0;
	path.clear();
	for(int a=0;a<=n;a++){
		mrk2[a] = 0;
		cy[a] = -1;
		prv[a] = 0;
		mrkc[a] = 0;
		mrkd[a] = 0;
		pred[a] = 0;
		adj[a].clear();
		dt[a] = -1;
		pre[a] = 0;
	}
}

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &m);
		zera();
		for(int a=0;a<m;a++){
			int i, j;
			scanf("%d %d", &i, &j);	
			adj[i].pb(j);
		}
		for(int a=1;a<=n;a++){
			if(mrk2[a]) continue;
			tarjan(a);
		}
		for(int a=1;a<=n;a++){
			if(mrkc[cy[a]]) continue;
			mrkc[cy[a]] = 1;
			go(a);
			if(!ans.empty()) break;
		}

		if(ans.empty())
			puts("-1");
		else{
			puts("1");
			printf("%d\n", (int)ans.size());
			for(int a: ans)
				printf("%d\n", a);
		}
	}
}
