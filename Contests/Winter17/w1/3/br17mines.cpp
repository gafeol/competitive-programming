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
#define debug(args...)// fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
int L[MAXN], R[MAXN];

struct arv{
	int mn, mx;
} tree[MAXN*4];


struct bomb{
	ll x, r;
	int i;
} s[MAXN];

vector<ll> X;

void build(int idx, int i, int j){
	tree[idx].mn = INT_MAX;
	tree[idx].mx = INT_MIN;
	if(i == j) return ;
	int m = (i + j)/2;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
}

int qrymn(int idx, int i, int j, int l, int r){
	if(i > r || j < l || l > r) return INT_MAX;
	if(i >= l && j<= r)
		return tree[idx].mn;
	int m = (i + j)/2;
	return min(qrymn(idx*2, i, m, l, r),
				qrymn(idx*2+1, m+1, j, l, r));
}

void updmn(int idx, int i, int j, int l, int x){
	if(i > l || j < l) return;
	if(i >= l && j<= l){
		tree[idx].mn = min(tree[idx].mn, x);
		return ;
	}
	int m = (i + j)/2;
	updmn(idx*2, i, m, l, x);
	updmn(idx*2+1, m+1, j, l, x);
	tree[idx].mn = min(tree[idx*2+1].mn, tree[idx*2].mn);
}

int qrymx(int idx, int i, int j, int l, int r){
	if(i > r || j < l || l > r) return INT_MIN;
	if(i >= l && j<= r)
		return tree[idx].mx;
	int m = (i + j)/2;
	return max(qrymx(idx*2, i, m, l, r),
				qrymx(idx*2+1, m+1, j, l, r));
}

void updmx(int idx, int i, int j, int l, int x){
	if(i > l || j < l) return;
	if(i >= l && j<= l){
		tree[idx].mx = max(tree[idx].mx, x);
		return ;
	}
	int m = (i + j)/2;
	updmx(idx*2, i, m, l, x);
	updmx(idx*2+1, m+1, j, l, x);
	tree[idx].mx = max(tree[idx*2+1].mx, tree[idx*2].mx);
}

bool cmp(bomb a, bomb b){
	return a.r > b.r;
}

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		build(1, 0, n-1);
		X.clear();
		for(int a=0;a<n;a++){
			scanf("%lld%lld", &s[a].x, &s[a].r);
			s[a].i = a;
			X.pb(s[a].x);
		}
		for(int a=0;a<n;a++){
			int l = lower_bound(X.begin(), X.end(), s[a].x - s[a].r) - X.begin();
			debug("a %d l %d\n", a, l);
			L[a] = min(a, qrymn(1, 0, n-1, l, a-1));
			debug("L[%d] %d\n", a, L[a]);
			updmn(1, 0, n-1, a, L[a]);
		}
		for(int a=n-1;a>=0;a--){
			int r = (upper_bound(X.begin(), X.end(), s[a].x + s[a].r) - X.begin()) - 1;
			debug("a %d r %d\n", a, r);
			R[a] = max(a, qrymx(1, 0, n-1, a+1, r)); 
			debug("R[%d] %d\n", a, R[a]);
			updmx(1, 0, n-1, a, R[a]);
		}
		sort(s, s+n, cmp);
		for(int i=0;i<n;i++){
			int a = s[i].i;
			debug("a %d L %d R %d\n", a, L[a], R[a]);
			L[a] = min(L[a], qrymn(1, 0, n-1, L[a], R[a]));
			R[a] = max(R[a], qrymx(1, 0, n-1, L[a], R[a]));
			debug("processa %d\n", a);
			debug("L[%d] %d\nR[%d] %d\n", a, L[a], a, R[a]);
			updmn(1, 0, n-1, a, L[a]);
			updmx(1, 0, n-1, a, R[a]);
		}
		for(int a=0;a<n;a++){
			printf("%d", R[a] - L[a] + 1); 
			if(a != n-1)
				printf(" ");
		}
		printf("\n");
	}
}
