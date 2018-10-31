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

const int MAXN = 2018;

namespace f {
	const int maxv = MAXN;
	const int maxe = maxv*4*2;
	typedef int num;
	num inf = INT_MAX;
	int n = maxv;
	int to[maxe], en, nx[maxe], es[maxe], lv[maxv], qu[maxv], cr[maxv];
	num cp[maxe], fl[maxe];

	bool bfs(int s, int t){
		memset(lv, -1, sizeof(int)*n);
		lv[s] = 0;
		int a = 0, b = 0;
		qu[b++] = s; cr[s] = es[s];
		while(a < b){
			for(int i=es[qu[a]];i != -1;i = nx[i]){
				if(cp[i] > fl[i] && lv[to[i]] == -1){
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

	num dfs(int u, int t, num mx){
		if(u == t) return mx;
		for(int &i=cr[u];i!=-1;i=nx[i])
			if(cp[i] > fl[i] && lv[to[i]] == lv[u] + 1)
				if(num a = dfs(to[i], t, min(mx, cp[i] - fl[i]))){
					fl[i] += a;
					fl[i^1] -= a;
					return a;
				}
		return 0;
	}

	num max_flow(int s, int t){
		num fl = 0, a;
		while(bfs(s, t))
			while(a = dfs(s, t, inf))
				fl += a;
		return fl;
	}

	void reset_all(int n2=maxv){
		n = n2;
		en = 0;
		memset(es, -1, sizeof(int)*n);
	}
	void reset_flow(){
		memset(fl, 0, sizeof(num)*en);
	}
	void add_edge(int a, int b, num c, num rc=0){
		fl[en] = 0; to[en] = b; cp[en] = c; nx[en] = es[a]; es[a] = en++;
		fl[en] = 0; to[en] = a; cp[en] = rc; nx[en] = es[b]; es[b] = en++;
	}
}


int n, m, k;
int s[MAXN];

map<int, map<int, int> > mrk;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int vi[] = {-1, 1, 0, 0};
int vj[] = {0, 0, 1, -1};

int main (){
	int n;
	while (scanf("%d", &n) != EOF) {
		f::reset_all();
		mrk.clear();
		int S = n, T = n+1;
		for(int a=0;a<n;a++){
			int i, j;
			scanf("%d %d", &i, &j);
			mrk[i][j] = a;
			int t = ((i+j)&1);
			for(int d=0;d<4;d++){
				int ii = i + vi[d];
				int jj = j + vj[d];
				if(mrk[ii].find(jj) != mrk[ii].end()){
					if(t)
						f::add_edge(a, mrk[ii][jj], 1);
					else
						f::add_edge(mrk[ii][jj], a, 1);
				}
			}
			if(t)
				f::add_edge(S, a, 1);
			else
				f::add_edge(a, T, 1);
		}

		printf("%d\n", n - f::max_flow(S, T));
	}
}

