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

int n, m;
char s[MAXN];

struct arv{
	int lz, sum;
} tree[MAXN*4][30];

void upd(int idx, int ch, int i, int j, int l, int r, int val){
//	debug("upd(%d %d %d %d %d %d %d)\n", idx, ch, i, j, l, r, val);
	if(i > r || j < l) return ;
	if(tree[idx][ch].lz != 0){
		int aux = tree[idx][ch].lz;
		tree[idx][ch].lz = 0;
		if(i != j){
			int m = (i+j)>>1;
			tree[idx*2][ch].lz = aux;
			tree[idx*2+1][ch].lz = aux;
			if(aux == 1){
				tree[idx*2][ch].sum = m - i + 1;
				tree[idx*2+1][ch].sum = j - m;
			}
			else{
				tree[idx*2][ch].sum = 0;
				tree[idx*2+1][ch].sum = 0;
			}
		}
	}
	if(i >= l && j <= r){
		tree[idx][ch].sum = (j - i + 1)*(val == 1);
		tree[idx][ch].lz = val; 
		return ;
	}

	int m = (i+j)>>1;
	upd(idx*2, ch, i, m, l, r, val);
	upd(idx*2+1, ch, m+1, j, l, r, val);
	tree[idx][ch].sum = tree[idx*2][ch].sum + tree[idx*2+1][ch].sum;
}

int qry(int idx, int ch, int i, int j, int l, int r){
	if(i > r || j < l) return 0;
	if(tree[idx][ch].lz != 0){
		int aux = tree[idx][ch].lz;
		tree[idx][ch].lz = 0;
		if(i != j){
			int m = (i+j)>>1;
			tree[idx*2][ch].lz = aux;
			tree[idx*2+1][ch].lz = aux;
			if(aux == 1){
				tree[idx*2][ch].sum = m - i + 1;
				tree[idx*2+1][ch].sum = j - m;
			}
			else{
				tree[idx*2][ch].sum = 0;
				tree[idx*2+1][ch].sum = 0;
			}
		}
	}
	if(i >= l && j <= r){
		return tree[idx][ch].sum;
	}

	int m = (i+j)>>1;
	return qry(idx*2, ch, i, m, l, r) +	qry(idx*2+1, ch, m+1, j, l, r);
}

inline int f(char c){
	return (int)(c - 'a');
}

void print(){
	for(int a=0;a<n;a++){
		for(int c=0;c<26;c++){
			if(qry(1, c, 0, n-1, a, a))
				printf("'%c'", 'a'+c);
		}
	}
	printf("\n");
}

int main (){
	scanf("%d%d", &n, &m);
	scanf(" %s", s);
	int tam = strlen(s);
	for(int a=0;a<tam;a++){
		upd(1, f(s[a]), 0, tam-1, a, a, 1);
	}
	int ii, jj;
	for(int a=0;a<m;a++){
		int i, j, k;
		scanf("%d %d %d", &i, &j, &k);
		i--; j--;
		ii = i; jj = j;
		for(int c=0;c<26;c++){
			int val = qry(1, c, 0, tam-1, i, j); 			
			if(val){
				//debug("achei %d caras '%c' entre %d - %d\n", val, (char)(c+'a'), i, j);
				upd(1, c, 0, tam-1, i, j, -1);
				if(k)
					upd(1, c, 0, tam-1, ii, ii+val-1, 1);
				else
					upd(1, c, 0, tam-1, jj-val+1, jj, 1);
			}
			ii += val;
			jj -= val;
		}
	//	print();
	}
	for(int a=0;a<tam;a++){
		for(int c=0;c<26;c++){
			if(qry(1, c, 0, tam-1, a, a))
				printf("%c", 'a'+c);
		}
	}
	printf("\n");
}
