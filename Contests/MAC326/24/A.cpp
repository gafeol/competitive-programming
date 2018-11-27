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

int n, m, k;
int s[MAXN];

vector<pii> adj[MAXN];

vector<ll> f;

void go(int u, ll t){
	if(adj[u].empty()){
		f.pb(t);	
		return ;
	}

	ll mn = LLONG_MAX, imn;
	for(int i = 0;i < adj[u].size();i++){
		pii ar = adj[u][i];
		int v = ar.fst;	
		ll d = ar.snd;

		if(d < mn){
			mn = d;
			imn = i;
		}
	}

	for(int i = 0;i < adj[u].size();i++){
		pii ar = adj[u][i];
		int v = ar.fst;	
		ll d = ar.snd;
		if(i == imn)
			go(v, t+d);	
		else
			go(v, t + 2ll*d - (ll)mn);
	}
}

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		for(int a=1;a<=n;a++)
			adj[a].clear();
		for(int a=2;a<=n;a++){
			int p, c;
			scanf("%d%d", &p, &c);
			adj[p].pb({a, c});
		}
		f.clear();
		go(1, 0ll);
		sort(f.begin(), f.end());
		scanf("%d", &m);
		for(int a=0;a<m;a++){
			ll qt;
			scanf("%lld", &qt);
			printf("%d\n", (int)(upper_bound(f.begin(), f.end(), qt) - f.begin()));
		}
	}
}

