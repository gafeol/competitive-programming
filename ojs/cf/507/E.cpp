#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
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

#define uu fst.fst
#define vv fst.snd 
#define tt snd

int n, m, k;

vector<pii> adj[MAXN];

int p[MAXN];
int pre[MAXN];
int mrk[MAXN];

ppi s[MAXN];

queue<int> q;

map<pii, int> ind;


int main (){
	scanf("%d %d", &n, &m);
	int res = m;
	for(int a=1;a<=n;a++){
		mrk[a] = INT_MAX;
		p[a] = INT_MIN;
	}
	for(int a=0;a<m;a++){
		scanf("%d %d %d", &s[a].uu, &s[a].vv, &s[a].tt);
		adj[s[a].uu].pb(pii(s[a].vv, s[a].tt));
		adj[s[a].vv].pb(pii(s[a].uu, s[a].tt));
		if(s[a].tt == 0)
			res--;
	}
	q.push(1);
	p[1] = 0;
	pre[1] = 1;
	mrk[1] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(pii nxt: adj[u]){
			if(mrk[nxt.fst] < mrk[u] + 1) continue;
			if(mrk[nxt.fst] == INT_MAX)
				q.push(nxt.fst);
			mrk[nxt.fst] = mrk[u] + 1;
			if(p[nxt.fst] < p[u] + (nxt.snd == 1)){
				p[nxt.fst] = p[u] + (nxt.snd == 1);
				pre[nxt.fst] = u;
			}
		}
	}
	printf("%d\n", res-p[n]+mrk[n]-p[n]);
	int u = n;
	while(u != 1){
		if(p[pre[u]] == p[u])
			printf("%d %d 1\n", pre[u], u); 
		ind[pii(pre[u], u)] = 1;
		ind[pii(u, pre[u])] = 1;
		u = pre[u];
	}
	for(int a=0;a<m;a++){
		if(s[a].tt == 1 && ind.find(s[a].fst) == ind.end())
			printf("%d %d 0\n", s[a].uu, s[a].vv);
	}
//	for(int a=1;a<=n;a++){
//		printf("vertice %d\n	mrk %d\n	pre %d\n	pt %d\n", a, mrk[a], pre[a], p[a]);
//	}
}
