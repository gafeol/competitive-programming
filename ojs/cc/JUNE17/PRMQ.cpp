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

const int MAXN = 112345;

int n, m, k;
int s[MAXN];

vector <int> tree[MAXN*4];
int mrk[MAXN];
vector<int> pri;

void join(int t, int a, int b){
	int i, j;
	i = j = 0;
	while(i < tree[a].size() && j < tree[b].size()){
		if(tree[a][i] < tree[b][j]){
			tree[t].pb(tree[a][i]);
			i++;
		}
		else{
			tree[t].pb(tree[b][j]);
			j++;
		}
	}
	while(i < tree[a].size()){
		tree[t].pb(tree[a][i]);
		i++;
	}
	while(j < tree[b].size()){
		tree[t].pb(tree[b][j]);
		j++;
	}
}


void build(int idx, int i, int j){
	if(i == j){
		for(int p: pri){
			while(s[i]%p == 0){
				s[i] /= p;
				tree[idx].pb(p);
			}
		}
		if(s[i] != 1)
			tree[idx].pb(s[i]);
		return ;
	}
	int m = (i + j)/2;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
	join(idx, idx*2, idx*2+1);
}

int qry(int idx, int i, int j, int l, int r, int x, int y){
	if(i > r || j < l)
		return 0;
	if(i >= l && j <= r){
		int le = lower_bound(tree[idx].begin(), tree[idx].end(), x) - tree[idx].begin();			
		int ri = upper_bound(tree[idx].begin(), tree[idx].end(), y) - tree[idx].begin() - 1;
		return ri - le + 1;
	}
	int m = (i + j)/2;
	return qry(idx*2, i, m, l, r, x, y) + qry(idx*2+1, m+1, j, l, r, x, y);
}


int main (){
	for(int p=2;p<2000;p++){
		if(mrk[p]) continue;
		pri.pb(p);
		for(ll i = p; p*i <= 2000; i++)
			mrk[i*p] = 1;	
	}
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	build(1, 0, n-1);
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		int l, r, x, y;
		scanf("%d %d %d %d", &l, &r, &x, &y);
		l--;
		r--;
		printf("%d\n", qry(1, 0, n-1, l, r, x, y));
	}
}
