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

int n, m;
ll A, B;
ll s[MAXN];
ll res;

ll x[MAXN];

void solve(ll p, ll k){
	debug("solve(%lld %lld)\n", p, k);
	x[0] = 0;
	int i = 0;
	ll cnt[] = {1, 0};
	for(int a=1;a<=n;a++){
		ll val = ((s[a] >> p)&1ll);
		debug("val %lld = (%lld >> %lld = %lld)&1\n", val, s[a], p, (s[a] >> p)); 
		if(a - i > k){
			cnt[x[i]]--;
			i++;
		}
		x[a] = x[a-1]^val;
		debug("em %d somo %lld\n", a, (1ll<<p)*cnt[x[a]^1]);
		res = mod(res + (1ll<<p)*cnt[x[a]^1]);
		cnt[x[a]]++;
	}
}

int main (){
	scanf("%d %lld %lld", &n, &A, &B);
	for(int a=1;a<=n;a++){
		scanf("%lld", &s[a]);  
	}
	for(ll a=0;a<32;a++){
		solve(a, B);
	}
	ll ans = res;
	res = 0;
	for(ll a=0;a<32;a++){
		solve(a, A-1);
	}
	ans = ans -res;
	while(ans < 0)
		ans += modn;
	ans = mod(ans);
	printf("%lld\n", ans);
}
