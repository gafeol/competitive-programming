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

struct arv{
	int bst, l, r, t;
	arv(int b, int ll, int rr, int tt){
		bst = b;
		l = ll;
		r = rr;
		t = tt;
	}
	arv(){};
}tree[MAXN*4];

void printt(arv a){
	debug(" arv bst %d l %d r %d t %d\n", a.bst, a.l, a.r, a.t);
}

arv join(arv a, arv b){
	if(a.t == INT_MIN) return b;
	if(b.t == INT_MIN) return a;
	debug("join:\n");
	printt(a);
	printt(b);
	arv res;
	res.t = a.t + b.t;
	res.l = max(a.l, a.t + b.l);
	res.r = max(b.r, a.r + b.t);
	res.bst = max(max(res.l, res.r), max(max(a.bst, b.bst), max(a.r+b.l, res.t)));
	printt(res);
	return res;
}

void build(int idx, int i, int j){
	if(i == j){
		tree[idx].t = tree[idx].l = tree[idx].r = tree[idx].bst = s[i];
		return ;	
	}
	int m = (i+j)>>1;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
	tree[idx] = join(tree[idx*2], tree[idx*2+1]);
}


arv qry(int idx, int i, int j, int l, int r){
	if(l > j || r < i) return arv(INT_MIN, INT_MIN, INT_MIN, INT_MIN);
	if(i >= l && j <= r)
		return tree[idx];
	int m = (i+j)>>1;
	return join(qry(idx*2, i, m, l, r), 
				qry(idx*2+1, m+1, j, l, r));
}

void upd(int idx, int i, int j, int l, int val){
	if(l > j || l < i) return;
	if(i == j){
		tree[idx] = arv(val, val, val, val);
		return;
	}
	int m = (i + j)>>1;
	upd(idx*2, i, m, l, val);
	upd(idx*2+1, m+1, j, l, val);
	tree[idx] = join(tree[idx*2], tree[idx*2+1]);
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
	}
	build(1, 1, n);
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		int t, x, y;
		scanf("%d %d %d", &t, &x, &y);
		if(t)
			printf("%d\n", qry(1, 1, n, x, y).bst);
		else
			upd(1, 1, n, x, y);
	}
}
