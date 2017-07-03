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

const int MAXN = 312345;

int n, m, k;
int s[MAXN];

struct arv{
	int lz, val;
} tree[MAXN*4];

void build(int idx, int i, int j){
	tree[idx].lz = -1;
	tree[idx].val = 0;
	if(i == j)
		return;
	int m = (i+j)/2;
	build(idx*2, i, m);
	build(idx*2 + 1, m+1, j);
}

void upd(int idx, int i, int j, int l, int r, int val){
	if(i > r || j < l) return ;

	if(tree[idx].lz != -1){
		int aux = tree[idx].lz;
		tree[idx].lz = -1;
		if(i!= j){
			if(tree[idx*2].val == 0){
				tree[idx*2].val = aux;
				tree[idx*2].lz = aux;
			}
			if(tree[idx*2+1].val == 0){
				tree[idx*2+1].val = aux;
				tree[idx*2+1].lz = aux;
			}
		}
	}

	if(i >= l && j <= r){
		if(tree[idx].val == 0){
			tree[idx].val = val;
			tree[idx].lz = val;
		}
		return ;
	}

	int m = (i+j)/2;
	upd(idx*2, i, m, l, r, val);
	upd(idx*2+1, m+1, j, l, r, val);
}

int qry(int idx, int i, int j, int l){
	if(l < i || l > j)
		return 0;
	
	if(tree[idx].lz != -1){
		int aux = tree[idx].lz;
		tree[idx].lz = -1;
		if(i!= j){
			if(tree[idx*2].val == 0){
				tree[idx*2].val = aux;
				tree[idx*2].lz = aux;
			}
			if(tree[idx*2+1].val == 0){
				tree[idx*2+1].val = aux;
				tree[idx*2+1].lz = aux;
			}
		}
	}

	if(i == l && j == l)
		return tree[idx].val;
	int m = (i + j)/2;

	return qry(idx*2, i, m, l) + qry(idx*2+1, m+1, j, l);
}

int main (){
	scanf("%d %d", &n, &m);
	build(1, 1, n);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d %d", &i, &j, &k);
		if(i <= k-1)
			upd(1, 1, n, i, k-1, k);
		if(k + 1 <= j)
			upd(1, 1, n, k+1, j, k);
	}
	for(int a=1;a<=n;a++){
		printf("%d ", qry(1, 1, n, a));
	}
}
