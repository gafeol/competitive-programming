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

const int MAXN = 100010;

ll n, dp[MAXN][10], pot[MAXN];

vector<ll> p, nxt;

int main (){
	scanf("%lld", &n);
	for(ll a=0;a<MAXN;a++){
		pot[a] = a*a*a;
	}
	ll nn = n;
	ll ans = 0;
	ll sum = 0;
	int u = -1;
	for(int a=1;a<MAXN;a++){
		ll cnt = 0;
		while(sum + (cnt+1)*pot[a] <= n && sum + (cnt+1)*pot[a] < pot[a+1])
			cnt++;
		if(cnt){
			u = a;
			p.pb(a);
			debug("bota %lld pecas de tm %d\n", cnt, a);
		}
		ans += cnt;
		sum += cnt*pot[a];
	}
	n = nn;
	debug("pecas %lld\n", ans);
	nxt.pb(0);
	for(int i: p){
		debug("put %lld in nxt\n", pot[i+1]);
		nxt.pb(pot[i+1]);
	}
	ll res = sum;
	for(int a=p.size();a>=0;a--){
		//debug("searching for %lld found %lld\n", n - sum + pot[p[a]], *upper_bound(nxt.begin(), nxt.end(), n - sum + pot[p[a]]));
		int i = (--upper_bound(nxt.begin(), nxt.end(), n - sum + pot[p[a]])) - nxt.begin();
		res = max(res, sum - pot[p[a]] + nxt[i]);
		debug("substitute a %lld %lld with %lld\n", p[a], pot[p[a]],nxt[i]);

	}
	printf("%lld %lld\n", ans, res);
}
