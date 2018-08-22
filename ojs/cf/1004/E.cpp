#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
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

const int MAXN = 212345, LOGN = 30;

int n, m, k;
int s[MAXN];

vector<pil> adj[MAXN][LOGN];

int main (){
	scanf("%d%d", &n, &k);
	int r = 1;
	for(int a=0;a<n;a++){
		int u, v;
		ll di;
		scanf("%d %d %lld", &u, &v, &d); 
		adj[u].pb(pil(v, d));
		adj[v].pb(pil(u, d));
	}
}

