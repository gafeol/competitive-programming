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

const int MAXN = 6123;

namespace f {
	const int maxv = 2*MAXN;
	const int maxe =  (MAXN*4)* 2;
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

int n, m, k;
int s[MAXN];

pii ar[MAXN];
int deg[MAXN];
int ans[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d%d%d", &n, &m, &k);
        f::reset_all(n + m + 5);
        for(int a=0;a<n;a++)
            deg[a] = 0;
        for(int a=0;a<m;a++){
            ans[a] = 0;
        }
        int S = n+m;
        int T = S+1;
        for(int a=0;a<m;a++){
            int u, v;
            scanf("%d%d", &u, &v);
            u--;
            v--;
            deg[u]++;deg[v]++;
            ar[a] = {u, v};
            f::add_edge(u, a+n, 1);
            f::add_edge(v, a+n, 1);
            f::add_edge(a+n, T, 1);
        }
        bool ok = true;

        int fl = 0;
        for(int a=0;a<n;a++){
            if(k*2 < deg[a])
                goto fim;
            if(k < deg[a]){
                f::add_edge(S, a, 2*(deg[a] - k));
                fl += 2*(deg[a] - k);
            }
        }
        if(ok && f::max_flow(S, T) == fl){
            int degans = 1;
            for(int u=0;u<n;u++){
                if(k >= deg[u])
                    continue; 
                int lst = -1;
                for(int i=f::es[u];i != -1;i = f::nx[i]){
                    if(f::to[i] >= n && f::to[i] < S && f::fl[i] == 1){
                        if(lst != -1){
                            ans[f::to[i]-n] = ans[f::to[lst]-n] = degans++;
                            lst = -1;
                        }
                        else{
                            lst = i;
                        }
                    }
                }
                assert(lst == -1);
            }
            for(int a=0;a<m;a++){
                if(ans[a] == 0){
                    ans[a] = degans++;
                }
            }
        }

fim:
        for(int a=0;a<m;a++){
            if(!ok) ans[a] = 0;
            printf("%d%c", ans[a], " \n"[a==m-1]);
        }
    }
}

