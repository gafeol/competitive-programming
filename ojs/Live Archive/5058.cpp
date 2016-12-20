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
const ll modn = 1000003;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 4123;

int n, m, k;
int s[MAXN], ind[MAXN], l[MAXN], r[MAXN];

ll ans[MAXN];
ll fat[MAXN];
unordered_map<int, ll> sz;


bool cmp(int a,int b){
	return ind[a] < ind[b];
}

int build(int v, int u){
	if(v == -1) return u;
	sz[v]++;
	if(u > v)
		r[v] = build(r[v], u);
	else
		l[v] = build(l[v], u);
	return v;
}

ll expo(ll b, ll e){
	//debug("expo (%lld %lld) = \n", b, e);
	ll val = b;
	ll res = 1;
	while(e > 0ll){
		if(e&1ll)
			res = mod(res*val);
		val = mod(val*val);
		e >>= 1ll;
	}
//	debug("= %lld\n", res);
	return res;
}

ll choose(ll a, ll b){
	return mod(mod(fat[a]*expo(fat[b], modn-2))*expo(fat[a-b], modn-2));
}

ll go(int u){
	if(u == -1)
		return 1;
	ll nl = go(l[u]);
	ll nr = go(r[u]);
	return ans[u] = mod(mod(nl*nr)*choose(sz[l[u]] + sz[r[u]], sz[r[u]]));
}

set<int> q;

int main (){
	fat[0] = 1;
	fat[1] = 1;
	for(ll a=2;a<MAXN;a++){
		fat[a] = mod(fat[a-1]*a);
	}
	for_tests(t, tt){
		sz.clear();
		scanf("%d%d", &n, &m);
		for(int a=1;a<=n;a++){
			scanf("%d", &s[a]);
			sz[s[a]] = 1;
			l[s[a]] = -1;
			r[s[a]] = -1;
			ans[s[a]] = 0;
		}
		sz[-1] = 0;
		for(int a=2;a<=n;a++){
			build(s[1], s[a]);
		}
		debug("choose (%d %d): %lld go - %lld\n", m, n, choose(m, n), go(s[1])); 
		printf("%lld\n", mod(choose(m, n)*go(s[1])));
	}
}
