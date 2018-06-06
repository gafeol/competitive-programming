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
const ll modn = 998244353;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

set<pii> seg[MAXN];

struct arv{
	ll sum;
	ll lzs;
	ll lzm;
} tree[MAXN*4];

void unlaze(int idx, int i, int j){
	int l = idx*2, r = idx*2+1;
	ll auxs = tree[idx].lzs;
	ll auxm = tree[idx].lzm;
	tree[idx].sum = mod(mod(tree[idx].sum * auxm) + auxs);
	tree[idx].lzs = 0;
	tree[idx].lzm = 1;
	if(i == j) return ;
	tree[l].lzs = mod(mod(tree[l].lzs*auxm)+auxs);
	tree[l].lzm = mod(tree[l].lzm * auxm);
	
	tree[r].lzs = mod(mod(tree[r].lzs*auxm)+auxs);
	tree[r].lzm = mod(tree[r].lzm * auxm);
}

void build(int idx, int i, int j){
	tree[idx].sum = 0;
	tree[idx].lzs = 0;
	tree[idx].lzm = 1;
	if(i == j)
		return ;
	int m = (i + j)/2;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
}


//Se so somar, mul = 1
void upd(int idx, int i, int j, int l, int r, ll sum, ll mul){
	if(i > r || j < l) return ;
	unlaze(idx, i, j);
	if(i == j){
		tree[idx].lzs = mod(mod(tree[idx].lzs * mul) + sum);
		tree[idx].lzm = mod(tree[idx].lzm * mul);
		return ;
	}
	int m = (i + j)/2;
	upd(idx*2, i, m, l, r, sum, mul);
	upd(idx*2+1, m+1, j, l, r, sum, mul);
}

ll qry(int idx, int i, int j, int l, int r){
	if(i > r || j < l) return 0;
	unlaze(idx, i, j);
	if(i == j)
		return tree[idx].sum;
	int m = (i + j)/2;
	return mod(qry(idx*2, i, m, l, r) +
				qry(idx*2+1, m+1, j, l, r));
}

void dob(int i, int j){
	upd(1, 0, n-1, i, j, 0, 2);
}

void som(int i, int j){
	upd(1, 0, n-1, i, j, 1, 1);
}


vector<ppp> atu;

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
		int t;
		int l, r;
		scanf("%d", &t);
		if(t == 1){
			int x;
			scanf("%d %d %d", &l, &r, &x);
			l--;r--;
			atu.clear();
			auto itb = seg[x].upper_bound(pii(l, n));
			auto ite = seg[x].upper_bound(pii(r, n));
			if(itb == seg[x].begin()){
				som(l, r);
				seg[x].insert(pii(l, r));
			}
			else{
				--itb;
				--ite;
				int l1 = itb->l, r1 = itb->r;
				int l2 = ite->l, r2 = ite->r;
				if(r1 < l && l2 > r){
					auto prv = NULL;
					for(auto it = ++itb;it != ite;++it){
						if(prv != NULL) seg[x].erase(prv);
						prv = it;

					}
					if(prv != NULL) seg[x].erase(prv);
				}
			}
			int ult = l;
			if(it != seg[x].begin()){
				auto bef = it;
				bef--;
				int ll = bef->fst;
				int rr = bef->snd;
				if(rr >= l){
					dob(l, min(rr, r));
					if(rr < r)
						atu.pb(pii(ll, rr), pii(ll, r));
					ult = max(rr, r)+1;
				}
			}
			while(it != seg[x].end()){
				int ll = it->fst;
				int rr = it->snd;
				if(ll > l) break;
				if(rr <= ult){
					atu.pb(pii(ll, rr, -1, -1));
					dob(ll, rr);
				}
				else{
					ult = rr+1;
				}
				dob(
			}
			for(ppp p: atu){
				seg[x].erase(p.fst);
				seg[x].insert(p.snd);
			}
		}
	}
}

