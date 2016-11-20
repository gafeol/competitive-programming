#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
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

int n, m;
ll k;
pii s[MAXN];
ll p[MAXN], t;

ll test(ll c){
	ll ans = 0;
	for(int a=1;a<=m;a++){
		if(c < (p[a] - p[a-1]))
			return LLONG_MAX;
		if( c > 2*(p[a] - p[a-1])){
			ans += p[a] - p[a-1];
		}
		else{
			ans += 2*(p[a] - p[a-1]) - min(p[a] - p[a-1], (c - (p[a] - p[a-1])));
		}
	}
	debug("with %lld time %lld\n", c, ans);
	return ans;
}

int main (){
	scanf("%d%d%lld%lld", &n, &m, &k, &t);
	for(int a=0;a<n;a++){
		scanf("%lld%lld", &s[a].fst, &s[a].snd);
	}
	p[0] = 0;
	for(int a=1;a<=m;a++){
		scanf("%lld", &p[a]);
	}
	p[m+1] = k;
	m++;
	sort(p, p+m+1);
	ll i = 1, j = 5e9;
	while(i < j){
		ll m = (i + j)/2ll;
		debug("test %lld\n", m);
		if(test(m) <= t)
			j = m;
		else
			i = m+1;
	}
	debug("min c requi %lld\n", i);
	ll res = LLONG_MAX;
	for(int a=0;a<n;a++){
		if(s[a].snd >= i && s[a].fst < res){
			res = s[a].fst;
		}
	}
	if(res != LLONG_MAX)
		printf("%lld\n", res);
	else
		puts("-1");
}
