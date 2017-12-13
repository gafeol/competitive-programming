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
int mrk[MAXN];

ll expo(ll base, ll e){
	if(e == 0) return 1;
	ll ans = expo(base, e/2ll);
	ans = mod(ans*ans);
	if((e&1))
		ans = mod(ans*base);	
	return ans;
}

int count(ll x){
	int cnt =0;
	ll val = 1;
	for(int p: pr){
		if(x%p == 0){
			cnt++;
			val *= p;
		}
	}
	return (x == val)*cnt;
}

map<ll, int> ja;

int main (){
	scanf("%lld%lld", &n, &m);
	ll ans = 0;
	if(m%n == 0){
		m /= n;
		ll val = m;
		for(ll a=2;a<MAXN;a++){
			if(mrk[a]) continue;
			if(val%a == 0) 
				pr.pb(a);
			while(val%a == 0)
				val /= a;
			for(ll b=a;a*b < MAXN;b++)
				mrk[a*b]++;
		}
		if(val != 1)
			pr.pb(val);
		ans = expo(2ll, m-1);
		if(count(m) > 0){
			if((count(m)&1))
				ans = mod(ans - 1);
			else
				ans = mod(ans + 1);
		}
		for(ll p = 2;p<MAXN;p++){
			if(m%p == 0){
				if(p > sqrt(m))
					break;
				debug("mrk %lld %d\n", p, mrk[p]); 
				if(count(p) > 0){
					if((count(p)&1))
						ans = mod(ans - expo(2ll, m/p - 1)); 
					else
						ans = mod(ans + expo(2ll, m/p - 1));
				}

				ll o = m/p;
				if(o <= p) continue;
				if(count(o) > 0){
					if((count(o)&1))
						ans = mod(ans - expo(2ll, m/o - 1)); 
					else
						ans = mod(ans + expo(2ll, m/o - 1));
				}
			}
		}
	}
	printf("%lld\n", mod(modn + ans));
}
