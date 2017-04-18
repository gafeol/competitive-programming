#include <bits/stdc++.h>
using namespace std;
#define int ll
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 2123456;

ll n, m, k;

set<ll> q;
map<ll, ll> cnt;

main (){
	for_tests(t, tt){
		scanf("%lld%lld", &n, &k);	
		cnt.clear();
		q.clear();
		q.insert(-n);
		cnt[n] = 1;
		ll resmn=LLONG_MAX, resmx=LLONG_MIN;
		ll count = 0;
		while(1){
			ll tam = -(*q.begin());
			q.erase(q.begin());
			ll x1 = ((tam-1ll)>>1ll) + ((tam-1ll)&1);
			ll x2 = ((tam-1ll)>>1ll);
			resmn = min(x1, x2);
			resmx = max(x1, x2);
			count += cnt[tam];
			if(count >= k)
				break;
			q.insert(-x1);
			q.insert(-x2);
			cnt[x1]+=cnt[tam];
			cnt[x2]+=cnt[tam];
		}
		printf("Case #%lld: %lld %lld\n", tt, resmx, resmn);
	}
}
