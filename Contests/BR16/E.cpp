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


const int N = 1e5 + 13;
const int Q = 1e5 + 13;
const int LQ = 14;

typedef struct node{
	int f, l, r;
	struct node * left, * right;
} node;

int n, q;
node _M[3*Q*LQ], *ns = _M;
node * T[N];
int x[N], seen[N], ss;

inline int idx(int x) { return lower_bound(seen, seen+ss, x) - seen; }

node * copyNode(node * s){
	node * ans = ns++;
	if(s == NULL) return ans;
	ans->f = s->f; ans->l = s->l; ans->r = s->r;
	ans->left = s->left; ans->right = s->right;
	return ans;
}

node * build(int l, int r){
	if(l == r) return NULL;
	int m = (l + r)/2;
	node * ans = ns++;
	ans->l = l; ans->r = r;
	if(l + 1 != r) {
		ans->left = build(l, m);
		ans->right = build(m, r);
	}
	return ans;
}

node * upd(node * t, int i, int v){
	node * ans = copyNode(t);
	if(t == NULL || ans->r - ans->l == 1) ans->f += v;
	else {
		int m = (ans->l + ans->r)/2;
		if(i < m) ans->left  = upd(ans->left, i, v);
		else      ans->right = upd(ans->right, i, v);
		ans->f = 0;
		if(ans->left ) ans->f += ans->left->f;
		if(ans->right) ans->f += ans->right->f;
	}
	return ans;
}

void swap(int i){
	T[i] = upd(T[i], x[i], -1);
	swap(x[i], x[i+1]);
	T[i] = upd(T[i], x[i],  1);
}

int query(node * ti, node * tj, int k){
	if(ti->l + 1 == ti->r) return seen[ti->l];
	if(k <= tj->left->f - ti->left->f) return query(ti->left, tj->left, k);
	k -= tj->left->f - ti->left->f;
	return query(ti->right, tj->right, k);
}

int main (){
	scanf(" %d%d", &n, &q);
	for(int i=1;i<=n;i++){
		scanf(" %d", x+i);
		seen[ss++] = x[i];
	}
	sort(seen, seen+ss);
	ss = unique(seen, seen+ss) - seen;
	for(int i=1;i<=n;i++) x[i] = idx(x[i]);

	T[0] = build(0, ss);
	for(int i=1;i<=n;i++) T[i] = upd(T[i-1], x[i], 1);

	while(q--){
		char c; scanf(" %c", &c);
		if(c == 'Q') {
			int i, j, k; scanf(" %d%d%d", &i, &j, &k);
			printf("%d\n", query(T[--i], T[j], k));
		} else {
			int i; scanf(" %d", &i);
			swap(i);
		}
	}
}

