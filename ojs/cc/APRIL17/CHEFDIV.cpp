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

const int MAXN = 1123456;

int n, m, k;
ll A, B;

int mrk[MAXN];
vector<ll> p;

set<int> cnt[MAXN];
multiset<int> qtd;

int main (){
	scanf("%lld %lld", &A, &B);
	for(ll a=2;a<MAXN;a++){
		if(mrk[a]) continue;
		p.pb(a);
		for(ll b = a;b*a < MAXN;b++){
			mrk[b*a] = 1;
		}
	}
	for(ll pri: p){
		if(pri > B) continue;
		ll val = pri*(A/pri);
		while(val < A)
			val += pri;
		while(val <= B){
			cnt[val-A].insert(pri);
			debug("%lld insert %lld\n", val, pri);
			val += pri;
		}
	}
	ll res = 0;
	for(ll i = 0;i <= B-A;i++){
		ll left = A + i;
		ll mult = 1;
		while(!cnt[i].empty()){
			ll beg = *cnt[i].begin();
			cnt[i].erase(beg);
			int k = 0;
			while(left%beg == 0){
				k++;
				left /= beg;
			}
			qtd.insert(k);
			mult *= (k+1ll);
		}
		if(left != 1){
			mult *= 2ll;
			qtd.insert(1);
		}
		debug("mult %lld\n", mult);
		while(mult != 1){
			res += mult;
			ll bigg = *qtd.rbegin();
			debug("tira o cara de qtd %lld\n", bigg);
			qtd.erase(qtd.find(bigg));
			mult /= (bigg+1);
			bigg--;
			mult *= (bigg+1);
			qtd.insert(bigg);
		}
		qtd.clear();
	}
	printf("%lld\n", res);
}

