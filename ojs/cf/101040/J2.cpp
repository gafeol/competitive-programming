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

ll res, s[MAXN];

map<int, ll> dc[MAXN];
int shf[MAXN];
ll shfd[MAXN];
map<int, ll>::reverse_iterator rit;
map<int, ll>::iterator it;

vector<int> adj[MAXN];

void go(int v){
	ind[v] = deg++;
	dc[ind[v]][0] = 0;
	shf[ind[v]] = 0;
	shfd[ind[v]] = 0;
	for(int nxt: adj[v]){
		int u = nxt;
		go(u);
		shfd[ind[u]] += s[ind[u]];
		shf[ind[u]]++;
		if(dc[ind[u]].size() > dc[ind[v]].size())
			swap(ind[u], ind[v]);
		for(it = dc[ind[u]].begin();it != dc[ind[u]].end();++it){
			pii x = *it;
			int d = x.fst + shf[ind[u]] - shf[ind[v]];
			if(dc[ind[v]].count(k - d))
				res = min(res, dc[ind[u]][d] + shfd[ind[u]] + dc[ind[v]][k - d] + shfd[ind[v]]);
		}
		for(it = dc[ind[u]].begin(); it != dc[ind[u]].end(); ++it){
			pii x = *it;
			int d = x.fst + shf[ind[u]] - shf[ind[v]];
			ll cus = x.snd + shfd[ind[u]] - shfd[ind[v]];
			if(dc[ind[v]].count(d))
				dc[ind[v]][d] = min(dc[ind[v]][d], cus);
			else
				dc[ind[v]][d] = cus;
		}
		if(dc[ind[v]].find(k) != dc[ind[v]].end())
			res = min(res, dc[ind[v]][k] + shfd[ind[v]]);
	}
}

int main (){
	scanf("%d %d", &n, &k);
	res = LLONG_MAX;
	for(int a=2;a<=n;a++){
		int i;
		ll j;
		scanf("%d%lld", &i, &j);
		adj[i].pb(a);
		s[i] = j;
	}
	go(1);
	if(res == LLONG_MAX)
		puts("-1");
	else
		printf("%lld\n", res);
}
