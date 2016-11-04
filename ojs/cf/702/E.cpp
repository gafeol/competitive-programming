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

const int MAXN = 212345, LOGN = 35;

int n, m, nxt[MAXN][LOGN];
ll k;
ll sum[MAXN][LOGN], mn[MAXN][LOGN];

int main(){
	scanf("%d%lld", &n, &k);
	for(int a=1;a<=n;a++){
		scanf("%d", &nxt[a][0]);
		nxt[a][0]++;
	}
	for(int a=1;a<=n;a++){
		scanf("%lld", &sum[a][0]);
		mn[a][0] = sum[a][0];
	}
	ll l;
	for(l = 1; (1ll<<l) <= k;l++){
		for(int a=1;a<=n;a++){
			nxt[a][l] = nxt[nxt[a][l-1]][l-1];
			sum[a][l] = sum[nxt[a][l-1]][l-1] + sum[a][l-1];
			mn[a][l] = min(mn[nxt[a][l-1]][l-1], mn[a][l-1]);
		}
	}
	l--;
	for(int a=1;a<=n;a++){
		ll kk = k;
		int v = a;
		ll S = 0, M = LLONG_MAX;
		for(ll e = l;e>=0;e--){
			if((1ll << e) <= kk){
				kk -= (1ll << e);
				S += sum[v][e];
				M = min(M, mn[v][e]);
				v = nxt[v][e];
			}
		}
		printf("%lld %lld\n", S, M);
	}
}
