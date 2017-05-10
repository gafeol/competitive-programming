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

const int MAXN = 512;

int n, m;
int s[MAXN], cus[MAXN];
int mrk[MAXN];
ll p, q;

vector<pii> adj[MAXN];

void go(int u){
	mrk[u] = 1;
	int imx = -1;
	ll i = 0, j = 0;
	for(int a = 0;a <= adj[u].size();a++){
		pii nxt = adj[u][a];
		int v = nxt.fst;
		if(mrk[v]) continue;
		int c = nxt.snd;
		cus[v] += c;
		if(i*q + p*cus[v] + i*cus[v] < q*s[v] + j*p + s[v]*j){
			i = s[v];
			j = cus[v];
			imx = v; 
		}
	}

	p = p + i;
	q = q + j;
	debug("passei pelo cara %d p %lld q %lld\n", u, p, q);
	if(imx != -1)
		go(imx);
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
	}
	for(int a=0;a<m;a++){
		int i, j, k;
		scanf("%d %d %d", &i, &j, &k);
		adj[i].pb(pii(j, k));
		adj[j].pb(pii(i, k));
		}
	double ans = 0; 
	for(int a=1;a<=n;a++){
		memset(cus, 0, sizeof(cus));
		memset(mrk, 0, sizeof(mrk));
		p = s[a];
		go(a);
		debug("p %lld q %lld\n", p, q);
		if(q != 0)
			ans = max(ans, ((double)p/q));
	}
	printf("%.10f\n", ans);
}
