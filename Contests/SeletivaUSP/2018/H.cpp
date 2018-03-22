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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

vector<int> adj[MAXN], inv[MAXN];

int ind[MAXN], oud[MAXN];
int prv[MAXN][2], nxt[MAXN];

int in[MAXN], mrk[MAXN][2];

int vis[MAXN], cy[MAXN];

queue<int> q;

void put(int u){
	if(in[u]) return;
	in[u] = 1;
	q.push(u);
}

vector<int> ans;

int inp[MAXN];

void re(int u, int t, int ini){
	while(u != ini){
		debug("re u %d ini %d\n", u, ini);
		ans.pb(u);
		u = prv[u][t];
		t = 1 - t;
	}
	ans.pb(u);
}

void go(int u, int t){
	if(!ans.empty()) return;
	inp[u] = 1;
	mrk[u][t] = 1;
	debug("u %d t %d\n", u, t);
	for(int nxt: adj[u]){
		if(cy[nxt] != cy[u]) continue;
		if(!ans.empty()) return;
		debug("u %d nxt %d\n", u, nxt);
		if(mrk[nxt][t] && inp[nxt]) re(nxt, t, u);
		if(!ans.empty()) return;
		if(mrk[nxt][1-t]) continue;
		debug("u %d chama %d\n", u, nxt);
		prv[nxt][1-t] = u;
		go(nxt, 1-t);
	}
	inp[u] = 0;
}

int imrk[MAXN][2], iprv[MAXN][2];

void gi(int u, int t, int ini){
	if(!ans.empty()) return;
	inp[u] = 1;
	imrk[u][t] = 1;
	//if(mrk[u][1-t])
	//	ire(u, t
	debug("u %d t %d\n", u, t);
	for(int nxt: inv[u]){
		if(cy[nxt] != cy[u]) continue;
		if(!ans.empty()) return;
		debug("u %d nxt %d\n", u, nxt);
	//	if(imrk[nxt][t] && inp[nxt]) ire(nxt, t, u);
		if(!ans.empty()) return;
		if(imrk[nxt][1-t]) continue;
		debug("u %d chama %d\n", u, nxt);
		iprv[nxt][1-t] = u;
		gi(nxt, 1-t, ini);
	}
	inp[u] = 0;
}

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

int mrkc[MAXN];

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &m);
		ans.clear();
		deg = 0;
		dege = 0;
		for(int a=1;a<=n;a++){
			prv[a][0] = 0;
			prv[a][1] = 0;
			in[a] = 0;
			mrk[a][0] = 0;
			mrk[a][1] = 0;
			adj[a].clear();
			inv[a].clear();
			vis[a] = 0;
			ind[a] = 0;
			oud[a] = 0;
		}
		while(!q.empty())
			q.pop();
		for(int a=0;a<m;a++){
			int i, j;
			scanf("%d %d", &i, &j);	
			adj[i].pb(j);
			inv[j].pb(i);
		}
		for(int a=1;a<=n;a++){
			if(mrkc[cy[a]]) continue;
			mrkc[cy[a]] = 1;
			go(a, 0);
			if(!ans.empty()) break;
		}
		/*
		if(ans.empty()){
			for(int a=1;a<=n;a++){
				if(mrkc[cy[a]] == 2) continue;
				mrkc[cy[a]] = 2;
				gi(a, 0);
				if(!ans.empty()) break;
			}
		}
		*/

		if(ans.empty())
			puts("-1");
		else{
			puts("1");
			printf("%d\n", (int)ans.size());
			for(int a=ans.size()-1;a>=0;a--){
				printf("%d\n", ans[a]);
			}
		}
	}
}
