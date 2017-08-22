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


multiset<ll> ev;

void add(int id){
	ev.insert(s[id].fst);
	debug("add s[%d] %lld\n", id, s[id].fst);
}
void rmv(int id){
	ev.erase(ev.find(s[id].fst));
}

bool go(ll t){
	if(t == 0){
		return (n*m == k-1);
	}
	ll mnx = n-1, mxx = 0, mx = 0, mn = m-1;
	ind.clear();
	ev.clear();
	for(int a=0;a<k;a++){
		ind[s[a].fst-t].pb(pii(a, 0));
		ind[s[a].fst+t].pb(pii(a, 1));
	}
	vector<pii> v;
	ind[n+t].pb(pii(0, 0));
	ind[n+t].pb(pii(0, 1));
	ll lstx = -2*t-1;
	for(auto &r: ind){
		ll x = r.fst;
		v = r.snd;	
		int has = 0;
		for(pii e: v){
			if(e.snd == 0){
				has = 1;
				add(e.fst);
			}
		}
		if(has && lstx + 2*t + 1 < x - t){
			debug("nao cobre todo x de %lld a %lld\n", lstx, x);
			mnx = min(mnx, lstx+2*t+1);
			mxx = max(mxx, x-t-1);
		}
		if(has) lstx = x;
		if(x == n+t)
			break;
		ev.insert(m+t);
		ll lst = -2*t-1;
		for(auto e: ev){
			if(lst + 2*t + 1 < e - t){
				debug("nao cobre todo y de %lld a %lld\n", lst, e);
				mn = min(mn, lst+2*t+1);
				mx = max(mx, e-t-1);
			}
			debug("lst(%lld) = %lld\n", lst, e);
			lst = e;	
		}
		for(pii e: v){
			if(e.snd == 0){
				rmv(e.fst);
			}
		}
	}
	debug("t %lld\n", t);
	debug("%lld %lld %lld %lld\n", mxx, mnx, mx, mn);
	if(max(mxx - mnx, mx - mn)+1 <= 2*t + 1)
		return 1;
	return 0;
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

