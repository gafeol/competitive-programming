#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
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

const int MAXN = 8000026;

int n, m, k;
pii s[MAXN];

struct arv{
	int mn, lz;

	arv(){}
	arv(int mm, int ll){
		mn = mm;
		lz = ll;
	}

} tree[4*MAXN];


void build(int idx, int i, int j){
	tree[idx].mn = 0;
	tree[idx].lz = 0;
	if(i == j)
		return ;
	int m = (i + j)>>1;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
}

void upd(int idx, int i, int j, int l, int r, int t){
	if(i > r || j < l) return ;
	if(tree[idx].lz != 0){
		int aux = tree[idx].lz;
		tree[idx].lz = 0;
		if(i != j){
			tree[idx*2].lz += aux;
			tree[idx*2+1].lz += aux;
			tree[idx*2].mn += aux;
			tree[idx*2+1].mn += aux;
		}
	}
	if(i >= l && j <= r){
		tree[idx].lz += t;
		tree[idx].mn += t;
		return ;
	}

	int m = (i + j)>>1;
	upd(idx*2, i, m, l, r, t);
	upd(idx*2+1, m+1, j, l, r, t);
	tree[idx].mn = min(tree[idx*2].mn, tree[idx*2+1].mn);
}

map<int, vector<ppi> > ind;

ppi mk(int a, int b, int c){
	return ppi(pii(a, b), c);
}

bool go(int t){
	debug("go %d\n", t);
	build(1, -t, t);
	ind.clear();
	for(int a=0;a<n;a++){
		ind[(s[a].fst - t)].pb(mk(s[a].snd-t, s[a].snd+t, 0));
		ind[(s[a].fst + t) + 1].pb(mk(s[a].snd-t, s[a].snd+t, 1));
	}
	ind[(-t)].pb(mk(-t, t, 2));
	ind[t+1].pb(mk(-t, t, 3));

	vector<ppi> ev;
	int in = 0;
	for(auto& it: ind){
		int x = it.fst;
		debug("to no x %d\n", x);
		ev = it.snd;
		for(ppi e: ev){
			int y = e.fst.fst, yy = e.fst.snd;
			debug("analisa evento (%d %d) - (%d, %d)\n", x, y, x, yy);
			if(e.snd == 0)
				upd(1, -t, t, max(-t, y), min(t, yy), 1); 
			else if(e.snd == 1)
				upd(1, -t, t, max(-t, y), min(t, yy), -1);
			else if(e.snd == 2)
				in = 1;
			else
				return false;

		}
		debug("mn %d\n", tree[1].mn);
		if(in && tree[1].mn == 0)
			return true;
	}
	return false;
}

int main (){
	int tt = 0;
	while(scanf("%d", &n) != EOF && n != -1){
		++tt;
		for(int a=0;a<n;a++){
			scanf("%d %d", &s[a].fst, &s[a].snd);
			debug("%d %d\n", s[a].fst, s[a].snd);
		}
		sort(s, s+n);
		int i = 0, j = 3000010;
		debug("i %d j %d\n", i, j);
		while(i < j){
			int m = (i + j + 1)>>1;
			debug("\ni %d j %d m %d\n", i, j, m);
			if(go(m))
				i = m;
			else
				j = m - 1;
		}
		printf("Case %d: ", tt);
		if(i >= 3000010)
			puts("never");
		else
			printf("%d\n", i+1);
	}
}
