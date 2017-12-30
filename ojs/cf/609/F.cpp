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
#define debug(args...) fprintf(stderr,args);
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 412345;

int n, m, k;
ll s[MAXN], p[MAXN];
ll mx[MAXN], ms[MAXN];

vector<ll> X;

map<ll, int> ind;

int up(ll x){
	return upper_bound(X.begin(), X.end(), x) - X.begin() - 1;
}

bool cmp(int a, int b){
	return p[a] < p[b];
}

int in[MAXN];

struct arv{
	int f, lz; 
	int mn;

	arv(){
		mn = INT_MAX;
		f = -1;
		lz = -1;
	}
} tree[4*MAXN];

int men(int i, int j){
	if(i == -1) return j;
	if(j == -1) return i;
	return ((in[i] < in[j]) ? i : j); 
}

void unlaze(int idx, int i, int j){
	if(tree[idx].lz != -1){
		if(i != j){
			tree[idx*2].f = men(tree[idx].lz, tree[idx*2].f);
			tree[idx*2+1].f = men(tree[idx].lz, tree[idx*2+1].f);
			tree[idx*2].lz = men(tree[idx].lz, tree[idx*2].lz);
			tree[idx*2+1].lz = men(tree[idx].lz, tree[idx*2+1].lz);
		}
		tree[idx].lz = -1;
	}
}

void updf(int idx, int i, int j, int l, int r, int f){
	if(i > r || j < l) return ;
	unlaze(idx, i, j);
	if(i >= l && j <= r){
		tree[idx].f = men(tree[idx].f, f);
		tree[idx].lz = men(tree[idx].lz, f); 
		return ;
	}
	int m = (i + j)/2;
	updf(idx*2, i, m, l, r, f);
	updf(idx*2+1, m+1, j, l, r, f);
	tree[idx].f = men(tree[idx*2].f, tree[idx*2+1].f);
}

void updm(int idx, int i, int j, int l, int mo){
	if(i > l || j < l) return ;
	unlaze(idx, i, j);
	if(i >= l && j <= l){
		tree[idx].mn = mo;
		return ;
	}
	int m = (i + j)/2;
	updm(idx*2, i, m, l, mo);
	updm(idx*2+1, m+1, j, l, mo);
	tree[idx].mn = min(tree[idx*2].mn, tree[idx*2+1].mn); 
	tree[idx].f = men(tree[idx*2].f, tree[idx*2+1].f);
}

int qrym(int idx, int i, int j, int l){
	if(i > l || j < l) return -1;
	unlaze(idx, i, j);
	if(i >= l && j <= l){
		return tree[idx].f;
	}
	int m = (i + j)/2;
	int res = men(qrym(idx*2, i, m, l),
			qrym(idx*2+1, m+1, j, l));
	tree[idx].f = men(tree[idx*2].f, tree[idx*2+1].f);
	return res;
}

int qryf(int idx, int i, int j, int l, int r){
	if(i > r || j < l) return INT_MAX;
	unlaze(idx, i, j);
	if(i >= l && j <= r){
		return tree[idx].mn;
	}
	int m = (i + j)/2;
	int res = min(qryf(idx*2, i, m, l, r),
			qryf(idx*2+1, m+1, j, l, r));
	tree[idx].f = men(tree[idx*2].f, tree[idx*2+1].f);
	return res;
}

int res[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%lld %lld", &p[a], &s[a]);
		X.pb(p[a]);
		in[a] = a;
	}
	sort(in, in+n, cmp);
	for(int a=0;a<m;a++){
		scanf("%lld%lld", mx+a, ms+a); 
		X.pb(mx[a]);
	}
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());

	for(int i=0;i<X.size();i++)
		ind[X[i]] = i;

	for(int a=0;a<m;a++)
		mx[a] = ind[mx[a]];

	for(int ii=n-1;ii>=0;ii--){
		int i = in[ii];
		int l = ind[p[i]];
		int r = up(s[i] + p[i]);
		if(l > r) continue;
		updf(1, 0, X.size()-1, l, r, i);
		debug("frog %d em l %d r %d\n", i, l, r);
	}
	for(int a=0;a<m;a++){
		int fg = qrym(1, 0, X.size()-1, mx[a]);	
		debug("mosca %d na pos %d frog %d\n", a, mx[a], fg);
		if(fg == -1)
			updm(1, 0, X.size()-1, mx[a], a);
		else{
			res[fg]++;
			ll sz = ms[a];
			int l, r;
			while(1){
				l = up(s[fg] + p[fg]);
				r = up(s[fg] + p[fg] + sz);
				int mo = qryf(1, 0, X.size()-1, l, r);
				if(mo == INT_MAX) break;
				res[fg]++;
				sz += ms[mo];
				updm(1, 0, X.size()-1, mx[mo], INT_MAX);
			}
			debug("updf fg %d l %d r %d\n", fg, l, r);
			updf(1, 0, X.size()-1, l, r, fg); 
			s[fg] += sz;
		}
	}
	for(int a=0;a<n;a++)
		printf("%d %lld\n", res[a], s[a]);
}
