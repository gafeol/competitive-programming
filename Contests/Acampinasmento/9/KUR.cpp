#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN = 500010;

int n, m;

vector<int> tree[MAXN*4];

int s[MAXN];


void join(int idx){
	int l = idx*2;
	int r = idx*2+1;
	int i = 0, j = 0;
	while(i < tree[l].size() || j < tree[r].size()){
		if(i == tree[l].size()){
			tree[idx].pb(tree[r][j]);
			j++;
		}
		else if(j == tree[r].size()){
			tree[idx].pb(tree[l][i]);
			i++;
		}
		else{
			if(tree[l][i] < tree[r][j]){
				tree[idx].pb(tree[l][i]);
				i++;
			}
			else{
				tree[idx].pb(tree[r][j]);
				j++;
			}
		}
	}
}

void build(int idx, int i, int j){
	if(i == j){
		tree[idx].pb(s[i]);
		return ;
	}
	int m = (i+j)/2;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
	join(idx);
}

vector<int> res;

vector<int> pos[MAXN];

void qry(int idx, int i, int j, int l, int r){
	if(i > r || j < l) return ;
	if(i >= l && j <= r){
		int sz = tree[idx].size();
		res.pb(tree[idx][sz/2]);
		return ;
	}
	int m = (i+j)/2;
	qry(idx*2, i, m, l, r);
	qry(idx*2+1, m+1, j, l, r);
}

inline int cnt(int i, int j, int x){
	return (upper_bound(pos[x].begin(), pos[x].end(), j) - lower_bound(pos[x].begin(), pos[x].end(), i));
}


inline int query(int i, int j){
	i--;j--;
	//qry(1, 0, n-1, i, j);
	int k = 21;
	while(k--){
		int a = rand()%(j-i+1) + i;
		if(cnt(i, j, s[a]) > (j-i+1)/2)
			return s[a];
	}
	return 0;
}

int main(){

	srand(time(NULL));
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		pos[s[a]].pb(a);
	}
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		printf("%d\n", query(i, j));
	}
}
