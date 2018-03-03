#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];
int p[MAXN], sz[MAXN];

vector<vector<int> > c;

unordered_map<int, set<int> > has;

int head = 0, deg = 1;
int l[MAXN*31], r[MAXN*31];
int cnt[MAXN*31];

inline void add(int u, int x, int i){
	cnt[u]++;
	if(i == -1){
		has[u].insert(x);
		return ;
	}
	int nxt;
	if((s[x]&(1<<i))){
		if(r[u] == -1) r[u] = deg++;
		nxt = r[u];
	}
	else{
		if(l[u] == -1) l[u] = deg++;
		nxt = l[u];
	}
	add(nxt,x, i-1);
}

inline void rmv(int u, int x, int i){
	cnt[u]--;
	if(i == -1){
		has[u].erase(x);
		return ;
	}
	int nxt;
	if((s[x]&(1<<i)))
		nxt = r[u];
	else
		nxt = l[u];
	rmv(nxt,x, i-1);
}

int other;

inline int qry(int u, int x, int i){
	if(i == -1){
		other = *has[u].begin();
		return 0;
	}
	int nxt;
	if((s[x]&(1<<i))){
		if(r[u] == -1 || cnt[r[u]] == 0) 
			return qry(l[u], x, i-1) + (1<<i);
		return qry(r[u], x, i-1);
	}
	else{
		if(l[u] == -1 || cnt[l[u]] == 0)
			return qry(r[u], x, i-1) + (1<<i);
		return qry(l[u], x, i-1);
	}
}

inline int raiz(int u){
	if(p[u] == u) return u;
	return p[u] = raiz(p[u]);
}

inline void join(int u, int v){
	u = raiz(u);
	v = raiz(v);
	if(u == v) return;
	if(sz[u] > sz[v])
		swap(u,v);
	p[u] = v;
	sz[v] += sz[u];
}

unordered_map<int, vector<int> > mrk;
vector<int> aux;

int main (){
	memset(l, -1, sizeof(l));
	memset(r, -1, sizeof(r));
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		p[a] = a;
		sz[a] = 1;
		scanf("%d", s+a);
	}
	sort(s, s+n);
	for(int a=0;a<n;a++){
		add(0, a, 29);
		aux.clear();
		aux.pb(a);
		c.pb(aux);
	}
	ll res = 0;
	int cnt = 0, cnt2 = 0;
	while(c.size() > 1){
		cnt++;
		set<pip> ares;
		for(vector<int> &v: c){
			pip cus;
			cus = {INT_MAX,{0,0}};
			for(int u: v) rmv(0, u, 29);
			for(int u: v){
				cnt2++;
				int val = qry(0, u, 29);
				if(cus.fst > val)
					cus = pip(val, pii(u, other));
			}
			for(int u: v) add(0, u, 29);
			int ui = min(raiz(cus.snd.fst), raiz(cus.snd.snd));
			int uj = max(raiz(cus.snd.fst), raiz(cus.snd.snd));
			cus = pip(cus.fst, pii(ui, uj));
			ares.insert(cus);
		}
		while(!ares.empty()){
			pip ar = *ares.begin();
			ares.erase(ares.begin());
			int u = ar.snd.fst;
			int v = ar.snd.snd;
			ll pes = (ll)ar.fst;
			if(raiz(u) == raiz(v)) continue;
			res += pes;
			join(u, v);
		}
		mrk.clear();
		c.clear();
		for(int a=0;a<n;a++)
			mrk[raiz(a)].pb(a);

		for(auto &it : mrk){
			c.pb(it.snd);
			it.snd.clear();
		}
	}
	printf("%lld\n", res);
}
