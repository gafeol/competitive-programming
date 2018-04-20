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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1123456;
const ll INF = 1000000000LL;

int n, m;

ll k;
char p[MAXN];
ll s[MAXN], val[MAXN];

ll expom(ll base, ll e){
	if(e == 0) return 1;
	ll ans = expom(base, e/2ll);
	ans = min(INF, ans*ans);
	if((e&1))
		ans = min(INF, ans*base);
	return ans;
}

ll solve(int i, ll m){
	s[i] = (s[i]%m);
	if(i == n-1) return s[i];	
	vector<ll> path;
	path.pb(s[i]);
	map<ll, int> mrk;
	mrk[s[i]] = 0;
	int aux = 1;
	ll u = (s[i]*s[i])%m;
	debug("Path %lld ", s[i]);
	while(mrk.find(u) == mrk.end()){
		debug("-> %lld ", u);
		path.pb(u);
		mrk[u] = aux++;
		u = (u*s[i])%m;	
	}
	int cyc = mrk[u];
	if(val[i+1] <= path.size())
		return path[val[i+1]-1];
	else{
		int mns = mrk[u];
		int cycsz = path.size() - mns; 
		debug("mns %d cycsz %d\n", mns, cycsz);
		ll sv = solve(i+1, (ll)cycsz);
		ll aux = (cycsz + ((sv - mns - 1)%cycsz))%cycsz;
		return path[mns + aux];
	}
}

int main (){
	int deg = 1;
	while(scanf(" %s", p) != EOF && p[0] != '#'){
		if(deg > 1) puts("");
		k = atol(p);
		scanf("%d", &n);
		s[n] = 1;
		for(int a=0;a<n;a++)
			scanf("%lld", s+a);
		val[n] = 1;
		for(int a=n-1;a>=0;a--)
			val[a] = expom(s[a], val[a+1]);
		printf("Case #%d: %lld", deg++, solve(0, k));
	}
}
