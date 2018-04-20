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

const int MAXN = 252345*2;

int n, m, k;
int s[MAXN];

map<int, int> ind;
int deg;

ll ans;
ll val[MAXN];

inline int id(int i){
	if(ind.find(i) == ind.end()){
		val[deg] = (ll)i;
		ind[i] = deg++;
	}
	return ind[i];
}

int pre[MAXN];

int cyc[MAXN], mrk[MAXN], mrk2[MAXN];
vector<pii> adj[MAXN];

ll go2(int u){
	mrk2[u] = 1;
	ll res = 0;
	for(pii nxt: adj[u]){
		int v = nxt.fst;
		if(mrk2[v]) continue;
		res += val[u];
		res += go2(v);
	}
	return res;
}

void cy(int u, int ini){
	debug("u %d ini %d\n", u, ini);
	queue<int> q;
	while(u != ini){
		mrk2[u] = 1;
		q.push(u);
		ans += val[u];
		u = pre[u];
		debug("u %d\n", u);
	}
	mrk2[u] = 1;
	q.push(u);
	ans += val[u];
	u = pre[u];
	while(!q.empty()){
		ans += go2(q.front());
		q.pop();
	}
}

int mx, mxu;

void go(int u, int ult){
	if(val[u] > mx){
		mx = val[u];
		mxu = u;
	}
	mrk[u] = 1;
	for(pii nxt: adj[u]){
		if(mrk2[u]) return;
		if(nxt.snd == ult) continue;
		int v = nxt.fst;
		if(mrk[v]){
			debug("u %d mrk[%d]\n", u, v);
			cy(u, v);
		}
		else{
			pre[v] = u;
			debug("pre[%d] = %d\n", v, u);
			go(v, nxt.snd);
		}
	}
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		int u = id(i), v = id(j);
		adj[u].pb(pii(v, a));
		adj[v].pb(pii(u, a));
	}
	for(int a=0;a<deg;a++){
		if(!mrk[a]){
			mx = INT_MIN;
			debug("go %d\n", a);
			go(a, -1);	
			if(!mrk2[a]){
				debug("go2 %d\n", mxu);
				ans += go2(mxu);
			}
		}
	}
	printf("%lld\n", ans);
}

