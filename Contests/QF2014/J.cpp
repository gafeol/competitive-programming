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
int L;
char s[MAXN];

struct arv{
	int u, q;
} tree[4*MAXN][30];

void cmp(int i){
	int j = i*2, k = i*2+1;
	for(int a=0;a<=26;a++){
		tree[i][a].q = tree[j][a].q + tree[k][a].q;
		tree[i][a].u = max(tree[j][a].u, tree[k][a].u);
	}
}

void build(int idx, int i, int j){
	if(i == j){
		for(int a=0;a<=26;a++){
			tree[idx][a].q = (s[i]-'a' == a);
			tree[idx][a].u = (s[i]-'a' == a ? i : -1);
		}
		return;
	}
	int m = (i + j)/2;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
	cmp(idx);
}

void upd(int idx, int i, int j, int l, int c, int x){
	if(i > l || j < l) return ;
	if(i == j && i == l){
		tree[idx][c].q += x;
		tree[idx][c].u = (x == 1 ? i : -1);
		return ;
	}
	int m = (i + j)/2;
	upd(idx*2, i, m, l, c, x);
	upd(idx*2+1, m+1, j, l, c, x);
	cmp(idx);
}

int qry(int idx, int i, int j, int l, int r, int c){
	if(i > r || j < l || l > r) return 0;
	if(i >= l && j <= r){
		L = max(L, tree[idx][c].u + 1);
		return tree[idx][c].q;
	}
	int m = (i + j)/2;
	return qry(idx*2, i, m, l, r, c) + qry(idx*2+1, m+1, j, l, r, c);
}

int main (){
	scanf(" %s", s);
	int tam = strlen(s)-1;
	build(1, 0, tam); 
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int t;
		scanf("%d", &t);
		if(t == 1){
			int i, j, p;
			scanf("%d %d %d", &i, &j, &p);
			i--;j--;
			L = i;
			for(int c = 25;c>=0;c--){
				p -= qry(1, 0, tam, L, j, c); 
				if(p <= 0){
					printf("%c", c+'a');
					break;
				}

			}
			if(p > 0){
				printf("-");
			}
			puts("");
		}
		else{
			char c;
			int i;
			scanf("%d %c", &i, &c);
			i--;
			upd(1, 0, tam, i, s[i]-'a', -1);
			s[i] = c;
			upd(1, 0, tam, i, c-'a', 1); 
		}
	}
}
