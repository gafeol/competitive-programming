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

struct qry{
	int i, j;
	char c;
} q[MAXN];

struct arv{
	int x, lz;
} tree[8*MAXN][2];

vector<int> vi;
map<int, int> ind;

int qry(int idx, int t, int i, int j, int l){
	if(l > j || l < i) return 0;
	if(tree[idx][t].lz){
		int aux = tree[idx][t].lz;
		tree[idx][t].x = max(tree[idx][t].x, aux);
		tree[idx][t].lz = 0;
		if(i != j){
			tree[idx*2][t].lz = max(tree[idx*2][t].lz, aux);
			tree[idx*2+1][t].lz = max(tree[idx*2+1][t].lz, aux);
		}
	}
	if(i == j && i == l)
		return tree[idx][t].x;

	int m = (i+j)>>1;
	return qry(idx*2, t, i, m, l) +	qry(idx*2+1, t, m+1, j, l);
}

void upd(int idx, int t, int i, int j, int l, int r, int val){
	if(i > r || j < l) return ;
	if(tree[idx][t].lz){
		int aux = tree[idx][t].lz;
		tree[idx][t].x = max(tree[idx][t].x, aux);
		tree[idx][t].lz = 0;
		if(i != j){
			tree[idx*2][t].lz = max(tree[idx*2][t].lz, aux);
			tree[idx*2+1][t].lz = max(tree[idx*2+1][t].lz, aux);
		}
	}
	if(i >= l && j <= r){
		tree[idx][t].lz = max(tree[idx][t].lz, val); 
		return ;
	}
	int m = (i+j)>>1;
	upd(idx*2, t, i, m, l, r, val);
	upd(idx*2+1, t, m+1, j, l, r, val);
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
		scanf("%d%d %c", &q[a].j, &q[a].i, &q[a].c);
		vi.pb(q[a].i);
		vi.pb(q[a].j);
	}
	vi.pb(0);
	sort(vi.begin(), vi.end());
	vi.erase(unique(vi.begin(), vi.end()), vi.end());
	int tam = vi.size();

	for(int a=0;a<vi.size();a++){
		ind[vi[a]] = a;	
	}
	for(int a=0;a<m;a++){
		int t = (q[a].c == 'U');
		int x = qry(1, t, 0, tam-1, ind[(t ? q[a].j:q[a].i)]);
//		printf("qry t %d no ponto ind[%d] %d) dando %d\n", t, (t ? q[a].j:q[a].i), ind[(t ? q[a].j:q[a].i)], x);
		if(t == 0)
			printf("%d\n", q[a].j - x);	
		else
			printf("%d\n", q[a].i - x);
//		printf("upd t %d no ponto (ind[%d] %d - ind[%d]) %d com o val %d\n", t^1, x, ind[x], (t ? q[a].i:q[a].j), ind[(t ? q[a].i:q[a].j)], (t ? q[a].j:q[a].i));
		upd(1, t^1, 0, tam-1, ind[x], ind[(t ? q[a].i:q[a].j)], (t ? q[a].j:q[a].i));
		upd(1, t, 0, tam-1, ind[(t ? q[a].j:q[a].i)], ind[(t ? q[a].j:q[a].i)], (t ? q[a].i:q[a].j));
		debug("upd t %d no ponto (ind[%d] %d - ind[%d] %d) com o val %d\n", t, (t ? q[a].j:q[a].i), ind[(t ? q[a].j:q[a].i)],(t ? q[a].j:q[a].i), ind[(t ? q[a].j:q[a].i)], (t ? q[a].i:q[a].j));
	}
}
