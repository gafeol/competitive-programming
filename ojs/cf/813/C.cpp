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
int res;
int s[MAXN];
int d[MAXN];

vector<int> adj[MAXN];

void go(int u, int p){
	d[u] = d[p] + 1;
	for(int nxt: adj[u]){
		if(nxt == p) continue;
		go(nxt, u);	
	}
}

void run(int u, int p, int dist){
	res = max(res, d[u]*2);
	for(int nxt: adj[u]){
		if(nxt == p) continue;
		if(d[nxt] <= dist+1) continue;
		run(nxt, u, dist+1);
	}
}

int main (){
	scanf("%d %d", &n, &k);
	for(int a=0;a<n-1;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}

	d[1] = -1;
	go(1, 1);
	run(k, k, 0);
	printf("%d\n", res);
}
