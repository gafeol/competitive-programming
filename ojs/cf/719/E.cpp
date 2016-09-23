

#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
ll s[MAXN];
ll f[MAXN], fm[MAXN];

int M[2][2], ini[2][3]; 


struct arv{
	ll sum, summ, lz;
	
} tree[4*MAXN];

void zera(){
	M[0][0] = M[0][1] = M[1][0] = 1;
	M[1][1] = 0;
	ini[0][0] = ini[0][1] = ini[1][0] = 1;
	ini[1][1] = 0;
}

void build(int idx, int i, int j){
	if(i == j){
		tree[idx].sum = 0;
		tree[idx].summ = 0;
		tree[idx].lz = 0;
		return ;
	}
	int m = (i+j)/2;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
}

void quad(){
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			ini[a][b] = 0;
			for(int c=0;c<2;c++){
				ini[a][b] += M[c][b]*M[b][c];
			}
		}
	}
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			M[a][b] = ini[a][b];
		}
	}
}

void mult(){
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			ini[a][b] = 0;
			for(int c=0;c<2;c++){
				ini[a][b] += M[c][b]*ini[b][c];
			}
		}
	}
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			M[a][b] = ini[a][b];
		}
	}
}

void expo(ll i){
	if(i == 0ll){
		zera();
		return;
	}
	expo(i/2ll);
	quad();
	if(i&1ll)
		mult();
}

ll fib(ll i){
	expo(i);
	return M[0][0] + M[0][1];
}

void upd(int idx, int i, int j, int l, int r, ll x){
	if(i > r || j < l)
		return ;
	if(tree[idx].lz != 0){
		ll x = tree[idx].lz;
		tree[idx].lz = 0;
			if(i != j){
			int m = (i+j)/2;
			expo(x);
			ll ns=0, nss=0;
			ns = mod(mod(tree[idx*2].sum*M[0][0]) + mod(tree[idx*2].summ*M[0][1]));
			nss = mod(mod(tree[idx*2].sum*M[1][0]) + mod(tree[idx*2].summ*M[1][1]));
			tree[idx*2].sum = ns;
			tree[idx*2].summ = nss;
			tree[idx*2].lz += x;

			ns = mod(mod(tree[idx*2+1].sum*M[0][0]) + mod(tree[idx*2+1].summ*M[0][1]));
			nss = tree[idx*2+1].sum*M[1][0] + tree[idx*2+1].summ*M[1][1];
			tree[idx*2+1].sum = ns;
			tree[idx*2+1].summ = nss;
			tree[idx*2+1].lz += x;
		}

	}
	if(i >= l && j <= r){
		tree[idx].lz += x;
		expo(x);
		ll ns=0, nss=0;
		ns = mod(mod(tree[idx].sum*M[0][0]) + mod(tree[idx].summ*M[0][1]));
		nss = mod(mod(tree[idx].sum*M[1][0]) + mod(tree[idx].summ*M[1][1]));
		tree[idx].sum = ns;
		tree[idx].summ = nss;
		return;
	}
	int m = (i+j)/2;
	upd(idx*2, i, m, l, r, x);
	upd(idx*2+1, m+1, j, l, r, x);
}

ll qry(int idx, int i, int j, int l, int r){
	if(i > r || j < l)
		return 0ll;
	if(tree[idx].lz != 0){
		ll x = tree[idx].lz;
		tree[idx].lz = 0;
		if(i != j){
			int m = (i+j)/2;
			expo(x);
			ll ns=0, nss=0;
			ns = mod(mod(tree[idx*2].sum*M[0][0]) + mod(tree[idx*2].summ*M[0][1]));
			nss = mod(mod(tree[idx*2].sum*M[1][0]) + mod(tree[idx*2].summ*M[1][1]));
			tree[idx*2].sum = ns;
			tree[idx*2].summ = nss;
			tree[idx*2].lz += x;

			ns = mod(mod(tree[idx*2+1].sum*M[0][0]) + mod(tree[idx*2+1].summ*M[0][1]));
			nss = tree[idx*2+1].sum*M[1][0] + tree[idx*2+1].summ*M[1][1];
			tree[idx*2+1].sum = ns;
			tree[idx*2+1].summ = nss;
			tree[idx*2+1].lz += x;
		}
	}
	if(i >= l && j <= r){
		return tree[idx].sum;
	}
	int m = (i+j)/2;
	return mod(qry(idx*2, i, m, l, r) + 
		qry(idx*2+1, m+1, j, l, r));
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%lld", &s[a]);
		f[a] = fib(s[a]);
		fm[a] = fib(s[a]-1);
	}
	for(int a=0;a<m;a++){
		int t, i, j;
		scanf("%d%d%d", &t, &i, &j); 
		if(t == 1){
			ll x;
			scanf("%lld", &x);
			upd(1, 0, n-1, i, j, x);
		}
		else{
			printf("%lld\n", qry(1, 0, n-1, i, j));
		}
	}
}
