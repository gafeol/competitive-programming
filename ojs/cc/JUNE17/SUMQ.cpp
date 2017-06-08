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

int n[5], m, k;
ll sum[4][MAXN];

vector<ll> s[4];

int main (){
	for_tests(t1, tt2){
		scanf("%d%d%d", &n[0], &n[1], &n[2]);

		for(int a=0;a<3;a++)
			s[a].clear();
		s[0].pb(LLONG_MAX);
		s[2].pb(LLONG_MAX);

		for(int tp=0;tp<3;tp++){
			for(int a=1;a<=n[tp];a++){
				ll val;
				scanf("%lld", &val);
				s[tp].pb(val);
			}
			s[tp].pb(LLONG_MIN);
			sort(s[tp].begin(), s[tp].end());
			n[tp] = s[tp].size();
		}

		
		for(int tp=0;tp<3;tp++)
			for(int a=1;a<n[tp]-1;a++)
				sum[tp][a] = mod(s[tp][a] + sum[tp][a-1]);
		
		ll l = 0, r = 0;
		ll res = 0;
		for(int a=1;a<n[1];a++){
			while(s[0][l+1] <= s[1][a])
				l++;
			while(s[2][r+1] <= s[1][a])
				r++;
			res = mod(res + mod(s[1][a]*mod(l*sum[2][r])) + mod(s[1][a]*mod(r*sum[0][l])) + mod(mod(s[1][a]*s[1][a])*mod(l*r)) + mod(sum[0][l]*sum[2][r]));
		}
		printf("%lld\n", res);
	}
}
