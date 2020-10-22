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

const int MAXN = 5123;

int n, m, k;
int s, t;
int tim[MAXN], mai[MAXN];


struct ares{
	int nxt;
	int l, r;
};

vector<ares> adj[MAXN];

vector<int> pos;

set<pii> q;

inline void upd(int u, int tem){
	if(tim[u] != tem){
		tim[u] = tem;
		mai[u] = 0;
	}
}

inline int go(int ini, int v){
	debug("begin djalma %d %d\n", ini, v);
	q.clear();
	q.insert(pii(-k, ini));
	while(!q.empty()){
		pii beg = *q.begin();
		int u = beg.snd;
		int mx = -beg.fst;
		debug("u %d %d\n", u, mx);
		if(u == t) return mx;
		q.erase(q.begin());
		for(ares ar: adj[u]){
			if(ar.l > v || ar.r < v) continue; 
			int mmx = min(mx, ar.r);
			upd(ar.nxt, v);
			if(mai[ar.nxt] < mmx){
				if(mai[ar.nxt] != 0)
					q.erase(pii(-mai[ar.nxt], ar.nxt));
				mai[ar.nxt] = mmx;
				q.insert(pii(-mai[ar.nxt], ar.nxt));
			}
		}
	}
	return 0;
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
	scanf("%d %d", &s, &t);
	for(int a=0;a<m;a++){
		int i, j, l, r;
		scanf("%d %d %d %d", &i, &j, &l, &r);
		pos.pb(l);
		adj[i].pb({j, l, r});
	}
	sort(pos.begin(), pos.end());
	pos.erase(unique(pos.begin(), pos.end()), pos.end());
	int ate = 0;
	int res =0;
	for(int v: pos){
		if(v <= ate) continue;
		debug("testa %d\n", v);
		int up = go(s, v);
		if(up >= v){
			res += up-v+1;
			ate = up;
		}
		debug("up %d\n", up);
	}
	printf("%d\n", res);
}

