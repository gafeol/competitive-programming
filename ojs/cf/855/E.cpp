
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

const int MAXN = 212345, MASK = (1<<11) + 10;

int n, m, k;
int s[MAXN];

ll dp[67][11][MASK][2], pot[11][70];

ll go(int i, int b, int bm, int lz){
	if(i < 0) return 0;
	if(dp[i][b][bm][lz] != -1)
		return dp[i][b][bm][lz];
	if(i == 0) return dp[i][b][bm][lz] = (bm == 0);
	dp[i][b][bm][lz] = 0;
	for(int d=0;d<b;d++){
		dp[i][b][bm][lz] += go(i+1, b, (bm^(1<<b)), min(lz, (int)(d == 0)));
	}
	return dp[i][b][bm][lz];
}

queue<int> brk;

ll solve(int b, ll v){
	int i =0;
	for(;pot[b][i] <= v;i++);
	i--;
	debug("break %lld in base %d\n", v, b);
	for(int a = i;a>=0;a--){
		brk.push(v/pot[b][a]);
		debug("	%lld", v/pot[b][a]);
		v -= (v/pot[b][a])*pot[b][a];
	}
	debug("\n");
	ll ans = 0;
	int bm = 0, lz = 1;
	for(int d=i;!brk.empty();d--){
		int lst = brk.front(); 
		brk.pop();
		bm = (bm^(1<<lst));
		if(lst > 1)
			ans += (lst-1)*go(d-1, b, bm, 0);
		if(lst > 0) ans += go(d-1, b, bm, 1);
	}
	if(bm == 0)
		ans++;

	return ans;
}


int main (){
	for(int b=2;b<=10;b++){
		pot[b][0] = 1;
		for(int i =1;pot[b][i-1] < 1e18;i++){
			pot[b][i] = ll(b)*pot[b][i-1];
			debug("pot %d %d %lld\n", b, i, pot[b][i]);
			pot[b][i+1] = LLONG_MAX;
		}
	}
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for(int a=0;a<n;a++){
		ll l, r;
		int b;
		scanf("%d %lld %lld", &b, &l, &r); 
		ll ans = solve(b, r) - solve(b, l-1);
		printf("%lld\n", ans);
	}
}

