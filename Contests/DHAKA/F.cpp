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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}


const int MAXN = 21234;
const int LOGN = 20;

int n, m, k;
vector<int> adj[MAXN];
int p[MAXN][LOGN], h[MAXN];

void go(int u, int pai=1){
    h[u] = h[pai]+1;
    p[u][0] = pai;
    for(int i=1;i<LOGN;i++){
        p[u][i] = p[p[u][i-1]][i-1];
    }
    for(int nxt: adj[u]){
        if(nxt == pai) continue;
        go(nxt, u);
    }
}

int lca(int u, int v){
    if(h[u] != h[v]){
        if(h[u] < h[v]) swap(u, v);
        for(int i=LOGN-1;i>=0;i--){
            if(h[p[u][i]] > h[v])
                u = p[u][i];
        }
        u = p[u][0];
    }
    if(u == v)
        return u;
    for(int i=LOGN-1;i>=0;i--){
        if(p[u][i] != p[v][i]){
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}

// u anc ou igual a v
bool isAnc(int u, int v){
    return (h[u] <= h[v] && lca(u, v) == u);
}

bool isIn(int u, int a, int b){
    assert(h[a] >= h[b] && isAnc(b, a));
    return (isAnc(b, u) && isAnc(u, a));
}

tuple<int, int> inter(tuple<int, int> tp,  tuple<int, int> tpp){
    int u, uu, v, vv;
    tie(u, uu) = tp;
    tie(v, vv) = tpp;
    if(u == uu){
        if(isIn(u, v, vv))
            return {u, u};
        else
            return {-2, -2};
    }
    if(v == vv){
        if(isIn(v, u, uu))
            return {v, v};
        else
            return {-2, -2};
    }
    int topo = (h[uu] > h[vv] ? uu: vv);
    if((v != uu && isAnc(v, uu)) || (u != vv && isAnc(u, vv)))
        return {-2, -2};

    if(!isAnc(topo, u) || !isAnc(topo, v))
        return {-2, -2};

    int base = lca(u, v);
    if(isAnc(topo, base))
        return make_tuple(base, topo);
    else
        return make_tuple(-2, -2);

}

int sz(tuple<int, int> pth){
    int u, uu;
    tie(u, uu) = pth;
    if(u == -2) return 0;
    assert(isAnc(uu, u));
    return h[u] - h[uu] + 1;
}

int main (){
    int t = readInt(), tt = 0;
    while(tt++ < t){
        int n = readInt(); 
        for(int a=0;a<=n;a++)
            adj[a].clear();
        for(int a=1;a<n;a++){
            int u = readInt();
            int v = readInt();
            adj[u].pb(v);
            adj[v].pb(u);
        }
        h[1] = 0;
        go(1);
        printf("Case %d:\n", tt);
        int m = readInt();
        for(int a=0;a<m;a++){
            int k = readInt();
            /// h[U] > h[V]
            vector<tuple<int, int>> pths, novo;
            bool fst = true;
            for(int i=0;i<k;i++){
                int u = readInt();
                int v = readInt();
                if(h[u] < h[v]) swap(u, v);
                int lc = lca(u, v);
                novo.clear();
                if(lc == v)
                    novo.pb({u, v});
                else{
                    novo.pb({u, lc});
                    novo.pb({v, lc});
                }
                if(fst){
                    pths = novo;
                    /*printf("inicialmente pths:\n");
                    for(tuple<int, int> tp: pths){
                        int u, uu;
                        tie(u, uu) = tp;
                        printf("pths %d %d\n", u, uu);
                    }
                    printf("fim paths\n");
                    */
                    fst = false;
                }
                else{
                    vector<tuple<int, int>> aux;
                    for(tuple<int, int> tp: pths){
                        vector<tuple<int, int>> novotp;
                        for(tuple<int, int> ntp: novo){
                            tuple<int, int> auxtp = inter(tp, ntp);
                            if(get<0>(auxtp) != -2)
                                novotp.pb(auxtp);
                        }
                        if(novotp.size() > 1){
                            if(sz(novotp[0]) > sz(novotp[1]))
                                aux.pb(novotp[0]);
                            else
                                aux.pb(novotp[1]);
                        }
                        else if(!novotp.empty())
                            aux.pb(novotp[0]);
                    }
                    pths = aux;
                }
            }
            int ans = 0;
            for(tuple<int, int> tp: pths){
                int u, uu;
                tie(u, uu) = tp;
                //printf("pths %d %d\n", u, uu);
                ans += sz(tp);
            }
            assert(pths.size() < 3);
            if(pths.size() > 1){
                tuple<int, int> tp = inter(pths[0], pths[1]);
                int u, uu;
                tie(u, uu) = tp;
                //printf("inter pths %d %d\n", u, uu);
                ans -= sz(tp); 
            }
            printf("%d\n", ans);
        }
    }
}
