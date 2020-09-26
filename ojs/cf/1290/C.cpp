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

const int MAXN = 312345;

int n, m, k;
int s[MAXN];

int p[MAXN], sz[MAXN];
vector<int> comp[MAXN];
int c[MAXN][2], state[MAXN];
vector<int> over[MAXN];

int ans;

int raiz(int u){
    if(p[u] == u) return u;
    return p[u] = raiz(p[u]);
}

void inv(int r){
    for(int ov: comp[r]){
        state[ov] ^= 1;
    }
    swap(c[r][0], c[r][1]);
}
int INF = 1e6;

void juntaIgual(int u, int v){
    debug("junta ig %d %d\n", u, v);
    int ru = raiz(u);
    int rv = raiz(v);

    if(ru == rv)
        return ;

    ans -= min(c[ru][0], c[ru][1]);
    ans -= min(c[rv][0], c[rv][1]);

    if(sz[ru] < sz[rv])
        swap(ru, rv);
    sz[ru] += sz[rv];
    p[rv] = ru;

    if(state[u] != state[v])
        inv(rv);

    for(int x: comp[rv])
        comp[ru].pb(x);
    comp[rv].clear();

    c[ru][0] += c[rv][0];
    c[ru][0] = min(c[ru][0], INF);
    c[ru][1] += c[rv][1];
    c[ru][1] = min(c[ru][1], INF);
    ans += min(c[ru][0], c[ru][1]);
}

void juntaDif(int u, int v){
    debug("junta dif %d %d\n", u, v);
    int ru = raiz(u);
    int rv = raiz(v);

    if(ru == rv)
        return ;

    ans -= min(c[ru][0], c[ru][1]);
    ans -= min(c[rv][0], c[rv][1]);

    if(sz[ru] < sz[rv])
        swap(ru, rv);
    sz[ru] += sz[rv];
    p[rv] = ru;

    if(state[u] == state[v])
        inv(rv);

    for(int x: comp[rv])
        comp[ru].pb(x);
    comp[rv].clear();

    c[ru][0] += c[rv][0];
    c[ru][0] = min(c[ru][0], INF);
    c[ru][1] += c[rv][1];
    c[ru][1] = min(c[ru][1], INF);
    ans += min(c[ru][0], c[ru][1]);
}


void imp(int u, int s){
    // impossivel ru ser state 
    int ru = raiz(u);
    //printf("impossivel u %d s %d ru %d\n", u, s, ru);
    ans -= min(c[ru][0], c[ru][1]);
    c[ru][s] = INF;
    //printf("c[%d] %d %d\n", ru, c[ru][0], c[ru][1]);
    ans += min(c[ru][0], c[ru][1]);
}


int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        char c;
        scanf(" %c", &c);
        s[a] = c-'0';
	}
    for(int a=0;a<m;a++){
        int x;
        scanf("%d", &x);
        p[a] = a;
        sz[a] = 1;
        comp[a].pb(a);
        state[a] = 0;
        c[a][0] = 1;
        c[a][1] = 0;
        while(x--){
            int u;
            scanf("%d", &u);
            u--;
            over[u].pb(a);
        }
    }
    ans = 0;
    for(int i=0;i<n;i++){
        if(over[i].size() == 2){
            int u = over[i][0], v = over[i][1];
            if(s[i])
                juntaIgual(u, v);
            else
                juntaDif(u, v);
        }
        else if(over[i].size() == 1){
            int u = over[i][0];
            if(s[i])
                imp(u, state[u]);
            else
                imp(u, 1-state[u]);

        }
        printf("%d\n", ans);
    }
}
