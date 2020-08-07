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

const int MAXN = 512;

namespace f {
    const int N = MAXN*2 + 3, M = (MAXN*5)* 2;
    typedef int val;
    typedef int num;
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

    void init(int n) {
        en = 0;
        memset(es, -1, sizeof(int) * n);
    }

    val flow;
    pair<num, val> mncost(int s, int t) {
        tot = 0; flow = 0;
        while(val a = spfa(s, t)) flow += a;
        return {tot, flow};
    }

    void add_edge(int u, int v, val c, num s) {
        fl[en] = 0; cp[en] = c; to[en] = v; nx[en] = es[u]; cs[en] =  s; es[u] = en++;
        fl[en] = 0; cp[en] = 0; to[en] = u; nx[en] = es[v]; cs[en] = -s; es[v] = en++;
    }
}

int n, x, y;
int s[MAXN];
vector<int> adj[MAXN];
vector<int> inv[MAXN];
int cp[MAXN]; 
bool mrk[MAXN];


void go(int u, int p){
    if(u != p && mrk[u] == false)
        f::add_edge(p, u, f::infv, 0);
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        go(nxt, u);
    }
}

void rev(int u, int p){
    if(u != p && mrk[u] == false)
        f::add_edge(u+n, p+n, f::infv, 0);
    for(int nxt: inv[u]){
        if(nxt == p) continue;
        rev(nxt, u);
    }
}

int pass(int u, int p){
    int sum = 0;    
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        sum += pass(nxt, u);
    }
    if(cp[u] != 0)
        cp[u] -= sum;
    return cp[u] + sum;
}

int ipass(int u, int p){
    int sum = 0;    
    for(int nxt: inv[u]){
        if(nxt == p) continue;
        sum += ipass(nxt, u);
    }
    if(cp[u] != 0)
        cp[u] -= sum;
    return cp[u] + sum;
}

int main (){
	scanf("%d%d%d", &n, &x, &y);
    x--;y--;
    f::init(2*n + 5);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
	}
    for(int a=0;a<n-1;a++){
        int i,j;
        scanf("%d%d", &i, &j);
        i--;j--;
        adj[i].pb(j);
        adj[j].pb(i);
    }
    int S = 2*n;
    int T = S + 1;

    for(int a=0;a<n-1;a++){
        int i,j;
        scanf("%d%d", &i, &j);
        i--;j--;
        inv[i].pb(j);
        inv[j].pb(i);
    }
    for(int a=0;a<n;a++)
        f::add_edge(a, a+n, 1, -s[a]);

    int q;
    int tot = 0;
    scanf("%d", &q);
    for(int a=0;a<q;a++){
        int u, k;
        scanf("%d%d", &u, &k);
        u--;
        if(u == x)
            tot = k;
        cp[u] = k;
        mrk[u] = true;
    }
    pass(x, x);
    go(x, x);
    for(int a=0;a<n;a++){
        //printf("cp[%d] %d\n", a, cp[a]);
        if(cp[a] > 0)
            f::add_edge(S, a, cp[a], 0);
        else if(cp[a] < 0){
            puts("-1");
            return 0;
        }
        cp[a] = 0;
        mrk[a] = false;
    }

    scanf("%d", &q);
    for(int a=0;a<q;a++){
        int u, k;
        scanf("%d%d", &u, &k);
        u--;
        if(u == y)
            tot = max(tot, k);
        cp[u] = k;
        mrk[u] = true;
    }
    ipass(y, y);
    rev(y, y);
    for(int a=0;a<n;a++){
        //printf("invcp[%d] %d\n", a, cp[a]);
        if(cp[a] > 0)
            f::add_edge(a+n, T, cp[a], 0);
        else if(cp[a] < 0){
            puts("-1");
            return 0;
        }
    }


    pii ans = f::mncost(S, T);
    //printf("ans.fst %d snd %d\n", ans.fst, ans.snd);
    if(ans.snd == tot)
        printf("%d\n", -ans.fst);
    else
        puts("-1");
}

