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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 200045;

int n, m, k;
int s[MAXN];

int bit[MAXN];
multiset<int> bst[MAXN];

int f[MAXN];
vector<int> q;

int tree[MAXN*4];

int qry(int idx, int i, int j, int l){
	if(j <= l) return 0;
	if(i > l)
		return tree[idx];
	int m = (i + j)/2;
	return max(qry(idx*2, i, m, l), qry(idx*2+1, m+1, j, l));
}

void upd(int idx, int i, int j, int l){
	debug("upd %d %d %d %d\n", idx, i, j, l);
	if(i > l || j < l) return ;
	if(i == j){
		tree[idx] = (bst[i].empty() ? 0 : *bst[i].rbegin());
		return ;
	}
	int m = (i + j)/2;
	upd(idx*2, i, m, l);
	upd(idx*2+1, m+1, j, l);
	tree[idx] = max(tree[idx*2], tree[idx*2+1]);
}

void build(int idx, int i, int j){
	if(i == j){
		tree[idx] = (bst[i].empty() ? 0 : *bst[i].rbegin());
		return ;
	}
	int m = (i + j)/2;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
	tree[idx] = max(tree[idx*2], tree[idx*2+1]);
}

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		q.clear();
		for(int a=0;a<n;a++)
			bst[a].clear();
		for(int a=0;a<n;a++){
			scanf("%d", s+a);
			q.pb(s[a]);
		}
		sort(q.begin(), q.end());
		q.erase(unique(q.begin(), q.end()), q.end());
		for(int a=0;a<n;a++){
			s[a] = lower_bound(q.begin(), q.end(), s[a]) - q.begin();
		}
		f[n-1] = 1;
		bst[s[n-1]].insert(1);
		for(int a=n-2;a>=0;a--){
			f[a] = 1;
			if(s[a] < s[a+1])
				f[a] = f[a+1]+1;
			bst[s[a]].insert(f[a]);
		}
		build(1, 0, n);

		int cnt = 1;
		int res = 0;
		for(int a=0;a<n;a++){
			if(a > 0){
				if(s[a] > s[a-1])
					cnt++;
				else
					cnt = 1;
			}
			bst[s[a]].erase(bst[s[a]].find(f[a]));
			upd(1, 0, n, s[a]);
			res = max(res, cnt + qry(1, 0, n, s[a]));
		}
		printf("%d\n", res);
	}
}

