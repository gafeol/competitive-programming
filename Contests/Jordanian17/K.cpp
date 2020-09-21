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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

typedef int val; // type of flow
typedef ll num; // type of cost
const int N = 260, M = (N*N + 2*N)* 2; const num eps = 0;
struct mcmf {
	int es[N], to[M], nx[M], en = 2, pai[N], seen[N], tempo, qu[N];
	val fl[M], cp[M], flow; num cs[M], d[N], tot;
	val spfa(int s, int t) {
		tempo++; int a = 0, b = 0;
		for(int i = 0; i < N; i++) d[i] = numeric_limits<num>::max();
		d[s] = 0; qu[b++] = s; seen[s] = tempo;
		while(a != b) {
			int u = qu[a++]; if(a == N) a = 0; seen[u] = 0;
			for(int e = es[u]; e; e = nx[e]) if(cp[e] - fl[e] > val(0) && d[u] + cs[e] < d[to[e]] - eps) {
				d[to[e]] = d[u] + cs[e]; pai[to[e]] = e ^ 1;
				if(seen[to[e]] < tempo) { seen[to[e]] = tempo; qu[b++] = to[e]; if(b == N) b = 0; }
			}
		}
		if(d[t] == numeric_limits<num>::max()) return false;
		val mx = numeric_limits<val>::max();
		for(int u = t; u != s; u = to[pai[u]])
			mx = min(mx, cp[pai[u] ^ 1] - fl[pai[u] ^ 1]);
		tot += d[t] * val(mx);
		for(int u = t; u != s; u = to[pai[u]])
			fl[pai[u]] -= mx, fl[pai[u] ^ 1] += mx;
		return mx;
	}
	// public $
	num min_cost(int s, int t) {
		tot = 0; flow = 0;
		while(val a = spfa(s, t)) flow += a;
		return tot;
	}
	void add_edge(int u, int v, val c, num s) {
		fl[en] = 0; cp[en] = c; to[en] = v; nx[en] = es[u]; cs[en] =  s; es[u] = en++;
		fl[en] = 0; cp[en] = 0; to[en] = u; nx[en] = es[v]; cs[en] = -s; es[v] = en++;
	}
	void reset_flow() { memset(fl, 0, sizeof(val) * en); }
	void init(int n) { en = 2; memset(es, 0, sizeof(int) * n); } // XXX must be called
};


int n, m, k;
ll s[MAXN];
ll lim[MAXN];

const ll INF = (ll)2e10;

int main (){
    freopen("threads.in", "r", stdin);
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        mcmf f;
        f.init(2*n + m  + 4);
        f.reset_flow();
        int S = 2*n + m;
        int T = S + 1;
        for(int a=0;a<m;a++){
            scanf("%lld", lim+a);
            f.add_edge(S, a + 2*n, 1, 0);
            f.add_edge(a + 2*n, T, 1, lim[a]);
        }
        for(int a=0;a<n;a++){
            f.add_edge(a*2, a*2+1, 1, -INF);
        }
        for(int a=0;a<n;a++){
            scanf("%lld", s+a);
        }
        for(int a=0;a<n;a++){
            for(int b=0;b<a;b++){
                if(s[a] > s[b]){
                    f.add_edge(a*2+1, b*2, 1, 0);
                }
            }
            for(int i=0;i<m;i++){
                if(lim[i] >= s[a]){
                    f.add_edge(i + 2*n, a*2, 1, lim[i] - s[a]);
                }
            }
            f.add_edge(a*2+1, T, 1, 0);
        }
        ll cst = f.min_cost(S, T) + n*INF;
        printf("%lld ", cst);
        f.init(2*n + m  + 4);
        f.reset_flow();
        for(int a=0;a<m;a++){
            f.add_edge(S, a + 2*n, 1, 0);
            f.add_edge(a + 2*n, T, 1, -lim[a]);
        }
        for(int a=0;a<n;a++)
            f.add_edge(a*2, a*2+1, 1, -INF);
        for(int a=0;a<n;a++){
            for(int b=0;b<a;b++){
                if(s[a] > s[b]){
                    f.add_edge(a*2+1, b*2, 1, 0);
                }
            }
            for(int i=0;i<m;i++){
                if(lim[i] >= s[a]){
                    f.add_edge(i + 2*n, a*2, 1, s[a] - lim[i]);
                }
            }
            f.add_edge(a*2+1, T, 1, 0);
        }
        cst = -(f.min_cost(S, T) + n*INF);
        printf("%lld\n", cst);
    }
}

