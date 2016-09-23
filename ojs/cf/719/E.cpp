


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
	ll sum, summ, lz;
	arv(int s, int ss, int ll): sum(s), summ(ss), lz(ll) {}
	arv(){}
	arv operator+ (arv o) const{
		return arv(sum + o.sum, summ + o.summ, lz); 
	}
	
} tree[4*MAXN];

void printm(){
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			printf("%lld ", M[a][b]);
		}
		printf("\n");
	}
}

void quad(){
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			aux[a][b] = 0;
			for(int c=0;c<2;c++){
				aux[a][b] += M[c][b]*M[a][c];
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

void mult(){
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			aux[a][b] = 0;
			for(int c=0;c<2;c++){
				aux[a][b] += M[c][b]*ini[a][c];
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

void zera(){
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

void expo(ll i){
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


ll fib(ll i){
	i--;
	if(i == -1)
		return 0;
	if(i == 0 || i == 1)
		return 1;
	zera();
	expo(i);
	printf("\nM:\n");
	printm();
	printf("fib %lld dando %lld\n", i+1, M[0][0] + M[0][1]);
	return M[0][0] + M[0][1];
}


void build(int idx, int i, int j){
	if(i == j){
		tree[idx].sum = fib(s[i]);
		tree[idx].summ = fib(s[i]-1);
		tree[idx].lz = 0;
		return ;
	}
	int m = (i+j)/2;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
	tree[idx] = tree[idx*2] + tree[idx*2+1]; 
}

void upd(int idx, int i, int j, int l, int r, ll x){
	if(i > r || j < l)
		return ;
	if(tree[idx].lz != 0){
		ll val = tree[idx].lz;
		tree[idx].lz = 0;
			if(i != j){
			int m = (i+j)/2;
			zera();
			expo(val);
			ll ns=0, nss=0;
			ns = mod(mod(tree[idx*2].sum*M[0][0]) + mod(tree[idx*2].summ*M[0][1]));
			nss = mod(mod(tree[idx*2].sum*M[1][0]) + mod(tree[idx*2].summ*M[1][1]));
			tree[idx*2].sum = ns;
			tree[idx*2].summ = nss;
			tree[idx*2].lz += val;

			ns = mod(mod(tree[idx*2+1].sum*M[0][0]) + mod(tree[idx*2+1].summ*M[0][1]));
			nss = tree[idx*2+1].sum*M[1][0] + tree[idx*2+1].summ*M[1][1];
			tree[idx*2+1].sum = ns;
			tree[idx*2+1].summ = nss;
			tree[idx*2+1].lz += val;
		}

	}
	if(i >= l && j <= r){
		tree[idx].lz += x;
		zera();
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
	tree[idx] = tree[idx*2] + tree[idx*2+1];
}

ll qry(int idx, int i, int j, int l, int r){
	if(i > r || j < l)
		return 0ll;
	if(tree[idx].lz != 0){
		ll val = tree[idx].lz;
		tree[idx].lz = 0;
		if(i != j){
			int m = (i+j)/2;
			zera();
			expo(val);
			ll ns=0, nss=0;
			ns = mod(mod(tree[idx*2].sum*M[0][0]) + mod(tree[idx*2].summ*M[0][1]));
			nss = mod(mod(tree[idx*2].sum*M[1][0]) + mod(tree[idx*2].summ*M[1][1]));
			tree[idx*2].sum = ns;
			tree[idx*2].summ = nss;
			tree[idx*2].lz += val;

			ns = mod(mod(tree[idx*2+1].sum*M[0][0]) + mod(tree[idx*2+1].summ*M[0][1]));
			nss = tree[idx*2+1].sum*M[1][0] + tree[idx*2+1].summ*M[1][1];
			tree[idx*2+1].sum = ns;
			tree[idx*2+1].summ = nss;
			tree[idx*2+1].lz += val;
		}
	}
	if(i >= l && j <= r){
		return tree[idx].sum;
	}
	int m = (i+j)/2;
	return mod(qry(idx*2, i, m, l, r) +
			qry(idx*2+1, m+1, j, l, r));
}

void printt(int idx, int i, int j){
	printf("%d %d-%d:\n", idx, i, j);
	printf("	%lld %lld %lld\n", tree[idx].sum, tree[idx].summ, tree[idx].lz);
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
	printt(1, 0, n-1);
	for(int a=0;a<m;a++){
		int t, i, j;
		scanf("%d%d%d", &t, &i, &j); 
		i--;
		j--;
		if(t == 1){
			ll x;
			scanf("%lld", &x);
			upd(1, 0, n-1, i, j, x);
			printf("\nUPD +%lld de %d a %d\n", x, i, j);
			printt(1, 0, n-1);
		}
		else{
			printf("%lld\n", qry(1, 0, n-1, i, j));
		}
	}
}
