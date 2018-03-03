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
int mrk[MAXN];

vector<int> adj[MAXN];

int raiz(int u){
	if(pai[u] == u) return u;
	return pai[u] = raiz(pai[u]);
}



int add(int u){
	map<int, int> mx;
	mrk[u] = 1;
	int r = raiz(u);
	for(int nxt: adj[u]){
		if(mrk[nxt]){
			mx = max(mx, nxt);
			int rr = raiz(nxt);
			mx[rr] = max(mx[rr], nxt);
			if(rr == r)
				return 0;
		}
	}
	for(auto it: mx){

	}

}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d %d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	int j = 1;
	add(i);
	for(int i = 0;i < n;i++){
		while(
	}
}

