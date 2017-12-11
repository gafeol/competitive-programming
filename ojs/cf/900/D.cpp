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

const int MAXN = 212345;

ll n, m, k;
vector<ll> pr;
set<ll> s[MAXN];
int mrk[MAXN];

ll expo(ll base, ll e){
	if(e == 0) return 1;
	ll ans = expo(base, e/2ll);
	ans = mod(ans*ans);
	if((e&1))
		ans = mod(ans*base);	
	return ans;
}

int main (){
	for(ll a=2;a<MAXN;a++){
		if(mrk[a]) continue;
		pr.pb(a);
		for(ll b=1;a*b < MAXN;b++){
			mrk[a*b]++;
			s[a*b].insert(a);
		}
	}
	scanf("%lld%lld", &n, &m);
	ll ans = 0;
	if(m%n == 0){
		m /= n;
		ans = expo(2ll, m-1);
		for(ll p = 2;p<MAXN;p++){
			if(m%p == 0){
				debug("mrk %d %d\n", p, mrk[p]); 
				if(s[p].size() == 1){
					if(*s[p].begin() == p)
						ans = mod(ans - expo(2ll, m/p - 1)); 
					continue;
				}
				if(((s[p].size())&1)){
					ans = mod(ans - expo(2ll, m/p - 1)); 
				}
				else{
					ans = mod(ans + expo(2ll, m/p - 1));
				}
			}
		}
	}
	printf("%lld\n", mod(modn + ans));
}
