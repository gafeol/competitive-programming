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

vector<int> tree[MAXN*4];

map<int, vector<int> > ind;

void build(int idx, int i, int j){
	if(i == j){
		tree[idx].pb(s[i]);
		return ;
	}
	int m = (i+j)/2;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j); 
	int l = 0;
	int r = 0;
	int t1 = tree[idx*2].size();
	int t2 = tree[idx*2+1].size();
	while(l < t1 && r < t2){
		if(tree[idx*2][l] < tree[idx*2+1][r])
			tree[idx].pb(tree[idx*2][l++]);
		else
			tree[idx].pb(tree[idx*2+1][r++]);
	}
	while(l < t1)
		tree[idx].pb(tree[idx*2][l++]);
	while(r < t2)
		tree[idx].pb(tree[idx*2+1][r++]);

	debug("\nno %d i %d j %d\n", idx, i, j);
	for(int x: tree[idx])
		debug("%d ", x);
	debug("\n");
}

int qry(int idx, int i, int j, int l, int r, int val){
	if(i > r || j < l) return 0;
	if(i >= l && j <= r){
		return (lower_bound(tree[idx].begin(), tree[idx].end(), val) - tree[idx].begin());
	}
	int m  = (i+j)/2;
	return qry(idx*2, i, m, l, r, val) + qry(idx*2+1, m+1, j, l, r, val);
}

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		int tam = ind[s[a]].size();
		ind[s[a]].pb(a);
		if(tam >= k)
			s[a] = ind[s[a]][tam-k]; 
		else
			s[a] = -1;
		debug("%d ", s[a]);
	}
	build(1, 0, n-1);
	scanf("%d", &m);
	int ult = 0;
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d",  &i, &j);
		i = (ult + i)%n;
		j = (ult + j)%n;
		if(i > j)
			swap(i, j);
		ult = qry(1, 0, n-1, i, j, i);
		printf("%d\n", ult);
	}
}

