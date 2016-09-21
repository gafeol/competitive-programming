#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 500009;

int n, m, k;
int ind[MAXN], deg;

ll res;

map<int, ll> dc[MAXN];
map<int, ll>::reverse_iterator rit;
map<int, ll>::iterator it;

vector<pii> adj[MAXN];

void go(int v){
	ind[v] = deg++;
	dc[ind[v]][0] = 0;
	for(pii nxt: adj[v]){
		int u = nxt.fst;
		ll c = nxt.snd;
		go(u);
		for(rit = dc[ind[u]].rbegin(); rit != dc[ind[u]].rend(); ++rit){
			dc[ind[u]][rit->fst + 1] = rit->snd + c; 
		}
		if(dc[ind[u]].size() > dc[ind[v]].size())
			swap(ind[u], ind[v]);
		for(it = dc[ind[u]].begin();it != dc[ind[u]].end();++it){
			pii x = *it;
			int d = x.fst;
			ll cus = x.snd;
			if(d > k) break;
			if(dc[ind[v]].find(k - d) != dc[ind[v]].end()){
				res = min(res, cus + dc[ind[v]][k - d]);
			}
		}
		if(dc[ind[v]].find(1) != dc[ind[v]].end())
			dc[ind[v]][1] = min(dc[ind[v]][1], c);
		else
			dc[ind[v]][1] = c;

		for(it = dc[ind[u]].begin(); it != dc[ind[u]].end(); ++it){
			pii x = *it;
			int d = x.fst;
			ll cus = x.snd;
			if(dc[ind[v]].find(d) != dc[ind[v]].end())
				dc[ind[v]][d] = min(dc[ind[v]][d], cus);
			else
				dc[ind[v]][d] = cus;
		}
		if(dc[ind[v]].find(k) != dc[ind[v]].end())
			res = min(res, dc[ind[v]][k]);
	}
}

int main (){
	scanf("%d %d", &n, &k);
	res = LLONG_MAX;
	for(int a=2;a<=n;a++){
		int i;
		ll j;
		scanf("%d%lld", &i, &j);
		adj[i].pb(pii(a, j));
	}
	// 1 pode nao ser a raiz
	go(1);
	if(res == LLONG_MAX)
		puts("-1");
	else
		printf("%lld\n", res);
}
