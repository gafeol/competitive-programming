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

vector<pil> adj[MAXN];

int p[MAXN][LOGN];

void go(int u, int pai){
	p[u][0] = pai;
	for(i = 1;i<LOGN;i++)
		p[u][i] = p[p[u][i-1]][i-1];
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<n;a++){
		int i, j;
		ll c;
		scanf("%d %d %lld", &i, &j, &c);
		adj[i].pb(pil(j, c));
		adj[j].pb(pil(i, c)).
	}
	go(1);
}

