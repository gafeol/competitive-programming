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

const int MAXN = 200005;

int n, m, k;
int deg;
char s[MAXN];

int bit[2*MAXN];

map<char, int> ind;

int tree[70][4*MAXN];

void bupd(int i){
	i += 2;
	while(i < MAXN){
		bit[i]++;
		i += (i&-i);
	}
}

int bqry(int i){
	int ans = 0;
	i += 2;
	while(i > 0){
		ans += bit[i];
		i -= (i&-i);
	}
	return ans;
}

void unlaze(int t, int idx, int i, int j){
	if(tree[t][idx] == -1){
		tree[t][idx] = 0;
		if(i != j){
			tree[t][idx*2] = -1;
			tree[t][idx*2+1] = -1;
		}
	}
}

void upd(int t, int idx, int i, int j, int l){
	if(i > l || j < l) return ;
	unlaze(t, idx, i, j);
	if(i == j){
		tree[t][idx] = 1;
		return ;
	}
	int m = (i + j)/2;
	upd(t, idx*2, i, m, l);
	upd(t, idx*2+1, m+1, j, l);
	tree[t][idx] = max(0, tree[t][idx*2]) + max(0, tree[t][idx*2+1]);
}

void zera(int t, int idx, int i, int j, int l, int r){
	if(i > r || j < l) return ;
	unlaze(t, idx, i, j);
	if(tree[t][idx] == 0) return ;
	if(i == j){
		tree[t][idx] = -1;
		bupd(i);
		debug("bupd %d\n", i);
		return ;
	}
	int m = (i + j)/2;
	zera(t, idx*2, i, m, l, r);
	zera(t, idx*2+1, m+1, j, l, r);
	tree[t][idx] = max(0, tree[t][idx*2]) + max(0, tree[t][idx*2+1]);
}

int id(char c){
	if(ind.find(c) == ind.end())
		ind[c] = deg++;
	return ind[c];
}

int qry(int t, int idx, int i, int j, int l){
	if(i > l || j < l) return 0;
	unlaze(t, idx, i, j);
	if(i == j)
		return tree[t][idx];
	int m = (i + j)/2;
	return max(qry(t, idx*2, i, m, l), qry(t, idx*2+1, m+1, j, l));
}

inline int find(int x){
	int i = x;
	int j = 2*n+1;
	while(i < j){
		int m = (i + j)/2;
		if(x + bqry(m) > m)
			i = m +1;
		else
			j = m;
	}
	return i;
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf(" %c", s+a);
		upd(id(s[a]), 1, 0, n-1, a); 
	}
	for(int a=0;a<m;a++){
		char c;
		int l, r;
		scanf("%d %d %c", &l, &r, &c);
		l--;
		r--;
		l = find(l);
		r = find(r);
		debug("l %d r %d\n", l, r);
		zera(id(c), 1, 0, n-1, l, r);
	}
	for(int a=0;a<n;a++){
		if(qry(id(s[a]), 1, 0, n-1, a))
			printf("%c", s[a]);
	}
	puts("");
}

