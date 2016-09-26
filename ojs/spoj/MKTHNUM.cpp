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

const int MAXN = 112345, NNODE = 11234567;

int n, m;
int s[MAXN];

int tree[NNODE], r[MAXN], L[NNODE], R[NNODE];

int deg;
vector<int> se;

map<int, int> ind;

int build(int idx, int i, int j){
//	printf("%d %d-%d\n", idx, i, j);
	tree[idx] = 0;
	if(i == j)
		return idx;
	int m = (i+j)/2;
	L[idx] = build(deg++, i, m);
	R[idx] = build(deg++, m+1, j);
	return idx;
}

void cpy(int idx){
	L[deg] = L[idx];
	R[deg] = R[idx];
}

int upd(int idx, int i, int j, int l){
	if(i == j){
		tree[idx]++;
//		printf("\n%d - %d  tree[%d] %d\n", i, j, idx, tree[idx]);
		return idx;
	}
	int m = (i + j)/2;
	if(l <= m){
		cpy(L[idx]);
		L[idx] = upd(deg++, i, m, l);
	}
	else{
		cpy(R[idx]);
		R[idx] = upd(deg++, m+1, j, l);
	}
	tree[idx] = tree[L[idx]] + tree[R[idx]];
//	printf("%d - %d tree[%d]: ", i, j, idx);
//	printf("%d\n", tree[idx]);
//	printf("filhos de %d    %d  %d\n", idx, L[idx], R[idx]);
	return idx;
}

int qry(int idx, int idxx, int i, int j, int k){
//	printf("tamos em %d e %d %d - %d quero o %d-esimo\ntrees %d %d\n", idx, idxx, i, j, k, tree[idx], tree[idxx]);
	if(i == j)
		return ind[i];
	int m = (i+j)/2;
	int ans;
	if(tree[L[idxx]] - tree[L[idx]] >= k)
		ans = qry(L[idx], L[idxx], i, m, k); 
	else
		ans = qry(R[idx], R[idxx], m+1, j, k-tree[L[idxx]] + tree[L[idx]]);
	return ans;	
}

int main (){
	deg = 1;
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
		se.pb(s[a]);
	}
	sort(se.begin(), se.end());
	se.erase(unique(se.begin(), se.end()), se.end());
	for(int a=1;a<=n;a++){
		int nv = lower_bound(se.begin(), se.end(), s[a]) - se.begin() + 1;
		ind[nv] = s[a];
		s[a] = nv;
	}
	se.clear();
	r[0] = build(deg++, 1, n);
	for(int a=1;a<=n;a++){
		cpy(r[a-1]);
		r[a] = upd(deg++, 1, n, s[a]);
	}
	for(int a=0;a<m;a++){
		int i, j, k;
		scanf("%d%d%d", &i, &j, &k);
		printf("%d\n", qry(r[i-1], r[j], 1, n, k));	
	}
}
