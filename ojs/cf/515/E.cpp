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

const int MAXN = 212345;

int n, m, k;
ll d[MAXN], h[MAXN];
ll s[2][MAXN];

struct arv{
	ll mx, mx2;
	int imx, imx2;
} tree[2][8*MAXN], zer;

arv cmp(arv a, arv b){
	arv res;
	if(a.mx < b.mx)
		swap(a, b);
	res.mx = a.mx;
	res.imx = a.imx;
	if(a.mx2 > b.mx){
		res.mx2 = a.mx2;
		res.imx2 = a.imx2;
	}
	else{
		res.mx2 = b.mx;
		res.imx2 = b.imx;
	}

	return res;
}

void build(int idx, int t, int i, int j){
	if(i == j){
		tree[t][idx].mx = s[t][i];	
		tree[t][idx].imx = i;
		tree[t][idx].mx2 = LLONG_MIN;
		return ;
	}
	
	int m = (i + j)>>1;

	build(idx*2, t, i, m);
	build(idx*2+1, t, m+1, j);
	tree[t][idx] = cmp(tree[t][idx*2], tree[t][idx*2+1]);
}

arv qry(int idx, int t, int i, int j, int l, int r){
	if(i > r || j < l)
		return zer;
	if(i >= l && j <= r)
		return tree[t][idx];

	int m = (i + j)>>1;

	return cmp(qry(idx*2, t, i, m, l, r),
		qry(idx*2 + 1, t, m+1, j, l, r));
}

ll som(arv a, arv b){
	if(a.imx != b.imx)
		return a.mx + b.mx;

	return max(a.mx + b.mx2, a.mx2 + b.mx);
}

int main (){

	zer.mx = LLONG_MIN;
	zer.mx2 = LLONG_MIN;

	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%lld", &d[a]);	
		d[a+n] = d[a];
	}
	for(int a=0;a<n;a++){
		scanf("%lld", &h[a]);
		h[a+n] = h[a];
	}
	for(int a=0;a<2*n;a++){
		if(a != 0){
			s[0][a] = s[0][a-1] - 2*h[a-1];
			s[0][a] += d[a-1]; 
			s[1][a] = s[1][a-1] - 2*h[a-1];
			s[1][a] -= d[a-1];
		}
		s[1][a] += 2*h[a];
		s[0][a] += 2*h[a];
	}

	for(int t=0;t<2;t++){
		for(int a=0;a<2*n;a++){
			debug("s[%d][%d] = %lld\n", t, a, s[t][a]);
		}
		printf("\n");
	}
	
	build(1, 0, 0, 2*n-1);
	build(1, 1, 0, 2*n-1);

	for(int a=0;a<m;a++){
		int l, r;
		scanf("%d %d", &l, &r);	
		l--;
		r--;
		ll r1, r2;
		r1 = r2 = LLONG_MIN;
		if(r < l){
			if(l-1 >= r+1){
				r1 = som(qry(1, 0, 0, 2*n-1, r+1, l-1), qry(1, 1, 0, 2*n-1, r+1, l-1));
			}
		}
		else{
			if(l-1 >= 0){
				r1 = som(qry(1, 0, 0, 2*n-1, 0, l-1), qry(1, 1, 0, 2*n-1, 0, l-1));
			}
			if(r+1 < l+n){
				r2 = som(qry(1, 0, 0, 2*n-1, r+1, l+n-1), qry(1, 1, 0, 2*n-1, r+1, l+n-1)); 
			}
		}

		printf("%lld\n", max(r1, r2)); 
	}
}
