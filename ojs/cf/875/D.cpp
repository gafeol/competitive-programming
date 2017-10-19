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

const int MAXN = 212345, LOG = 30;

vector<ll> bit[LOG];

int n, m, k;
int s[MAXN];

pii tree[MAXN*4];

void build(int idx, int i, int j){
	if(i == j){
		tree[idx] = pii(s[i], i);
		return ;
	}
	int m = (i + j)/2;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
	tree[idx] = max(tree[idx*2], tree[idx*2+1]);
}

pii qry(int idx, int i, int j, int l, int r){
	if(i > r || j < l) return pii(-1, 0);
	if(i >= l && j <= r)
		return tree[idx];
	int m = (i + j)/2;
	return max(qry(idx*2, i, m, l, r),
				qry(idx*2+1, m+1, j, l, r));
}

bool cmp(int a, int b){
	return s[a] > s[b];
}

ll res;

bool in (int x, int i, int j){
	return (x >= i && x<=j);
}

void go(int i, int j){
	if(i >= j) return ;
	pii x = qry(1, 0, n-1, i, j);
	int mx = x.fst;
	int imx = x.snd;
	debug("i %d j %d mx %d imx %d\n", i, j, mx, imx);
	ll L = i;
	ll R = j;
	for(int a =0;a < LOG;a++){
		if(mx&(1<<a)) continue;
		ll l = lower_bound(bit[a].begin(), bit[a].end(), imx) - bit[a].begin() - 1;
		if(l > 0 && l < bit[a].size() && in(bit[a][l], i, j))
			L = max(L, bit[a][l]+1);
		ll r = upper_bound(bit[a].begin(), bit[a].end(), imx) - bit[a].begin();
		if(r > 0 && r < bit[a].size() && in(bit[a][r], i, j))
			R = min(R, bit[a][r]-1);

	}
	res += (L-i)*(j-imx+1) + (j - R);
	debug("L %lld R %lld\n", L, R);
	debug("soma %d + %d\n", (L-i)*(j-imx+1), (j - R));
	go(i, imx-1);
	go(imx+1, j);
}

int main (){
	scanf("%d", &n);
	for(int i=0;i<LOG;i++)
		bit[i].pb(-1);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		for(int i=0;i<LOG;i++){
			if((1<<i)&s[a])
				bit[i].pb(a);
		}
	}
	for(int i=0;i<LOG;i++)
		bit[i].pb(n);
	build(1, 0, n-1);
	go(0, n-1);
	printf("%lld\n", res);
}

