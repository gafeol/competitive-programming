#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define int ll
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)
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
int s[MAXN];
int c[MAXN];
int nc, na;
int S, t;

namespace f {

const int N = MAXN*2, M = MAXN*2*2;
typedef int val;
typedef int num;
int es[N], to[M], nx[M], en, pai[N];
val fl[M], cp[M];
num cs[M], d[N];
const num inf = 1e8, eps = 0;
const val infv = INT_MAX;
int seen[N], tempo;
int qu[N];

num tot;
bool spfa(int s, int t) {
	tempo++;
	int a = 0, b = 0;
	for(int i = 0; i < N; i++) d[i] = inf;
	d[s] = 0;
	qu[b++] = s;
	seen[s] = tempo;
	while(a != b) {
		int u = qu[a++]; if(a == N) a = 0;
		seen[u] = 0;
		for(int e = es[u]; e != -1; e = nx[e])
			if(cp[e] - fl[e] > val(0) && d[u] + cs[e] < d[to[e]] - eps) {
				d[to[e]] = d[u] + cs[e]; pai[to[e]] = e ^ 1;
				if(seen[to[e]] < tempo) { seen[to[e]] = tempo; qu[b++] = to[e]; if(b == N) b = 0; }
			}
	}
	if(d[t] == inf) return false;
	val mx = infv;
	for(int u = t; u != s; u = to[pai[u]])
		mx = min(mx, cp[pai[u] ^ 1] - fl[pai[u] ^ 1]);
	tot += d[t] * val(mx);
	for(int u = t; u != s; u = to[pai[u]])
		fl[pai[u]] -= mx, fl[pai[u] ^ 1] += mx;
	return mx;
}

void init(int n) {
	en = 0;
	memset(es, -1, sizeof(int) * n);
}

val flow;
num mncost(int s, int t) {
	tot = 0; flow = 0;
	while(val a = spfa(s, t)) flow += a;
	nc = flow;
	na = tot;
	return tot;
}

void add_edge(int u, int v, val c, num s) {
	fl[en] = 0; cp[en] = c; to[en] = v; nx[en] = es[u]; cs[en] =  s; es[u] = en++;
	fl[en] = 0; cp[en] = 0; to[en] = u; nx[en] = es[v]; cs[en] = -s; es[v] = en++;
}
}

map<int, vector<int> > ind;

int nso[MAXN], mrk[MAXN];
using namespace f;

void go(int v){
	for(int a=0;a<en;a+=2){
		if(fl[a] != 0){
			if(to[a] == t || to[a] == S || to[a+1] == t || to[a+1] == S)
				continue;
			if(to[a] <= m){
				mrk[to[a+1]-m] = to[a];
				nso[to[a]] = cs[a];
			}
			else{
				mrk[to[a]-m] = to[a+1];
				nso[to[a+1]] = cs[a+1];
			}
		}
	}
}

main (){
	scanf("%lld%lld", &n, &m);
	f::init(n+m+5);
	S = n+m+3;
	t = n+m+4;
	for(int a=1;a<=n;a++){
		scanf("%lld", &c[a]);
		ind[c[a]].pb(a);
		f::add_edge(m+a, t, 1, 0);
	}
	for(int a=1;a<=m;a++){
		f::add_edge(S, a, 1, 0); 
		scanf("%lld", &s[a]);
		int val = s[a];
		int cus = 0;
		while(val != 1){
			if(ind.find(val)!= ind.end()){
				for(int nxt: ind[val]){
					f::add_edge(a, nxt+m, 1, cus);
				}
			}
			val = (val+1)/2;
			cus++;
		}
		if(ind.find(val) != ind.end()){
			for(int nxt: ind[val]){
				f::add_edge(a, nxt+m, 1, cus);
			}
		}
	}
	f::mncost(S, t);
	printf("%lld %lld\n", nc, na);
	go(S);
	for(int a=1;a<=m;a++){
		printf("%lld ", -nso[a]);
	}
	printf("\n");
	int c = 1;
	for(int a=1;a<=n;a++){
		if(mrk[a])
			printf("%lld ", mrk[a]);
		else
			printf("0 ");
	}
}
