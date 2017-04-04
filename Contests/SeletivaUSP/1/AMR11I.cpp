#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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

const int MAXN = 312345;

int n, m, k;
int gen[MAXN], res[MAXN];

vector<pll> s[MAXN*4];

vector<ll> cm;
unordered_map<ll, int> ind, mrk;

pll d[MAXN];

set<pii> q;

vector<int> adj[MAXN];

int L[MAXN], R[MAXN], deg, tree[MAXN*4];

void go(int u){
	L[u] = deg;
	for(int nxt: adj[u]){
		go(nxt);
	}
	R[u] = deg++;
}

void upd(int idx, int i, int j, int l, int val){
	if(i > l || j < l) return;
	if(i >= l && j <= l){
		tree[idx] = max(val, tree[idx]);
		return ;
	}
	int m = (i+j)>>1;
	upd(idx*2, i, m, l, val);
	upd(idx*2+1, m+1, j, l, val);
	tree[idx] = max(tree[idx*2], tree[idx*2+1]);
}

int qry(int idx, int i, int j, int l, int r){
	if(i > r || j < l) return 0;
	if(i >= l && j <= r)
		return tree[idx];
	int m = (i+j)>>1;
	return max(qry(idx*2, i, m, l, r), qry(idx*2+1, m+1, j, l, r));
}

int main (){
	for_tests(t, tt){
		q.clear();
		ind.clear();
		cm.clear();
		mrk.clear();
		memset(tree, 0, sizeof(tree));
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			adj[a].clear();
			int p;
			ll i, j;
			scanf("%d %lld %lld", &p, &i, &j);
			i *= 2ll;
			j *= 2ll;
			j++;
			d[a] = pii(i, j);
			if(mrk.find(i) == mrk.end()){
				cm.pb(i);
				mrk[i] = 1;
			}
			if(mrk.find(j) == mrk.end()){
				cm.pb(j);
				mrk[j] = 1;
			}
			if(p != -1){ 
				gen[a] = gen[p]+1;
				adj[p].pb(a);
			}

		}
		go(0);
		sort(cm.begin(), cm.end());
		for(int a=0;a<cm.size();a++){
			ind[cm[a]] = a;
		}
		for(int a=0;a<n;a++){
			//	assert(ind.find(d[a].fst) != ind.end());
			//	assert(ind.find(d[a].snd) != ind.end());
			s[ind[d[a].fst]].pb(pii(a, 0));
			s[ind[d[a].snd]].pb(pii(a, 1));
		}
		//s fst-a snd-t
		for(int a=0;a<cm.size();a++){
			for(pii ev: s[a]){
				int u = ev.fst;
				if(!ev.snd)
					upd(1, 0, deg-1, R[u], gen[u]);
				else
					res[u] =  qry(1, 0, deg-1, L[u], R[u]) - gen[u];
			}
			s[a].clear();
		}
		for(int a=0;a<n;a++){
			printf("%d ", res[a]);
		}
		printf("\n");
	}
}
