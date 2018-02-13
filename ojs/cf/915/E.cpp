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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 312345*4;

int n, m, k;
int s[MAXN];
int l[MAXN], r[MAXN], t[MAXN];

vector<int> pos;

struct arv{
	int x, t, lz;
} tree[MAXN*4];

void add(int u, int i, int j){
	int L = u*2;
	int R = u*2+1;
	if(i != j){
		tree[u].x = tree[L].x + tree[R].x;
		tree[u].t = tree[L].t + tree[R].t;
	}
}

void unlaze(int idx, int i, int j){
	int L = idx*2, R = idx*2+1;
	if(tree[idx].lz != 0){
		int t = tree[idx].lz;
		tree[idx].lz = 0;
		if(i != j){
			tree[L].lz = t;
			tree[L].x = (t == 1 ? tree[L].t : 0);
			tree[R].lz = t;
			tree[R].x = (t == 1 ? tree[R].t : 0);
		}
	}
}

void build(int idx, int i, int j){
	if(i == j){
		tree[idx].t = s[i];
		tree[idx].x = s[i];
		tree[idx].lz = 0;
		return;
	}
	int m = (i + j)/2;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
	add(idx, i, j);
}

void upd(int idx, int i, int j, int l, int r, int t){
	if(l > j || r < i) return ;
	unlaze(idx, i, j);
	if(i >= l && j <= r){
		tree[idx].lz = t; 
		tree[idx].x = (t == 1 ? tree[idx].t : 0);
		return ;
	}
	int m = (i + j)/2;
	upd(idx*2, i, m, l, r, t);
	upd(idx*2+1, m+1, j, l, r, t);
	add(idx, i, j);
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
		scanf("%d%d%d", l+a, r+a, t+a);
		r[a]++;
		pos.pb(l[a]);
		pos.pb(r[a]);
		t[a] = (t[a] == 1 ? 2:1);
	}
	pos.pb(1);
	pos.pb(n+1);
	sort(pos.begin(), pos.end());
	pos.erase(unique(pos.begin(), pos.end()), pos.end());
	for(int a=0;a<pos.size()-1;a++){
		s[a] = pos[a+1] - pos[a]; 
		debug("s[%d] %d\n", a, s[a]);
	}
	build(1, 0, pos.size()-2);
	for(int a=0;a<m;a++){
		int i = l[a];
		int j = r[a];
		int L = lower_bound(pos.begin(), pos.end(), i) - pos.begin();
		int R = lower_bound(pos.begin(), pos.end(), j) - pos.begin() - 1;
		debug("upd l %d r %d\n", L, R);
		upd(1, 0, pos.size()-2, L, R, t[a]); 
		printf("%d\n", tree[1].x);
	}
}

