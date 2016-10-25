

#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pli;
typedef pair<ll, ll> pil;
#define pb push_back
#define for_tests(t, tt) ll t; scanf("%lld", &t); for(ll tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const ll MAXN = 5123;
const ll INF = 3e17;

ll n, m, k, b;
ll d[MAXN], d2[MAXN], s[MAXN], sum[MAXN];

vector<pil> adj[MAXN], inv[MAXN];

set<pli> q;

ll opt[MAXN][MAXN];

ll dp[MAXN][MAXN];

ll cus(ll i, ll j){
	//de i+1 a j
	return (j-i)*(sum[j] - sum[i-1]);
}

void solve(ll i, ll j, ll l, ll r, ll kk){
	if(i > j)
		return;
	ll m = (i + j)/2ll;
	opt[m][kk] = l;
	for(ll a=l;a<=min(m,r);a++){
		dp[m][kk] = min(dp[a][kk-1] + cus(a+1, m), dp[m][kk]);
		if(dp[m][kk] == dp[a][kk-1] + cus(a+1, m))
			opt[m][kk] = a;
	}
	//printf("go %lld %lld m %lld dp[%lld][%lld] %lld\n", i, j, m, m, k, dp[m][k]);
	solve(i, m-1, l, opt[m][kk], kk);
	solve(m+1, j, opt[m][kk], r, kk);
}

main (){
	scanf("%lld%lld%lld%lld", &n, &b, &k, &m);
	for(ll a=1;a<=n;a++){
		d[a] = INF;
		d2[a] = INF;
		for(ll bb=0;bb<=k;bb++){
			dp[a][bb] = INF;
		}
	}
	for(ll a=1;a<=m;a++){
		ll i, j;
		ll c;
		scanf("%lld%lld%lld", &i, &j, &c);
		inv[i].pb(pil(j, c));
		adj[j].pb(pil(i, c));
	}
	q.insert(pli(0ll, b+1));
	d[b+1] = 0;
	while(!q.empty()){
		ll v = q.begin()->snd;
		q.erase(q.begin());
		for(pil nxt: adj[v]){
			ll u = nxt.fst;
			ll cus = nxt.snd;
			if(d[u] > d[v] + cus){
				if(d[u] != INF)
					q.erase(pli(d[u], u));
				d[u] = d[v] + cus;
				q.insert(pli(d[u], u));
			}
		}
	}
	q.insert(pli(0ll, b+1));
	d2[b+1] = 0;
	while(!q.empty()){
		ll v = q.begin()->snd;
		q.erase(q.begin());
		for(pil nxt: inv[v]){
			ll u = nxt.fst;
			ll cus = nxt.snd;
			if(d2[u] > d2[v] + cus){
				if(d2[u] != INF)
					q.erase(pli(d2[u], u));
				d2[u] = d2[v] + cus;
				q.insert(pli(d2[u], u));
			}
		}
	}
	for(ll a=1;a<=b;a++){
		s[a] = d[a] + d2[a];
	}
	sort(s+1, s+b+1);
	for(ll a=1;a<=b;a++){
		sum[a] = sum[a-1] + s[a];
	}
	k--;
	for(ll a=1;a<=b;a++){
		dp[a][0] = cus(1, a);
	//	printf("dp[%lld][%lld] %lld\n", a, 0, dp[a][0]);
	}
	for(ll kk = 1;kk <= k;kk++){
		solve(1, b, 1, b, kk);
	}
	printf("%lld", dp[b][k]);
}
