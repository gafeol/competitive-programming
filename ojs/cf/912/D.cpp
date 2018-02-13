#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
#define int ll
typedef pair<int, int> pii;
typedef pair<ll, pii> pip;
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

int vi[] = {0, 0, 1, -1};
int vj[] = {1, -1, 0, 0};

int n, m, k, r;
int s[MAXN];

set<pip> q;

map<int, map<int, int> > mrk;

ll f(int i, int j){
	ll h = min(m - j, r) + min(r-1, j); 
	ll v = min(n - i, r) + min(r-1, i);
	return (h-r+1)*(v-r+1); 
}

pip mk(ll a, int b, int c){
	return pip(a, pii(b, c));
}

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m);
}

main (){
	scanf("%lld%lld%lld%lld", &n, &m, &r, &k);
	q.insert(mk(-f(n/2, m/2), n/2, m/2));
	mrk[n/2][m/2] = 1;
	ll res = 0;
	while(k > 0){
		k--;
		pip top = *q.begin();
		q.erase(q.begin());
		res = res - top.fst;
		pii pos = top.snd;
		int i = pos.fst, j = pos.snd;
		for(int d=0;d<4;d++){
			int ii = i + vi[d], jj = j + vj[d];
			if(valid(ii, jj) && (mrk.find(ii) == mrk.end() || mrk[ii].find(jj) == mrk[ii].end())){
				q.insert(mk(-f(ii, jj), ii, jj));
				mrk[ii][jj] = 1;
			}
		}
	}
	ll tot = (ll(n-r+1)*(ll(m-r+1)));
	printf("%.20Lf\n", (long double)res/((n-r+1)*(m-r+1)));
}

