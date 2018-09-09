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

const int MAXN = 255;

int n, m, k;
int ne[2];
pii s[2][MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

namespace f {
	const int maxv = MAXN * 2 + 2;
	const int maxe =  (MAXN * MAXN + MAXN*2)* 2;
	typedef int num;
	num inf = INT_MAX;
	int n = maxv;

	int to[maxe], en, nx[maxe], es[maxe], lv[maxv], qu[maxv], cr[maxv];
	num cp[maxe], fl[maxe];


	bool bfs(int s, int t) {
		memset(lv, -1, sizeof(int) * n);
		lv[s] = 0;
		int a = 0, b = 0;
		qu[b++] = s; cr[s] = es[s];
		while(a < b) {
			for(int i = es[qu[a]]; i != -1; i = nx[i]) {
				if(cp[i] > fl[i] && lv[to[i]] == -1) {
					lv[to[i]] = lv[qu[a]] + 1;
					qu[b++] = to[i];
					cr[to[i]] = es[to[i]];
					if(to[i] == t) return true;
				}
			}
			a++;
		}
		return false;
	}

	num dfs(int u, int t, num mx) {
		if(u == t) return mx;
		for(int &i = cr[u]; i != -1; i = nx[i])
			if(cp[i] > fl[i] && lv[to[i]] == lv[u] + 1)
				if(num a = dfs(to[i], t, min(mx, cp[i] - fl[i]))) {
					fl[i] += a;
					fl[i ^ 1] -= a;
					return a;
				}
		return 0;
	}


	num max_flow(int s, int t) {
		num fl = 0, a;
		while(bfs(s, t))
			while(a = dfs(s, t, inf))
				fl += a;
		return fl;
	}

	void reset_all(int n2=maxv) { n = n2; en = 0; memset(es, -1, sizeof(int) * n); }
	void reset_flow() { memset(fl, 0, sizeof(num) * en); }

	void add_edge(int a, int b, num c, num rc=0) {
		fl[en] = 0; to[en] = b; cp[en] = c;  nx[en] = es[a]; es[a] = en++;
		fl[en] = 0; to[en] = a; cp[en] = rc; nx[en] = es[b]; es[b] = en++;
	}
}

ll dist(pii u, pii v){
	return abs((ll)u.fst - v.fst) + abs((ll)u.snd - v.snd);
}

bool go(ll d){
	f::reset_all();
	int S = n + n;
	int T = S+1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dist(s[0][i], s[1][j]) <= d)
				f::add_edge(i, n+j, 1);
		}
	}
	for(int i=0;i<n;i++)
		f::add_edge(S, i, 1);
	for(int j=0;j<n;j++)
		f::add_edge(n + j, T, 1);
	return (f::max_flow(S, T) == n);
}

int main (){
	scanf("%d", &n);
	for(int t=0;t<2;t++){
		for(int a=0;a<n;a++){
			scanf("%d %d", &s[t][a].fst, &s[t][a].snd);
		}
	}
	ll i = 0, j = 800000009;
	while(i < j){
		ll m = (i + j)/2ll;
		if(go(m))
			j = m;
		else
			i = m+1;
	}
	printf("%lld\n", i);
}
