#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000010;

int n, p;

int tree[MAXN*4];

void build(int idx, int i, int j){
	if(i == j){
		tree[idx] = 1;
		return ;
	}
	int m = (i+j)/2;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
	tree[idx] = tree[idx*2] + tree[idx*2+1];
}

void upd(int idx, int i, int j, int pos){
	if(i == j){
		assert(tree[idx] == 1);
		tree[idx] = 0;
		return ;
	}
	int m = (i+j)/2;
	if(tree[idx*2] > pos)
		upd(idx*2, i, m, pos);
	else
		upd(idx*2+1, m+1, j, pos - tree[idx*2]);
	tree[idx] = tree[idx*2] + tree[idx*2+1];
}

int qry(int idx, int i, int j, int l, int r){
	if(i > r || j < l) return 0;
	if(i >= l && j <= r){
		return tree[idx];
	}
	int m = (i+j)/2;
	return qry(idx*2, i, m, l, r) + qry(idx*2+1, m+1, j, l, r); 
}

void print(int idx, int i, int j){
	if(i == j){
		printf("%d\n", i);
		return ;
	}
	int m = (i+j)/2;
	if(tree[idx*2] > 0)
		print(idx*2, i, m);
	else
		print(idx*2+1,m+1, j);
}

int main (){
	scanf("%d %d", &n, &p);
	build(1, 1, n);
	int i = (p-1)%n; 
	while(tree[1] > 1){
		upd(1, 1, n, i);
		i += p-1;
		i = i%tree[1];
	}
	print(1, 1, n);
}
