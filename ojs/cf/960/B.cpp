#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plp;
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
ll k;
ll s[2][MAXN];
ll cnt[2];

multiset<ll> q;

int main (){
	scanf("%d%lld%lld", &n, &cnt[0], &cnt[1]);
	for(int t=0;t<2;t++){
		for(int a=0;a<n;a++){
			scanf("%lld", &s[t][a]);
		}	
	}
	for(int a=0;a<n;a++){
		q.insert(-abs(s[0][a] - s[1][a]));
	}
	k = cnt[0] + cnt[1];
	while(k--){
		ll u = *q.begin();
		q.erase(q.begin());
		u++;
		q.insert(-abs(u));
	}
	ll res = 0;
	while(!q.empty()){
		ll u = *q.begin();
		q.erase(q.begin());
		res += u*u;
	}
	printf("%lld\n", res);
}

