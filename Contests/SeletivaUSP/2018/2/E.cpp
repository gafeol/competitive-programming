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

const int MAXN = 212345;
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

ll expo(ll base, ll e, ll m){
	if(e == 0) return 1;
	ll ans = expo(base, e/2ll, m);
	ans = (ans*ans)%m;
	if((e&1))
		ans = (ans*base)%m;
	return ans;
}

ll solve(int i, ll m){
	s[i] = (s[i]%m);
	if(i == n-1) return s[i];	
	vector<ll> path;
	path.pb(s[i]);
	ll u = (s[i]*s[i])%m;
	debug("Path %lld ", s[i]);
	while(u != s[i]){
		debug("-> %lld ", u);
		path.pb(u);
		if(u == ((u*s[i])%m))
			break;
		u = (u*s[i])%m;	
	}
	int cnt = path.size()+1;
	debug("\ncnt %d\n", (int)path.size());
	if(u == ((u*s[i])%m)){
		if(val[i+1] < path.size()){
			debug("	i %d val %lld < cnt %d\n", i, val[i+1], cnt);
			//TIRAR DEBUG
			//assert(expo(s[i], val[i+1], m) == path[val[i+1]-1]);
			return path[val[i+1]-1];
		}
		return u;
	}
	else{
		ll aux = ((cnt-2) + solve(i+1, (ll)cnt-1))%(cnt-1) + 1;
		debug("	i %d expo(%lld, %lld, %lld) %lld\n", i, s[i], aux, m, expo(s[i], aux, m));
		debug("	== path[%lld  %d] %lld\n", aux, cnt-1, path[(aux%(cnt-1))]);
		//assert(expo(s[i], aux, m) == path[((cnt-2 + aux)%(cnt-1))]);
		return path[((cnt-2+aux)%(cnt-1))];
	}
}

int main (){
	int deg = 1;
	while(scanf(" %s", p) != EOF && p[0] != '#'){
		k = atol(p);
		scanf("%d", &n);
		s[n] = 1;
		for(int a=0;a<n;a++)
			scanf("%lld", s+a);
		val[n] = 1;
		for(int a=n-1;a>=0;a--)
			val[a] = expom(s[a], val[a+1]);
		for(int a=0;a<n;a++)
			debug("%lld ", val[a]);
		debug("\n");
		printf("Case #%d: %lld\n", deg++, solve(0, k));
	}
}
