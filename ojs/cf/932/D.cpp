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

const ll INF = 10000000000000000LL;

const int MAXN = 412345, LOGN = 23;

int n, m, k;

int p[MAXN][LOGN];
ll mx[MAXN][LOGN], w[MAXN];

int up[MAXN][LOGN];
ll dp[MAXN][LOGN];


void add(int r, int u, ll pes){
	w[u] = pes;
	p[u][0] = r;
	mx[u][0] = w[r];
	for(int i=1;i<LOGN;i++){
		p[u][i] = p[p[u][i-1]][i-1];
		mx[u][i] = max(mx[u][i-1], mx[p[u][i-1]][i-1]);
	}
	
	int v = u;
	for(int i=LOGN-1;i>=0;i--){
		if(mx[v][i] < pes)
			v = p[v][i];
	}
	v = p[v][0];
//	debug("up de %d eh %d\n", u, v);
	up[u][0] = v;	
	dp[u][0] = w[v];
	for(int i=1;i<LOGN;i++){
		up[u][i] = up[up[u][i-1]][i-1];
		dp[u][i] = min(INF, dp[u][i-1] + dp[up[u][i-1]][i-1]);
	}
}

int qry(int u, ll x){
	int v = u;
	int ans = 0;
	for(int i=LOGN-1;i>=0;i--){
		if(dp[v][i] <= x){
			debug("dp[%d][%d] %lld < x %lld\n", v, i, dp[v][i], x); 
			debug("de %d a %d soma %d\n", v, up[v][i], (1<<i));
			x -= dp[v][i];
			v = up[v][i];
			ans += (1<<i);
		}
	}
	return ans + 1;
}

int deg;

int main (){
	w[0] = INF;
	w[1] = 0;
	for(int i=0;i<LOGN;i++){
		mx[1][i] = mx[0][i] = INT_MAX;
		dp[1][i] = dp[0][i] = INF;
	}
	deg = 2;
	scanf("%d", &n);
	ll last = 0;
	for(int a=0;a<n;a++){
		int t;
		ll u, i;
		scanf("%d%lld %lld", &t, &u, &i);
		u = (u^last);
		i = (i^last);
		if(t == 1){
			debug("	ADD deg %d to %d w %lld\n", deg, u, i); 
			add(u, deg++, i);
		}
		else{
			debug("	QRY %d %lld\n", u, i);
			if(i < w[u])
				last = 0ll;
			else
				last = (ll)qry(u, i-w[u]);
			printf("%lld\n", last);
		}

	}
}

