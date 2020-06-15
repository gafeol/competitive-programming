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

const int MAXN = 45;
char M[MAXN][MAXN];

namespace f {
	const int maxv = 35*35*2*2;
	const int maxe = maxv * 6 * 2;
	typedef ll num;
	num inf = LLONG_MAX;
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

int n, m, k;
int s[MAXN];


int in(int i,int j){
    return 2*(i*m + j);
}

int out(int i, int j){
    return in(i, j) + 1;
}

bool valid(int i, int j){
    return (i>=0 && j>=0 && i < n && j < m);
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
    swap(n, m);
    f::reset_all();
    int S = 2*n*m;
    int T = S + 1;
	for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            scanf(" %c", &M[a][b]);
        }
	}
    for(int a=0;a<k;a++)
        scanf("%d", s+a);
    for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            int cus = INT_MAX;
            if(M[a][b] != '.' && M[a][b] != 'B')
                cus = s[M[a][b]-'a'];
            if(M[a][b] == 'B')
                f::add_edge(S, in(a, b), cus);
            f::add_edge(in(a, b), out(a, b), cus);
            int vi[] = {0, 0, -1, 1};
            int vj[] = {1, -1, 0, 0};
            for(int d=0;d<4;d++){
                int aa = a + vi[d], bb = b + vj[d];
                if(valid(aa, bb))
                    f::add_edge(out(a, b), in(aa, bb), INT_MAX);
                else
                    f::add_edge(out(a, b), T, INT_MAX);
            }
        }
    }
    ll ans = f::max_flow(S, T);
    if(ans >= (ll)INT_MAX)
        puts("-1");
    else
        printf("%lld\n", ans);
}

