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

const int MAXN = 2123;

int n, m, k, d;
vector<pii> s[MAXN];
int mrk[MAXN];

ll som;

vector<int> adj[MAXN];

vector<pii> dg;

void go(int u){
	mrk[u] = 1;
	if(!s[u].empty()){
		for(pii dragon: s[u]){
			dg.pb(dragon);
		}
	}
	for(int nxt: adj[u]){
		if(mrk[nxt]) continue;
		go(nxt);		
	}
}

bool cmp(pii a, pii b){
	return (a.fst > b.fst || (a.fst == b.fst && a.snd < b.snd));
}

int main (){
	scanf("%d%d%d", &n, &m, &d);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	for(int a=0;a<d;a++){
		int u, sx, gx;
		scanf("%d %d %d", &u, &sx, &gx);
		s[u].pb(pii(gx, sx));
	}
	ll res = 0;
	for(int a=0;a<n;a++){
		dg.clear();
		som = 0;
		if(!mrk[a])
			go(a);
		if(dg.empty()) continue;

		sort(dg.begin(), dg.end(), cmp);
		ll ans = dg[0].fst + 1; 
		for(int i = 0;i < dg.size();i++){
			pii u = dg[i];
			som += (ll)u.snd;	
			ll mx;
			if(i != dg.size()-1)
				mx = dg[i+1].fst + 1;
			else
				mx = 0;
			ans = min(ans, max(som, mx));
		}
		res += ans;
	}
	printf("%lld\n", res);
}
