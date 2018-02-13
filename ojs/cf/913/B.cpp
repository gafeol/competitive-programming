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

int deg[MAXN];

vector<int> adj[MAXN];

int l(int u){
	return (deg[u] == 0);
}

void go(int u){
	if(l(u)) return ;
	int cnt = 0;
	for(int nxt: adj[u]){
		cnt += l(nxt);
		go(nxt);
	}
	if(cnt < 3){
		puts("No");
		exit(0);
	}
}

int main (){
	scanf("%d", &n);
	for(int a=2;a<=n;a++){
		int p;
		scanf("%d", &p);
		deg[p]++;
		adj[p].pb(a);
	}
	go(1);
	puts("Yes");
}

