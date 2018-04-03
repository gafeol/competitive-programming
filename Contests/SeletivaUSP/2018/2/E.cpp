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

ll k;
char p[MAXN];
ll s[MAXN];

ll expo(ll base, ll e, ll m){
	if(e == 0) return 1;
	ll ans = expo(base, e/2ll, m);
	ans = (ans*ans)%m;
	if((e&1))
		ans = (ans*base)%m;
	return ans;
}

int ehmen(int i, ll x){
	if(i == n-1 || s[i] == 1)
		return (s[i] < x);
	ll ans = 0;
	int j = i;
	for(j = i;j < n;j++)
		if(s[j] == 1)
			break;
	j--;
	while(j > i){
		
	}

}

ll solve(int i, ll m){
	if(i == n-1) return (s[i]%m);	
	int cnt = 2;
	s[i] = s[i]%m;
	ll u = (s[i]*s[i])%m;
	while(u != 0 && u != s[i]){
		u = (u*s[i])%m;	
		cnt++;
	}
	if(u == 0){
		if(ehmen(i+1, cnt))
			return expo(s[i], brute(i+1), m);
		return 0;
	}
	else
		return expo(s[i], solve(i+1, (ll)cnt) + 1, m);
}

int main (){
	int deg = 1;
	while(scanf(" %s", p) != EOF && p[0] != '#'){
		k = atol(p);
		scanf("%d", &n);
		s[n] = 1;
		for(int a=0;a<n;a++)
			scanf("%lld", s+a);
		printf("Case #%d: %lld\n", deg++, solve(0, k));
	}
}
