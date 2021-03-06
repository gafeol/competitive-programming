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

const int MAXN = 52, MAXX = 10000001;

namespace f {

	const int N = MAXN*2 + 3, M = MAXN*8 +  MAXN*MAXN * 2;
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

	void init(int n = N) {
		en = 0;
		memset(es, -1, sizeof(int) * n);
	}

	val flow;
	num mncost(int s, int t) {
		tot = 0; flow = 0;
		while(val a = spfa(s, t)) flow += a;
		return tot;
	}

	void add_edge(int u, int v, val c, num s) {
		fl[en] = 0; cp[en] = c; to[en] = v; nx[en] = es[u]; cs[en] =  s; es[u] = en++;
		fl[en] = 0; cp[en] = 0; to[en] = u; nx[en] = es[v]; cs[en] = -s; es[v] = en++;
	}
}

int n, m, k;
int s[MAXN];
int sz[MAXN], bk[MAXN][MAXN];

int has[MAXX];


int main (){
	int tempo = 0;
	for_tests(t, tt){
		scanf("%d%d", &n, &m);
		f::init(n+m+3);
		int S = n + m;
		int T = S + 1;
		for(int a=0;a<n;a++)
			scanf("%d", s+a);
		for(int b=0;b<m;b++){
			int x;
			scanf("%d", &x);
			sz[b] = x;
			while(x--)
				scanf("%d", &bk[b][x]);
		}
		for(int j=0;j<m;j++){
			tempo++;
			int mid2 = (4 + 3*sz[j])/5;
			int mid = sz[j] - mid2;
			int sum;
			for(int bm=0;bm<(1<<mid2);bm++){
				sum = 0;
				for(int pos=0;pos<mid2;pos++)
					if(((1<<pos)&bm))
						sum += bk[j][pos+mid];	
				if(sum < MAXX){
					has[sum] = tempo;
				}
			}
			for(int i=0;i<n;i++){
				int ok = 0;

				for(int bm=0;bm<(1<<mid);bm++){
					sum = 0;
					for(int pos=0;pos<mid;pos++){
						if(((1<<pos)&bm))
							sum += bk[j][pos];
					}
					if(s[i] - sum >= 0 && has[s[i] - sum] == tempo){
						ok = 1;
						break;
					}
				}

				if(ok)
					f::add_edge(i, j+n, 1, -s[i]);
			}
		}
		for(int a=0;a<n;a++){
			f::add_edge(S, a, 1, 0);
			f::add_edge(a, T, 1, 0);
		}
		for(int a=0;a<m;a++)
			f::add_edge(a+n, T, 1, 0);
		printf("%d\n", -f::mncost(S, T));
	}
}
