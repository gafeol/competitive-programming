#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

const int MAXN = 1003;

const int K = 26;
const char base = 'a'; 

struct Vertex {
    int next[K]; // arestas reais
    bool leaf = false;
    int cntLeaf = 0;
    int p = -1;
    char pch;
    int link = -1; // Calculado de forma lazy, tem que chamar get_link pra calcular
    int go[K]; // arestas reais + do automato
    ll val = 0;

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

Vertex t[300000];
int ttam;

void add_string(string const& s, ll val) {
    int v = 0;
    for (char ch : s) {
        int c = ch - base;
        if (t[v].next[c] == -1) {
            t[v].next[c] = ttam;
            t[ttam++] = Vertex(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
    t[v].cntLeaf++;
    t[v].val += val;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else{
            t[v].link = go(get_link(t[v].p), t[v].pch);
            get_link(t[v].link);
            t[v].cntLeaf += t[t[v].link].cntLeaf;
            t[v].val += t[t[v].link].val;
        }
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - base;
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

int n, m, k;
char s[2][MAXN];
int tam[2];

ll dp[2][MAXN][MAXN];
unordered_map<int, unordered_map<int, ll>> dp2;

ll go(int tp, int i, int j, int u){
    ll r = dp[tp][i][j];
    if(r != -1)
        return r;
    if(tp && dp2[j].find(u) != dp2[j].end()){
        return r = dp2[j][u];
    }
    r = 0;
    if(tp == 0){
        r = max(r, go(1, i, j, u));
        if(i < tam[0]){
            int nu = go(u, s[0][i]);
            get_link(nu);
            r = max(r, go(tp, i+1, j, nu) + t[nu].val);
        }
    }
    else{
        if(j < tam[1]){
            int nu = go(u, s[1][j]);
            get_link(nu);
            r = max(r, go(tp, i, j+1, nu) + t[nu].val);
        }
    }
    if(tp) dp2[j][u] = r;

    return r;
}

int main (){
    for_tests(nt, tt){
        dp2.clear();
        t[0] = Vertex();
        ttam = 1;
        scanf(" %s", s[0]);
        tam[0] = strlen(s[0]);
        scanf(" %s", s[1]);
        tam[1] = strlen(s[1]);
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            char pal[30];
            ll val;
            scanf(" %s %lld", pal, &val);
            add_string(pal, val);
        }
        for(int tp=0;tp<2;tp++){
            for(int i=0;i<=tam[0];i++){
                for(int j=0;j<=tam[1];j++){
                    dp[tp][i][j] = -1;
                }
            }
        }
        ll ans = 0;
        for(int fim = 0;fim<=tam[1];fim++)
            ans = max(ans, go(0, 0, fim, 0));
        printf("%lld\n", ans);
    }
}
