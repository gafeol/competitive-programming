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

const int MAXN = 512345;

int n, m, k;

int L, R, t;

struct arv{
	ll tot, l, r, sz;

	arv(){}
	arv(ll t, ll le, ll ri, ll s) : tot(t), l(le), r(ri), sz(s) {}
} tree[2][MAXN*4];

arv join(arv a, arv b){
	ll l = a.l;
	if(a.l == a.sz)
		l = a.sz + b.l;
	ll r = b.r;
	if(b.r == b.sz)
		r = b.sz + a.r;

	return arv(a.tot + b.tot + a.r*b.l, l, r, a.sz + b.sz);
}

void upd(int t, int idx, int i, int j, int l, ll v){
	if(l > j || l < i) return ;
	if(i == j){
		tree[t][idx].l = tree[t][idx].r = tree[t][idx].tot = v;
		tree[t][idx].sz = 1;
		return ;	
	}

	int m = (i + j)/2;

	upd(t, idx*2, i, m, l, v);
	upd(t, idx*2+1, m+1, j, l, v);
	tree[t][idx] = join(tree[t][idx*2], tree[t][idx*2+1]);
}

arv qry(int t, int idx, int i, int j, int l, int r){
	if(l > j || r < i) return arv(0, 0, 0, 0);
	if(i >= l && j <= r)
		return tree[t][idx];
	
	int m = (i + j)/2;

	return join(qry(t, idx*2, i, m, l, r),
				qry(t, idx*2+1, m+1, j, l, r));
}

void build(int t, int idx, int i, int j){
	if(i == j){
		tree[t][idx].tot = tree[t][idx].sz = tree[t][idx].l = tree[t][idx].r = 1;
		return ;
	}

	int m = (i + j)/2;
	build(t, idx*2, i, m);
	build(t, idx*2+1, m+1, j);
	tree[t][idx] = join(tree[t][idx*2], tree[t][idx*2+1]);
}

int main (){
	scanf("%d %d %d %d", &n, &m, &L, &R);
	build(0, 1, 0, n-1);
	build(1, 1, 0, n-1);
	for(int a=0;a<m;a++){
		ll x, y;
		scanf("%d %lld %lld", &t, &x, &y);
		x--;
		if(t == 1){
			upd(1, 1, 0, n-1, x, (int)(y <= R));
			upd(0, 1, 0, n-1, x, (int)(y <= L-1));
		}
		else{
			y--;
			printf("%lld\n", qry(1, 1, 0, n-1, x, y).tot - qry(0, 1, 0, n-1, x, y).tot);
		}
	}
}

