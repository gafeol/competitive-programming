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
ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define int ll

const int MAXN = 212345;
int n;
ll s, t;
ll S[MAXN];
map<ll, ll> cus; 
multiset<ll> q;

ll go(ll u){
	ll ans = 0;		
	while(!q.empty()){
		if(q.lower_bound(u) == q.end()){
			ans += s - u;
			u = 0;
		}
		ll i = *q.lower_bound(u);
		q.erase(q.find(i));
		ans += i - u;
		u = i;
		ans += t;
		u = mod(u + t);
	}
	return ans;
}

vector<ll> dist;
ll resp = 0, resq = 1;

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

main (){
	scanf("%lld %lld %lld", &n, &s, &t);
	modn = s;
	for(int a=0;a<n;a++){
		scanf("%lld", &S[a]);	
		dist.pb(S[a]);
	}
	sort(dist.begin(), dist.end());
	dist.erase(unique(dist.begin(), dist.end()), dist.end());
	ll mn = LLONG_MAX, mx = LLONG_MIN;
	ll som = 0;
	for(int a=0;a<n;a++){
		if(cus.find(S[a]) != cus.end())
			continue;
		q.clear();
		for(int b=0;b<n;b++)
			q.insert(S[b]);
		cus[S[a]] = go(S[a]);
		debug("se comeco em %lld custo %lld\n", S[a], cus[S[a]]);
		mn = min(mn, cus[S[a]]);
		mx = max(mx, cus[S[a]]);
	}
	for(int i = 0;i < dist.size()-1;i++){
		ll pos = dist[i]+1;
		ll d = dist[i+1] - pos;
		som += ((cus[dist[i+1]]*2ll + d)*(d + 1ll))/2ll;
		mx = max(cus[dist[i+1]] + d, mx);
	}
	ll pos = mod(dist[dist.size()-1]+1);
	ll d;
	if(pos <= dist[0])
		d = dist[0] - pos;
	else
		d = s - pos + dist[0];
	debug("som %lld\n", som);
	som += ((cus[dist[0]]*2ll + d)*(d + 1ll))/2ll;
	debug("som %lld\n", som);
	mx = max(cus[dist[0]] + d, mx);
	assert(som >= 0);
	resp = som/gcd(som, s);
	resq = s/gcd(som, s);
	printf("%lld\n%lld\n%lld/%lld\n", mn, mx, resp, resq);
}
