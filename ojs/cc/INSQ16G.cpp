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

const int MAXN = 212, MAXC = 1123456;

int n, m, k;
pii s[MAXN];
int xx[MAXC], yy[MAXC];
int mrk[MAXN];

vector<int> adj[MAXN];

void fail(){
	puts("Impossible");
	exit(0);
}

void go(int u, int ini, int d){
	mrk[u] = 1;
	if(d >= 4 || adj[u].size() != 2)
		fail();

	int ok = 0;
	for(int nxt: adj[u]){
		if(mrk[nxt]) continue;
		go(nxt, ini, d+1);
		ok = 1;
	}

	if(!ok && d != 3)
		fail();
}


inline ll d(int u, int v){
	return abs((ll)s[u].fst - (ll)s[v].fst) +abs((ll)s[u].snd - s[v].snd);
}

inline ll area(int u){
	return (d(u, adj[u][0])*d(u, adj[u][1]));
}

inline ll peri(int u){
	return 2ll*(d(u, adj[u][0]) + d(u, adj[u][1]));
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d %d", &s[a].fst, &s[a].snd);
	}
	sort(s, s+n);
	memset(xx, -1, sizeof(xx));
	memset(yy, -1, sizeof(yy));
	for(int a=0;a<n;a++){
		int x = s[a].fst;
		int y = s[a].snd;
	
		if(xx[x] != -1){
			adj[a].pb(xx[x]);
			adj[xx[x]].pb(a);
			xx[x] = -1;
		}
		else{
			xx[x] = a;
		}
		if(yy[y] != -1){
			adj[a].pb(yy[y]);
			adj[yy[y]].pb(a);
			yy[y] = -1;
		}
		else{
			yy[y] = a;
		}
	}
	ll resa = 0;
	ll resp = 0;
	for(int a=0;a<n;a++){
		if(mrk[a]) continue;
		go(a, a, 0);
		resa += area(a);
		resp += peri(a);
	}
	printf("%lld %lld\n", resa, resp);
}
