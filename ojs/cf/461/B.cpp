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
ll res = 1;
vector<int> adj[MAXN];

void go(int u, int p, int d){
	if(s[u] == 1 && d != 0){
		res = mod(res*d);
		d = 0;
	}
	for(int nxt: adj[u]){
		if(nxt == p) continue;
		go(nxt, u, d+1);
	}
}

int main (){
	scanf("%d", &n);
	int u = -1;
	for(int a=0;a<n-1;a++){
		int p;
		scanf("%d", &p);
		adj[p].pb(a+1);
		adj[a+1].pb(p);
	}
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		if(s[a] == 1)
			u = a;
	}
	go(u, -1, 0);
	printf("%lld", res);
}
