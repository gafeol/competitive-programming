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

const int MAXN = 312;

int n, m, k;
char M[MAXN][MAXN];
int il[MAXN][MAXN];

namespace f {
	const int maxv = MAXN*MAXN*4;
	const int maxe =  (MAXN*MAXN + 2*MAXN)* 2;
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

int main (){
    for_tests(t, tt){
        f::reset_all();
        scanf("%d%d", &n, &m);
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                scanf(" %c", &M[a][b]);
            }
        }

        int S = 0, T = 1;
        int deg = 1;
        bool up = true;
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                if(M[a][b] == 'A')
                    up = true;
                if(M[a][b] != 'H')
                    continue;
                if(up){
                    deg++;
                    up = false;
                    f::add_edge(S, deg, 1);
                }
                il[a][b] = deg;
            }
            up = true;
        }

        up = true;
        for(int b=0;b<m;b++){
            for(int a=0;a<n;a++){
                if(M[a][b] == 'A')
                    up = true; 
                if(M[a][b] != 'H')
                    continue;
                if(up){
                    deg++;
                    up = false;
                    f::add_edge(deg, T, 1);
                }
                f::add_edge(il[a][b], deg, 1);
            }
            up = true;
        }
        printf("%d\n", f::max_flow(S, T));
    }
}
