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

const int MAXN = 412;

int n, m, k;
pii s[MAXN], h[MAXN];
int fo[MAXN], r[MAXN], nf[MAXN];

namespace f {
	const int maxv = MAXN + 100;
	const int maxe =  (410*110 + maxv)* 2;
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

int sq(int x){
    return x*x;
}

int dis(pii a, pii b){
    return sq(a.fst - b.fst) + sq(a.snd - b.snd);
}

bool in(int i, int j){
    return dis(s[i], h[j]) <= r[i]*r[i];   
}

int L(int i){
    return i;
}

int R(int i){
    return i+n;
}

int main (){
    for_tests(t, tt){
        f::reset_all();
        scanf("%d%d", &n, &m);
        int S = n+m;
        int T = S+1;
        for(int a=0;a<n;a++){
            scanf("%d%d%d%d", &s[a].fst, &s[a].snd, &fo[a], r+a);
        }
        int sum = 0;
        for(int a=0;a<m;a++){
            scanf("%d%d%d", &h[a].fst, &h[a].snd, &nf[a]);
            if(in(0, a)){
                fo[0] += nf[a];
            }
            else{
                int isin = 0;
                for(int i=1;i<n;i++){
                    if(in(i, a)){
                        isin = 1;
                        f::add_edge(L(i), R(a), nf[a]);
                    }
                }
                if(isin)
                    sum += nf[a];
            }
            f::add_edge(R(a), T, nf[a]);
        }
        int ok = 1;
        for(int a=1;a<n;a++){
            if(fo[a] > fo[0]){
                ok = 0;
                break;
            }
            f::add_edge(S, L(a), fo[0] - fo[a]);  
        }
        if(!ok || f::max_flow(S, T) != sum){
            puts("Lonesome Willy");
            continue;
        }
        else
            puts("Suiting Success");
        
    }
}

