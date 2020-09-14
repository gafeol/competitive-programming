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

const int MAXN = 212;

namespace f {
	const int maxv = 200*200*2 + 10;
	const int maxe = maxv*4 * 2;
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

	void add_edge(int a, int b, num c=1, num rc=0) {
        if(a == -1 || b == -1) return;
		fl[en] = 0; to[en] = b; cp[en] = c;  nx[en] = es[a]; es[a] = en++;
		fl[en] = 0; to[en] = a; cp[en] = rc; nx[en] = es[b]; es[b] = en++;
	}
}

int n, m, k;

char M[MAXN][MAXN];

bool valid(int i, int j){
    return (i >= 0 && j >= 0 && i < n && j < m && M[i][j] == '#');
}

int cnt;
map<pii, map<pii, int>> idp;

int id(int i, int j, int ii, int jj){
    if(!valid(i, j) || !valid(ii, jj))
        return -1;
    if(ii < i){
        swap(i, ii);
        swap(j, jj);
    }
    if(jj < j){
        swap(i, ii);
        swap(j, jj);
    }            
    if(idp[{i, j}].find({ii, jj}) == idp[{i, j}].end())
        idp[{i, j}][{ii, jj}] = cnt++;
    return idp[{i, j}][{ii,jj}];
}

int main (){
    cnt = 0;
    f::reset_all();
	scanf("%d%d", &n, &m);
    int ans = 0;
	for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            scanf(" %c", &M[a][b]);
            ans += (M[a][b] == '#');
        }
	}
    int vi[] = {-1, 0, 1, 0};
    int vj[] = {0, 1, 0, -1}; 
    vector<int> s[2];
    for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            vector<int> ind(4);
            for(int d=0;d<4;d++){
                ind[d] = id(a, b, a+vi[d], b+vj[d]);
                if(ind[d] != -1)
                    s[(d&1)].pb(ind[d]);
            }
            f::add_edge(ind[0], ind[1]);
            f::add_edge(ind[0], ind[3]);
            f::add_edge(ind[2], ind[1]);
            f::add_edge(ind[2], ind[3]);
        }
    }
    ans -= cnt;
    int S = cnt++;
    int T = cnt++;
    for(int t=0;t<2;t++){
        sort(s[t].begin(), s[t].end());
        s[t].erase(unique(s[t].begin(), s[t].end()), s[t].end());
    }
    for(int x: s[0])
        f::add_edge(S, x);
    for(int x: s[1])
        f::add_edge(x, T);
    printf("%d\n", ans + f::max_flow(S, T));
}

