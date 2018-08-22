#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 3123;

int n, m, k, p[MAXN];
ll s[MAXN];

int cnt[MAXN];

multiset<ll> mn;
vector<ll> lo[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%d %lld", p+a, s+a);
		if(p[a] == 1) s[a] = 0;
		lo[p[a]].pb(s[a]);
	}
	for(int a=1;a<=m;a++)
		sort(lo[a].begin(), lo[a].end());
	ll res = LLONG_MAX;
	for(int tam=1;tam<=n;tam++){
		ll ans = 0;
		int cnt = 0;
		for(int a=0;a<n;a++)
			mn.insert(s[a]);

		for(int a=2;a<=m;a++){
			if(lo[a].size() >= tam){
				for(int b=0;b<=lo[a].size()-tam;b++){
					ans += lo[a][b];
					mn.erase(mn.find(lo[a][b]));
					cnt++;
				}
			}
		}
		while(cnt < tam){
			ans += *mn.begin();
			mn.erase(mn.begin());
			cnt++;
		}
		mn.clear();
		res = min(res, ans);
	}
	printf("%lld\n", res);
}

