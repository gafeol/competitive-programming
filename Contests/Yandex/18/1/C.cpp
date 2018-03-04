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

const int MAXN = 112345;

int n, m, k;
ll s[MAXN];

vector<int> adj[MAXN];
int v[MAXN], has[MAXN], mrk[MAXN];

ll sum[MAXN], q[MAXN];

inline ll expo(ll base, ll e){
	if(e == 0) return 1ll;
	ll ans = expo(base, e/2ll);
	ans = mod(ans*ans);
	if((e&1))
		ans = mod(ans*base);
	return ans;
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
	for(int a=1;a<=n;a++){
		scanf("%lld", s+a);
	}
	for(int a=0;a<k;a++){
		scanf("%d", v+a);
		has[v[a]] = 1;
	}
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	ll inv = expo(2ll, modn-2);
	for(int a=0;a<k;a++){
		int u = v[a];
		for(int i=0;i < adj[u].size();i++){
			int nxt = adj[u][i];
			if(!has[nxt] && s[nxt] > 0){
				puts("-1");
				return 0;
			}
			sum[nxt] = mod(sum[nxt] + s[nxt]);
		}
		q[u]++;
		s[u] =	mod(s[u]*inv);
	}
	ll res =0;
	for(int a=1;a<=n;a++){
	//	debug("a %d q %d sm %lld\n", a, q[a], sum[a]);
		ll pot = expo(2, q[a]);
		ll ans = mod(mod(sum[a]*pot)*expo(pot - 1, modn-2));
	//	debug("ans %lld\n", ans);
		res = mod(res + ans);
	}
	printf("%lld\n", res);
}

