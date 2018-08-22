#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> ppl;
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
ll k, r;

vector<pll> s;
vector<ppl> e;

vector<int> alv;
int mrk[MAXN];

ppl mk(ll i, ll j, ll k){
	return ppl(pll(i, j), k);
}

void add(ll id, ll x, int t){
	e.pb(mk(x, t, id));
}

ll sq(ll x){
	return x*x;
}

int go(){
	sort(e.begin(), e.end());
	int has = n;
	for(ppl ev: e){
		int t = ev.fst.snd;
		ll x = ev.fst.fst;
		int id = ev.snd;
		if(mrk[id]) continue;

		if(t == 0)
			alv.pb(id);
		else{
			has--;
			if(has < 0) return 0;
			for(int u: alv)
				mrk[u] = 1;
			alv.clear();
		}
	}
	return 1;
}

int main (){
	for_tests(t, tt){
		s.clear();
		printf("Case %d: ", tt);
		scanf("%lld %d %d %lld", &k,  &m, &n, &r);
		for(int a=0;a<m;a++){
			ll i, j;
			scanf("%lld %lld", &j, &i);
			s.pb(pll(i,j));
		}

		e.clear();
		alv.clear();
		int ok = 1;
		for(int a=0;a<m;a++){
			mrk[a] = 0;
			ll up, dw;
			if(r < s[a].fst - k + 1){
				ok = 0;
				break;
			}
			ll dy = (ll)sqrt(sq(r) - sq(s[a].fst - k + 1));

			up = s[a].snd + dy;
			dw = s[a].snd - dy;
			add(a, dw, 0);
			add(a, up, 1);
		}
		if(ok)
			ok = go();
		if(!ok){
			puts("IMPOSSIBLE");
			continue;
		}
		ll i = 1, j = 1e9+1; 
		while(i < j){
			ll mid = (i + j +1ll)/2ll;
			e.clear();
			alv.clear();
			int ok = 1;
			for(int a=0;a<m;a++){
				mrk[a] = 0;
				ll up, dw;
				if(r < s[a].fst - k + mid){
					ok = 0;
					break;
				}
				ll dy = (ll)sqrt(sq(r) - sq(s[a].fst - k + mid));

				up = s[a].snd + dy;
				dw = s[a].snd - dy;
				add(a, dw, 0);
				add(a, up, 1);
			}
			if(ok)
				ok = go();

			if(ok)
				i = mid;
			else
				j = mid-1;
		}
		printf("%lld\n", i);
	}
}

