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

ll n, m;
int k;
pii s[MAXN];

map<ll, vector<pii> > ind;
vector<ll> X;

vector<pii> v;

multiset<ll> p;


void add(int id, ll t){
	p.insert(s[id].snd - t);
	p.insert(s[id].snd);
	p.insert(s[id].snd + t);
}

void rmv(int id, ll t){
	p.erase(p.find(s[id].snd - t));
	p.erase(p.find(s[id].snd));
	p.erase(p.find(s[id].snd + t));
}

bool go(ll t){
	p.clear();
	X.clear();
	ind.clear();
	ll mnx = n-1, mxx = 0, mny = m-1, mxy = 0;
	for(int a=0;a<k;a++){
		ind[s[a].fst - t].pb(pii(a, 0));	
		ind[s[a].fst + t + 1].pb(pii(a, 1));
		X.pb(s[a].fst - t);
		X.pb(s[a].fst + t + 1);
		X.pb(s[a].fst - t - 1);
		X.pb(s[a].snd + t + 2);
	}
	X.pb(0);
	X.pb(n-1);
	p.insert(m + t);
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	for(ll x : X){
		v = ind[x];
		for(pii e: v){
			int tp = e.snd;
			int id = e.fst;
			if(tp == 0)
				add(id, t);
			else
				rmv(id, t);
		}
		if(x < 0 || x >= n) continue;
		debug("em x %lld:\n", x); 
		int ulty = -t-1;
		for(auto &it : p){
			ll y = it;
			debug("	y %lld\n", y);
			if(max(0ll, ulty + t + 1ll) < min(y - t, m)){
				mnx = min(mnx, x);
				mxx = max(mxx, x);
				mny = min(mny, max(0ll, ulty + t + 1));
				mxy = max(mxy, min(y - t - 1, m-1));
				debug("mnx = %lld mxx %lld mny %lld mxy %lld\n", mnx, mxx, mny, mxy);
			}
			ulty = y;
		}
	}
	debug("t %lld mnx %lld mxx %lld mny %lld mxy %lld\n", t, mnx, mxx, mny, mxy);
	return (max(mxx - mnx, mxy - mny) + 1  <= 2*t + 1);
}

int main (){
	scanf("%lld%lld%d", &n, &m, &k);
	for(int a=0;a<k;a++){
		ll x, y;
		scanf("%lld %lld", &x, &y);
		x--;
		y--;
		s[a] = pii(x, y);
	}
	ll i = 0, j = 1e9;
	while(i < j){
		ll m = (i+j)/2;
		if(go(m))
			j = m;
		else
			i = m+1;
	}
	printf("%lld\n", i);
}

