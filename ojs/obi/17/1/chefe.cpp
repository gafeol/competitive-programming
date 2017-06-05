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

const int MAXN = 545, INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];
int pos[MAXN];
int dp[MAXN];
int deg[MAXN], ddeg[MAXN];
int has[MAXN];

vector<int> adj[MAXN];

void go(int x){
	queue<int> q;
	for(int a=1;a<=n;a++){
		deg[a] = ddeg[a];
		dp[a] = INF;
		if(deg[a] == 0)
			q.push(a);
	}

	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int nxt: adj[u]){
			dp[nxt] = min(dp[nxt], min(dp[u], s[has[u]])); 
			deg[nxt]--;
			if(deg[nxt] == 0)
				q.push(nxt);
		}
	}

	if(dp[pos[x]] != INF)
		printf("%d\n", dp[pos[x]]);
	else
		puts("*");
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
		pos[a] = a;
		has[a] = a;
	}
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		adj[i].pb(j);
		ddeg[j]++;
	}
	for(int a=0;a<k;a++){
		char t;
		scanf(" %c", &t);
		if(t == 'P'){
			int u;
			scanf("%d", &u);
			go(u);
		}
		else{
			int u, v;
			scanf("%d %d", &u, &v);
			swap(has[pos[u]], has[pos[v]]);
			swap(pos[u], pos[v]);
		}
	}
}
