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

ll M[2][2], ini[2][3], aux[2][2]; 


struct arv{
	ll sum, summ;
	ll lz[2][2];
	arv(ll s, ll ss, ll lzz[2][2]): sum(s), summ(ss) {
		for(int a=0;a<2;a++){
			for(int b=0;b<2;b++){
				lz[a][b] = lzz[a][b];
			}
		}
	}
	arv(){}
} tree[4*MAXN];


inline void quad(){
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			aux[a][b] = 0;
			for(int c=0;c<2;c++){
				aux[a][b] = mod(aux[a][b] + M[c][b]*M[a][c]);
			}
		}
	}
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			M[a][b] = aux[a][b];
			aux[a][b] = 0;
		}
	}
}

inline void mult(){
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			aux[a][b] = 0;
			for(int c=0;c<2;c++){
				aux[a][b] = mod(aux[a][b] + M[c][b]*ini[a][c]);
			}
		}
	}
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			M[a][b] = aux[a][b];
			aux[a][b] = 0;
		}
	}
}

inline void zera(){
	M[0][0] = M[0][1] = M[1][0] = 1;
	M[1][1] = 0;
	ini[0][0] = ini[0][1] = ini[1][0] = 1;
	ini[1][1] = 0;
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			aux[a][b] = 0;
		}
	}
}

inline void expo(ll i){
	if(i == 0){
		M[1][1] = M[0][0] = 1;
		M[0][1] = M[1][0] = 0;
		return ;
	}
	if(i == 1ll){
		zera();
		return;
	}
	expo(i/2ll);
	quad();
	if(i&1ll)
		mult();
}


inline ll fib(ll i){
	i--;
	if(i == -1)
		return 0;
	if(i == 0 || i == 1)
		return 1;
	zera();
	expo(i-1);
	//printf("\nM:\n");
	//	printm();
	//	printf("fib %lld dando %lld\n", i+1, M[0][0] + M[0][1]);
	return mod(M[0][0] + M[0][1]);
}

inline void id(ll a[2][2]){
	a[0][0] = a[1][1] = 1;
	a[0][1] = a[1][0] = 0;
}


inline void build(int idx, int i, int j){
	if(i == j){
		tree[idx].sum = fib(s[i]);
		tree[idx].summ = fib(s[i]-1);
		id(tree[idx].lz);
		return ;
	}
	int m = (i+j)/2;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
	id(tree[idx].lz);
	tree[idx] = arv(mod(tree[idx*2].sum + tree[idx*2+1].sum), mod(tree[idx*2].summ + tree[idx*2+1].summ), tree[idx].lz); 
}


inline void mulm(ll u[2][2], ll v[2][2]){
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			aux[a][b] = 0;
			for(int c=0;c<2;c++){
				aux[a][b] = mod(aux[a][b] + u[c][b]*v[a][c]);
			}
		}
	}
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			u[a][b] = aux[a][b];
			aux[a][b] = 0;
		}
	}
}

bool iden(ll a[2][2]){
	return (a[0][0] == 1 && a[0][1] == 0 && a[1][0] == 0 && a[1][1] == 1);
}

inline void unlaze(int idx, int i, int j){
	if(iden(tree[idx].lz)) return;
	if(i != j){
		int nxt = idx*2;
		ll ns = mod(tree[nxt].sum*tree[idx].lz[0][0] + tree[nxt].summ*tree[idx].lz[0][1]);
		ll nss = mod(tree[nxt].sum*tree[idx].lz[1][0] + tree[nxt].summ*tree[idx].lz[1][1]);
		mulm(tree[nxt].lz, tree[idx].lz);
		tree[nxt].sum = ns;
		tree[nxt].summ = nss;

		nxt = idx*2+1;
		ns = mod(tree[nxt].sum*tree[idx].lz[0][0] + tree[nxt].summ*tree[idx].lz[0][1]);
		nss = mod(tree[nxt].sum*tree[idx].lz[1][0] + tree[nxt].summ*tree[idx].lz[1][1]);
		mulm(tree[nxt].lz, tree[idx].lz);
		tree[nxt].sum = ns;
		tree[nxt].summ = nss;

	}
	id(tree[idx].lz);
}

inline void upd(int idx, int i, int j, int l, int r, ll x[2][2]){
	if(i > r || j < l)
		return ;
	unlaze(idx, i, j);
	if(i >= l && j <= r){
		mulm(tree[idx].lz, x);
		ll ns=0, nss=0;
		ns = mod((tree[idx].sum*x[0][0]) + (tree[idx].summ*x[0][1]));
		nss = mod((tree[idx].sum*x[1][0]) + (tree[idx].summ*x[1][1]));
		tree[idx].sum = ns;
		tree[idx].summ = nss;
		return;
	}
	int m = (i+j)/2;
	upd(idx*2, i, m, l, r, x);
	upd(idx*2+1, m+1, j, l, r, x);
	tree[idx] = arv(mod(tree[idx*2].sum + tree[idx*2+1].sum), mod(tree[idx*2].summ + tree[idx*2+1].summ), tree[idx].lz); 
}

inline ll qry(int idx, int i, int j, int l, int r){
	if(i > r || j < l)
		return 0ll;
	unlaze(idx, i, j);
	if(i >= l && j <= r){
		return tree[idx].sum;
	}
	int m = (i+j)/2;
	return mod(qry(idx*2, i, m, l, r) +
			qry(idx*2+1, m+1, j, l, r));
}

void printt(int idx, int i, int j){
	unlaze(idx, i, j);
	printf("%d %d-%d:\n", idx, i, j);
	printf("	sums %lld %lld\n ", tree[idx].sum, tree[idx].summ);
	printf("	%lld %lld\n	%lld %lld\n", tree[idx].lz[0][0], tree[idx].lz[0][1], tree[idx].lz[1][0], tree[idx].lz[1][1]); 
	if(i == j)
		return;
	int m = (i + j)/2;
	printt(idx*2, i, m);
	printt(idx*2+1, m+1, j);
}



int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%lld", &s[a]);
		f[a] = fib(s[a]);
		fm[a] = fib(s[a]-1);
	}
	build(1, 0, n-1);
	//	printt(1, 0, n-1);
	for(int a=0;a<m;a++){
		int t, i, j;
		scanf("%d%d%d", &t, &i, &j); 
		i--;
		j--;
		if(t == 1){
			ll x;
			scanf("%lld", &x);
			zera();
			expo(x);
			upd(1, 0, n-1, i, j, M);
			//	printf("\nUPD +%lld de %d a %d\n", x, i, j);
			//	printt(1, 0, n-1);
		}
		else{
			printf("%d\n", (int) qry(1, 0, n-1, i, j));
		}
	}
}
