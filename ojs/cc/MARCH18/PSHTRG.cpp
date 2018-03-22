#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<pli, pii> ppp;
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

const int MAXN = 112345;

int n, m, k;
ll s[MAXN];

pli tree[MAXN*4];

void build(int idx, int i, int j){
	if(i == j){
		tree[idx] = pli(s[i], i);
		return ;
	}
	int m = (i+j)/2;
	build(idx*2, i,m);
	build(idx*2+1, m+1, j);
	tree[idx] = max(tree[idx*2], tree[idx*2+1]);
}

pli qry(int idx, int i, int j, int l, int r){
	if(i > r || j < l) return pli(-1, 0);
	if(i >= l && j <= r)
		return tree[idx];
	int m = (i+j)/2;
	return max(qry(idx*2, i, m, l, r), qry(idx*2+1, m+1, j, l, r));
}

void upd(int idx, int i, int j, int l, ll x){
	if(i > l || j < l) return ;
	if(i >= l && j <= l){
		tree[idx] = pli(x, i);
		return ;
	}
	int m = (i+j)/2;
	upd(idx*2, i, m, l, x);
	upd(idx*2+1, m+1, j, l, x);
	tree[idx] = max(tree[idx*2], tree[idx*2+1]);
}

set<ppp> q;

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
	}
	build(1, 0, n-1);
	for(int a=0;a<m;a++){
		int t;
		scanf("%d", &t);
		if(t-1){
			ll mx[3];
			int l, r;
			scanf("%d %d", &l, &r);
			l--;r--;
			pli aux = qry(1, 0, n-1, l, r);
			q.clear();
			q.insert(ppp(pii(-aux.fst, aux.snd), pii(l, r)));
			mx[0] = mx[1] = mx[2] = -1;
			while(!q.empty() && (mx[2] == -1 || mx[2] >= mx[0] + mx[1])){
				mx[2] = mx[1];
				mx[1] = mx[0];
				ppp bg = *q.begin();
				mx[0] = -bg.fst.fst;
				q.erase(q.begin());
				pii pos = bg.snd;
				int i = bg.fst.snd;
				if(pos.fst < i){
					pli ans = qry(1, 0, n-1, pos.fst, i-1);
					q.insert(ppp(pli(-ans.fst, ans.snd), pii(pos.fst, i-1)));
				}
				if(i < pos.snd){
					pli ans = qry(1, 0, n-1, i+1, pos.snd);
					q.insert(ppp(pli(-ans.fst, ans.snd), pii(i+1, pos.snd)));
				}
			}
			if(mx[2] == -1 || mx[2] >= mx[0] + mx[1])
				puts("0");
			else
				printf("%lld\n", mx[0] + mx[1] + mx[2]); 
		}
		else{
			int pos;
			ll val;
			scanf("%d%lld", &pos, &val);
			pos--;
			upd(1, 0, n-1, pos, val);
		}
	}
}

