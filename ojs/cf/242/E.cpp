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

const int MAXN = 100009;

int n, m, k;
int s[MAXN];

struct arv{
	ll sum, lz;
	arv(){
		sum = 0;
		lz = 0;
	}
	arv(ll s, ll l){
		sum = s;
		lz = l;
	}
} tree[MAXN*4][20];

ll qry(int idx, int p, int i, int j, int l, int r){
	if(i > r || j < l) return 0;	
	
	arv &x = tree[idx][p];

	if(x.lz != 0){
		int m = (i + j)>>1;
		x.lz = 0;
		if(i != j){
			arv &L = tree[idx*2][p];
			arv &R = tree[idx*2+1][p];
			L.sum = m - i + 1 - L.sum;
			L.lz ^= 1;
			R.sum = j - m - R.sum;
			R.lz ^= 1;
		}
	}

	if(i >= l && j <= r)
		return x.sum;
	
	int m = (i + j)>>1;
	return qry(idx*2, p, i, m, l, r) + 
		qry(idx*2+1, p, m+1, j, l, r);
}

void upd(int idx, int p, int i, int j, int l, int r){
	if(i > r || j < l) return ;	
	
	arv &x = tree[idx][p];

	if(x.lz != 0){
		int m = (i + j)>>1;
		x.lz = 0;
		if(i != j){
			arv &L = tree[idx*2][p];
			arv &R = tree[idx*2+1][p];
			L.sum = m - i + 1 - L.sum;
			L.lz ^= 1;
			R.sum = j - m - R.sum;
			R.lz ^= 1;
		}
	}

	if(i >= l && j <= r){
		x.sum = j - i + 1 - x.sum;
		x.lz ^= 1;
		return ;
	}
	
	int m = (i + j)>>1;
	upd(idx*2, p, i, m, l, r);
	upd(idx*2+1, p, m+1, j, l, r);
	x.sum = tree[idx*2][p].sum + tree[idx*2+1][p].sum;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		int x = s[a];
		for(int p = 0;p < 20;p++){
			if(x&1)
				upd(1, p, 0, n-1, a, a);
			x >>= 1;
		}
	}
	scanf("%d", &m);
	for(int a=0;a<m;a++){
//		printf("qry(6): %lld%lld%lld%lld\n", qry(1, 3, 0, n-1, 6, 6), qry(1, 2, 0, n-1, 6, 6), qry(1, 1, 0, n-1, 6, 6), qry(1, 0, 0, n-1, 6, 6));
		int t, i, j;
		scanf("%d %d %d", &t, &i, &j);
		i--;
		j--;
		if(t == 1){
			ll res = 0;
			for(int p = 0;p < 20;p++){
				res += (1<<p)*qry(1, p, 0, n-1, i, j); 
			}
			printf("%lld\n", res);
		}
		else{
			int x;
			scanf("%d", &x);
			for(int p = 0;p < 20;p++){
				if(x&1)
					upd(1, p, 0, n-1, i, j);
				x >>=  1;
			}
		}
	}
}
