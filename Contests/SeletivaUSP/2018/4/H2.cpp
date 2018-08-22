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

const int MAXN = 212;

int n, m, k;
int s[MAXN], ind[MAXN];

namespace f {

const int N = 51*11 + 11 + 2, M =  (51*51*11 + 51 + 51*11) * 2;
typedef int val;
typedef int num;
int es[N], to[M], nx[M], en, pai[N], ori[M];
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

void init(int n=N) {
	en = 0;
	memset(es, -1, sizeof(int) * n);
}

val flow;
num mncost(int s, int t) {
	tot = 0; flow = 0;
	while(val a = spfa(s, t)) flow += a;
	debug("mx flow %d\n", flow);
	return tot;
}

void add_edge(int u, int v, val c, num s, int o) {
	fl[en] = 0; cp[en] = c; to[en] = v; nx[en] = es[u]; cs[en] =  s; ori[en] = o; es[u] = en++;
	fl[en] = 0; cp[en] = 0; to[en] = u; nx[en] = es[v]; cs[en] = -s; es[v] = en++;
}
}

void add(int ii, int jj, int cu){
	int i = n*m + ii;
	int j = jj*m;
	for(int q=1;q<=m;q++){
		assert(i < f::N && j+q-1 < f::N);
		debug("fake %d -> %d cus %d\n", ii, jj, q*cu);
		debug("real %d -> %d cus %d\n", i, j+q-1, q*cu);
		f::add_edge(i, j+q-1, 1, q*cu, cu);
	}
}

bool cmp(int a, int b){
	return s[a] < s[b];
}

pii ex[MAXN];

int q[MAXN][MAXN];
int on[MAXN], tim[MAXN], cust[MAXN];

int main (){
	int caso = 1;
	while(scanf("%d %d", &n, &m) != EOF && n+m != 0){
		memset(q, -1, sizeof(q));
		f::init();
		for(int a=0;a<n;a++){
			scanf("%d", s+a);
			ind[a] = a;
		}
		sort(ind, ind+n, cmp);
		for(int a=0;a<m;a++){
			int t;
			scanf("%d", &t);
			int cnt =0;
			while(cnt < t){
				int mn, sp;
				scanf("%d %d", &mn, &sp);
				ex[cnt] = pii(mn, sp);
				cnt++;
			}
			ex[t] = pii(INT_MAX, 0);
			for(int bb=0;bb<n;bb++){
				int b = ind[bb];
				for(int i=0;i<t;i++){
					if(s[b] >= ex[i].fst && s[b] < ex[i+1].fst){
						add(a, b, ex[i].snd);
					}
				}
			}
		}
		int S = n*m + m;
		int T = S + 1;
		for(int a=0;a<m;a++){
			f::add_edge(S, n*m + a, 1, 0, 0);
			debug("beg to %d\n%d -> %d\n", a, S, n*m+a);
		}
		for(int a=0;a<n;a++){
			for(int i=0;i<m;i++){
				f::add_edge(a*m + i, T, 1, 0, 0);
				debug("(%d, %d) to end\n%d -> %d\n", a, i, a*m+i, T);
			}
		}
		printf("Case %d\n", caso++);
		printf("Average turnaround time = %.2f\n", ((double)f::mncost(S, T))/m);
		for(int a=0;a<m;a++){
			int id = n*m + a;
			debug("a %d\n", a);
			for(int nxt=f::es[id];nxt != -1;nxt = f::nx[nxt]){
				if(f::fl[nxt] > 0){
					debug("id %d fl[%d] %d to %d\n", id, nxt, f::fl[nxt], f::to[nxt]);
					int idd = f::to[nxt]/m;
					int pos = m - 1 - f::to[nxt]%m;
					debug("on idd %d on %d-th pos\n", idd, pos);
					//id runs on idd on pos-th
					q[idd][pos] = a;
					on[a] = idd;
					cust[a] = f::ori[nxt];
					debug("ori c %d\n", f::ori[nxt]);
				}
			}
		}
		for(int a=0;a<n;a++){
			int tempo = 0;
			debug("a %d\n", a);
			for(int i=0;i<m;i++){
				if(q[a][i] == -1) continue;
				debug("tem[%d] = %d\n", q[a][i], tempo);
				tim[q[a][i]] = tempo;
				tempo += cust[q[a][i]];
			}
		}
		for(int a=0;a<m;a++)
			printf("Program %d runs in region %d from %d to %d\n", a+1, on[a]+1, tim[a], tim[a]+cust[a]);
		puts("");
	}
}
