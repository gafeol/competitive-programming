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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;

#define int ll

inline ll mod(ll x) { return x % modn; }

const int MAXN = 300005;

int n, np; 
ll s[MAXN];

ll k[MAXN];

int q, L[MAXN], R[MAXN];
ll c[MAXN];

unordered_map<int, vector<int> > v;
unordered_map<int, vector<int> > pos;

int res[MAXN];

struct arv{
	ll lz, x;
};

unordered_map<int, arv> tree;

unordered_map<int, int> vis;

int tempo;

void check(int x){
	if(vis[x] != tempo){
		vis[x] = tempo;
		tree[x].x = 0;
		tree[x].lz = 0;
	}
}

void unlaze(int idx, int i, int j){
	if(tree[idx].lz == 0) return;
	int aux = tree[idx].lz;
	tree[idx].lz = 0;
	if(i != j){
		check(idx*2);
		tree[idx*2].x += aux;
		tree[idx*2].lz += aux;
		check(idx*2+1);
		tree[idx*2+1].x += aux;
		tree[idx*2+1].lz += aux;
	}
}


void upd(int idx, int i, int j, int l, int r, ll x){
	if(i > r || j < l) return ;
	check(idx);
	unlaze(idx, i, j);
	if(i >= l && j <= r){
		tree[idx].x += x;
		tree[idx].lz += x;
		return ;
	}
	int m = (i+j)/2;
	upd(idx*2, i, m, l, r, x);
	upd(idx*2+1, m+1, j, l, r, x);
}

ll qry(int idx, int i, int j, int l){
	if(l > j || l < i) return 0;	
	check(idx);
	unlaze(idx, i, j);
	if(i == j)
		return tree[idx].x;
	int m = (i+j)/2;
	return qry(idx*2, i, m, l) + 
			qry(idx*2+1, m+1, j, l);
}

void go(int idx, int i, int j){
	if(v[idx].empty()) return ;
	if(i == j){
		for(int a=0;a<v[idx].size();a++){
			int u = v[idx][a];
			res[u] = i;
		}
		return ;
	}
	tempo++;
	int m = (i + j)/2;
	for(int a=i;a<=m;a++){
		int l = L[a], r = R[a], x = c[a];
		if(l > r){
			upd(1, 0, n-1, l, n-1, x);
			upd(1, 0, n-1, 0, r, x);
		}
		else
			upd(1, 0, n-1, l, r, x);
	}
	for(int u: v[idx]){
		ll ans = 0;
		for(int p: pos[u]){
			ans += qry(1, 0, n-1, p);
			if(ans >= k[u]) break;
		}
		if(ans >= k[u])
			v[idx*2].pb(u);
		else{
			k[u] -= ans;
			v[idx*2+1].pb(u);
		}
	}
	v[idx].clear();
	go(idx*2, i, m);
	go(idx*2+1, m+1, j);
}


main (){
	scanf("%lld%lld", &np, &n);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);	
		s[a]--;
		pos[s[a]].pb(a);
	}
	for(int a=0;a<np;a++){
		scanf("%lld", k+a); 
		v[1].pb(a);
	}
	scanf("%lld", &q);
	for(int a=0;a<q;a++){
		scanf("%lld %lld %lld", L+a, R+a, c+a);	
		L[a]--;
		R[a]--;
	}
	L[q] = 0;
	R[q] = n-1;
	c[q] = 1000000001;
	go(1, 0, q); 
	for(int a=0;a<np;a++){
		if(res[a] == q)
			puts("NIE");
		else
			printf("%lld\n", res[a]+1);
	}
}
