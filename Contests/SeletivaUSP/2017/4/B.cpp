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

const int MAXN = 21234;

int n, m, k;
int s[MAXN];
int res[MAXN][2];
vector<int> adj[MAXN];

void go(int u, int p){
	res[u][1] = k++;
	for(int nxt: adj[u]){
		if(nxt == p) continue;
		res[nxt][0] = res[u][1];
		go(nxt, u);
	}
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n-1;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	if(n == 2){
		printf("1 2\n1 2\n");
		return 0;
	}
	res[1][0] = 1;
	res[1][1] = 2;
	k = 3;
	for(int i = 0;i <  adj[1].size();i++){ 
		int nxt = adj[1][i];
		if(i == 0)
			res[nxt][0] = res[1][0];
		else
			res[nxt][0] = res[1][1];
		go(nxt, 1);
	}
	for(int a=1;a<=n;a++){
		printf("%d %d\n", res[a][0], res[a][1]);
	}
}
