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

const int MAXN = 1123456;

int n, m, k;
ll s[MAXN], tree[MAXN*4];

struct qryy{
	int l, r, i;
	ll res;
	qryy(int ll, int rr, int ii){
		l = ll;
		r = rr;
		i = ii;
	}
	qryy(){}

	bool const operator < (qryy o) const {
		return i < o.i;
	}
} q[MAXN];

bool cmp(qryy a, qryy b){
	return a.r < b.r;
}

void upd(int idx, int i, int j, int l, ll val){
	if(idx == 1)
		debug("\nUPD i %d, j %d, l %d, val %lld\n", i, j, l, val);
	if(i > l || j < l) return ;
	if(i >= l && j <= l){
		tree[idx] ^= val;
		return;
	}
	int m = (i + j)/2;
	upd(idx*2, i, m, l, val);
	upd(idx*2+1, m+1, j, l, val);
	tree[idx] = tree[idx*2]^tree[idx*2+1];
}

ll qry(int idx, int i, int j, int l, int r){
	if(idx == 1)
		debug("\nQRY i %d, j %d, l %d, r %d\n", i, j, l, r);
	if(i > r || j < l) return 0;
	if(i >= l && j <= r)
		return tree[idx];
	int m = (i + j)/2;
	ll ans = qry(idx*2, i, m, l, r) ^ qry(idx*2+1, m+1, j, l, r);
	return ans;
}

map<ll, int> ult;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld", &s[a]);
	}
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		int l, r;
		scanf("%d %d", &l, &r);
		l--;r--;
		q[a] = qryy(l, r, a);
	}
	sort(q, q+m, cmp);
	int j =0;
	for(int a=0;a<m;a++){
		while(j <= q[a].r){
			debug("s[%d] = %lld\n", j, s[j]);
			if(ult.find(s[j]) != ult.end())
				upd(1, 0, n-1, ult[s[j]], s[j]);
			ult[s[j]] = j;
			j++;
		}
		q[a].res = qry(1, 0, n-1, q[a].l, q[a].r);
		debug("RES %lld\n", q[a].res);
	}
	sort(q, q+m);
	for(int a=0;a<m;a++){
		printf("%lld\n", q[a].res);
	}
}
