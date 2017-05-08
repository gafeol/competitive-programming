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
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
pii s[MAXN];

map<int, vector<ppi>> ind;

ppi mk(int a, int b, int c){
	return ppi(pii(a, b), c);
}

void upd(int idx, int i, int j, int l, int r){
	
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int x, xx, y, yy;
		scanf("%d %d %d %d", &x, &y, &xx, &yy);
		ind[x].pb(mk(y, yy, 0));
		ind[xx].pb(mk(y, yy, 1));
	}
	
	vector<ppi> ev;
	int xx = -1;
	ll res = 0;
	for(auto& it: ind){
		int x = it.fst;
		if(xx != -1){
			res += (x - xx)*tree[1].res;
		}
		ev = it.snd;
		for(ppi e: ev){
			int i = e.fst.fst, j = e.fst.snd, t = e.snd;
			upd(1, 0, 30000, i, j, t);
		}
		xx = x;
	}
}
