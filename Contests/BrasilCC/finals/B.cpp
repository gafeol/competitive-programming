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

const int MAXN = 312345;

int n, m, k;
ll s[MAXN];
int nxt[MAXN], bef[MAXN], ind[MAXN];

ll tree[MAXN*4];

vector<int> v;
vector<int> val;

ll cus(ll c, ll tam){
	if(tam > c)
		tam = c;
	return tam*c - ((tam-1)*tam)/2;
}

void build(int idx, int i, int j){
	if(i == j){
		tree[idx] = val[i];
		return ;
	}

	int m = (i+j)/2;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
}

ll qry(int idx, int i, int j, int l, int r){
	if(i > r || j < l)
		return 0;
	if(i >= l && j <= r)
		return tree[idx];
	
	int m = (i+j)>>1;

	return max(qry(idx*2, i, m, l, r),
				qry(idx*2+1, m+1, j, l, r));
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%lld", &s[a]);
		if(a == 0 || s[a-1] != s[a])
			bef[a] = a;
		else
			bef[a] = bef[a-1];
	}
	nxt[n-1] = n-1;
	for(int a=n-2;a>=0;a--){
		if(s[a] == s[a+1])
			nxt[a] = nxt[a+1];
		else
			nxt[a] = a;
	}
	for(int a=0;a<n;a++){
		if(a == bef[a]){
			debug("cara %d == bef %d\n", a, bef[a]);
			int tam = nxt[a]- a + 1;
			val.pb(cus(s[a], tam));
		}
		ind[a] = (int)val.size()-1;
		debug("ind[%d] %d\n", a, ind[a]);
	}
	build(1, 0, val.size()-1);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		i--;
		j--;
		int l = ind[i];
		int r = ind[j];
		debug("qry(%d %d) l %d r %d\n", i, j, l, r);
		ll res = 0;	
		if(l == r)
			res = cus(s[i], j - i + 1);
		else{
			res = max(res, cus(s[i], nxt[i] - i + 1));
			res = max(res, cus(s[j], j - bef[j] + 1));
			debug("borda esq cus %lld %d\n", s[i], nxt[i] - i + 1);
			debug("borda dir cus %lld %d\n", s[j], j - bef[j] + 1);
			if(l + 1 <= r - 1)
				res = max(res, qry(1, 0, val.size()-1, l+1, r-1));
		}
		printf("%lld\n", res);
	}
}
