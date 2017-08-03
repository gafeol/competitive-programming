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

const int MAXN = 35234, MAXK = 51;

int n, m, k;
int s[MAXN];
int nxt[MAXN], pos[MAXN];
int dp[MAXN][MAXK];

struct arv{
	int lz, mx;
} tree[4*MAXN];

void build(int idx, int i, int j){
	tree[idx].lz = tree[idx].mx = 0;
	if(i == j) return ;
	int m = (i + j)/2;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
}

void unlaze(int idx, int i, int j){
	int aux = tree[idx].lz;
	tree[idx].lz = 0;
	if(i != j){
		tree[idx*2].mx += aux;
		tree[idx*2+1].mx += aux;
		tree[idx*2].lz += aux;
		tree[idx*2+1].lz += aux;
	}
}

int qry(int idx, int i, int j, int l, int r){
	if(i > r || j < l) return 0;
	unlaze(idx, i, j);
	if(i >= l && j <= r)
		return tree[idx].mx;
	int m = (i + j)/2;
	return max(qry(idx*2, i, m, l, r),
			qry(idx*2+1, m+1, j, l, r));
}

void upd(int idx, int i, int j, int l, int r, int x){
	if(i > r || j < l) return ;
	unlaze(idx, i, j);
	if(i >= l && j <= r){
		tree[idx].mx += x;
		tree[idx].lz += x;
		return;
	}
	int m = (i+j)/2;
	upd(idx*2, i, m, l, r, x);
	upd(idx*2+1, m+1, j, l, r, x);
	tree[idx].mx = max(tree[idx*2].mx, tree[idx*2+1].mx);
}

void solve(int kk){
	build(1, 0, n);
	for(int a=n-1;a>=0;a--){
		upd(1, 0, n, a+1, nxt[a], 1);
		debug("upd %d - %d com 1\n", a+1, nxt[a]);
		dp[a][kk] = qry(1, 0, n, a+1, n);
		debug("dp[%d][%d] %d\n", a, kk, dp[a][kk]);
		upd(1, 0, n, a, a, dp[a][kk-1]);
	}
}

int beg[MAXN];

int main (){
	scanf("%d%d", &n, &k);
	k--;
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		pos[s[a]] = n;
	}
	int ans = 0;
	memset(beg, -1, sizeof(beg));
	memset(dp, 0, sizeof(dp));
	for(int a=n-1;a>=0;a--){
		nxt[a] = pos[s[a]];
		pos[s[a]] = a;
		if(beg[s[a]] == -1){
			beg[s[a]] = a;
			ans++;
		}
		dp[a][0] = ans;
	}
	dp[n][0] = 0;
	for(int j=1;j<=k;j++){
		debug("solve %d\n", j);
		solve(j);
	}
	int res = 0;
	for(int a=0;a<=k;a++){
		res = max(dp[0][a], res);
	}
	printf("%d\n", res);
}
