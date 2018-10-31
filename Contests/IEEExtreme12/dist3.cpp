#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)

template <typename T> void write(ostream& out, T t) {
	out << t << "\n";
}
template <typename T, typename... Args>
void write(ostream& out, T t, Args... args) {
	out << t << ' ';
	write(out, args...);
}

template <typename... Args>
void debug(Args... args) {
	#ifdef LOCAL
		write(cerr, args...);
	#endif
}


template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 312345;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

namespace f {

const int N = MAXN + 200000, M = MAXN*2 * 2;
typedef int val;
typedef ll num;
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

void init(int n=N) {
	en = 0;
	memset(es, -1, sizeof(int) * n);
}

val flow;
num mncost(int s, int t) {
	tot = 0; flow = 0;
	while(val a = spfa(s, t)) flow += a;
	//printf("FLOW %lld\n", flow);
	//printf("cus %d\n", tot);
	return tot;
}

void add_edge(int u, int v, val c, num s) {
	//printf("liga %d %d com cap %lld cus %lld\n", u, v, c, s);
	fl[en] = 0; cp[en] = c; to[en] = v; nx[en] = es[u]; cs[en] =  s; es[u] = en++;
	fl[en] = 0; cp[en] = 0; to[en] = u; nx[en] = es[v]; cs[en] = -s; es[v] = en++;
}
}

set<int> fr;
int mrk[MAXN];

int has[MAXN];

int cs(int x, int i){
	if(x == 0) return 0;
	return abs(x - i);
}

int main (){
	scanf("%d", &n);
	if(n< 1000){
		for(int a=0;a<n;a++){
			scanf("%d", s+a);
			s[a] += n/2+1;
			mrk[s[a]]++;
		}
		f::init();
		int S = 2*n + 3, T = S + 1;
		for(int a=0;a<=2*n+2;a++){
			if(mrk[a] >= 1){
				f::add_edge(S, a, mrk[a], 0ll);
			}
			f::add_edge(a, T, 1, 0ll);
			if(a > 0)
				f::add_edge(a, a-1, n, 1ll);
			if(a < 2*n+2)
				f::add_edge(a, a+1, n, 1ll);
		}
		printf("%lld\n", f::mncost(S, T));
	}
	else{
		clock_t clk = clock();


		for(int a=0;a<n;a++){

			scanf("%d", s+a);

			s[a] += 3*n;

			mrk[s[a]]++;

		}

		sort(s, s+n);

		for(int a=0;a<5*n;a++){

			if(!mrk[a])

				fr.insert(a);

			else{

				while(mrk[a] > 1){

					int pos = *fr.rbegin();

					has[pos] = a;

					fr.erase(pos);

					mrk[a]--;

				}

				has[a] = a;

			}

		}

		ll res = 0;

		for(int a=0;a<5*n;a++){

			if(has[a]){

				int pos = *fr.upper_bound(has[a]);

				if(abs(pos - has[a]) <  abs(has[a] - a)){

					has[pos] = has[a];

					has[a] = 0;

					fr.erase(pos);

					fr.insert(a);

				}

			}

		}

		srand(time(NULL));

		while(((double)clock() - clk)/CLOCKS_PER_SEC < 0.8){

			int a = rand()%(5*n);

			int b = rand()%(5*n);

			if(cs(has[a], b) + cs(has[b], a) < cs(has[a], a) + cs(has[b], b))

				swap(has[a], has[b]);

		}



		for(int a=0;a<5*n;a++){

			if(!has[a]) continue;

			res += (ll)abs(has[a] - a);

		}

		printf("%lld\n", res);
	}
}

