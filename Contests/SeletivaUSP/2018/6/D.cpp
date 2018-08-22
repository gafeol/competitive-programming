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

const int MAXN = 21;

int n, m, k;

vector<int> adj[MAXN];

int cor[MAXN];

bool valid(int u, int c){
	for(int nxt: adj[u]){
		if(cor[nxt] == c) return false;
	}
	return true;
}

int go(int u, int mx){
	if(u == n) return 1;
	cor[u] = 1;
	while(cor[u] <= mx){
		while(cor[u] <= mx && !valid(u, cor[u])) cor[u]++;
		if(cor[u] > mx) break;
		if(go(u+1, mx)) return 1;
		if(u == 0) return 0;
		cor[u]++;
	}
	cor[u] = 0;
	return 0;
}


int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &m);
		memset(cor, 0, sizeof(cor));
		for(int a=0;a<n;a++)
			adj[a].clear();
		for(int a=0;a<m;a++){
			int i, j;
			scanf("%d %d", &i, &j);
			if(i < j) swap(i, j);
			adj[i].pb(j);
		}
		int ok = 0;
		for(int res=1;res<=4;res++){
			if(go(0, res)){
				ok = 1;
				printf("%d\n", res);
				break;
			}
		}
		if(!ok)
			puts("many");
	}
}

