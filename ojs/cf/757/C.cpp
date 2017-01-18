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

const int MAXN = 212345, MAXM = 1123456;

int n, m, k;

vector<int> s[MAXN];

map<vector<pii>, vector<int>> mrk; 

vector<pii> apa[MAXM];

map<int, int> cnt;

vector<int> t;

ll f[MAXM];

ll expo(ll base, ll e){
	if(e == 1) return base;
	ll ans = expo(base, e/2ll);
	ans = mod(ans*ans);
	if(e&1)
		ans = mod(ans*base);
	return ans;
}

int main (){
	f[0] = 1;
	f[1] = 1;
	for(ll a=2;a<MAXM-10;a++){
		f[a] = mod(f[a-1]*a);
	}
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		int tam;
		scanf("%d", &tam);
		for(int b=0;b<tam;b++){
			int x;
			scanf("%d", &x);
			t.pb(x);
			s[a].pb(x);
			cnt[x]++;
		}
		for(int b=0;b<tam;b++){
			int x = s[a][b];
			if(cnt.find(x) != cnt.end()){
				apa[x].pb(pii(a, cnt[x]));
				cnt.erase(x);
			}
		}
	}
	ll res = 1;
	sort(t.begin(), t.end());
	t.erase(unique(t.begin(), t.end()), t.end());
	for(int pk: t){
		mrk[apa[pk]].pb(pk);
	}
	for(int pk: t){
		if(mrk[apa[pk]].size() > 1){
			res = mod(res*f[mrk[apa[pk]].size()]);
			mrk.erase(apa[pk]);
		}
	}
	res = mod(res*f[(m - t.size())]);
	printf("%lld\n", res);
}
