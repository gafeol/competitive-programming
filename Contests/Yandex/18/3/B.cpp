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
const long double EPS = 1e-8;

int n, m, k;
ll s[MAXN];
ll cnt[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
		while(s[a] != 0 && s[a]%2ll == 0){
			s[a] = s[a]/2ll;
			cnt[a]++;
		}
	}
	ll res = 0;
	for(int a=1;a<n;a++){
		if(s[a] == 0 && s[a-1] > s[a]){
			res = LLONG_MAX;
			break;
		}
		if(s[a] == s[a-1]){
			res += max(0ll, cnt[a-1] - cnt[a]); 
			cnt[a] = max(cnt[a-1], cnt[a]);
		}
		else{
			long double bef = log2l((long double)s[a-1]) + (long double)cnt[a-1];
			long double val = log2l((long double)s[a]) + (long double)cnt[a];
			if(val + EPS >= bef) continue;
			ll dif = max(0ll, (ll)(bef - val - EPS - (long double)2.));
			res += dif;
			val += (long double)dif;
			cnt[a] += dif;
			while(val+EPS < bef){
				res++;
				cnt[a]++;
				val += (long double)1;
			}
		}
	}
	if(res == LLONG_MAX)
		puts("-1");
	else
		printf("%lld\n", res);
}

