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

const int MAXN = 1123;

char M[MAXN][MAXN];

const int K = 26;
const char base = 'A'; // aresta vai ser char
struct Vertex {
    int next[K]; // arestas reais
    bool leaf = false;
    int cntLeaf = 0;
    int p = -1;
    char pch;
    int link = -1; // Calculado de forma lazy, tem que chamar get_link pra calcular
    int go[K]; // arestas reais + do automato
    int endLink = -1; // direto pro link que eh leaf mais proximo ou zero
    vector<int> fim;

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s, int id) {
    int v = 0;
    for (char ch : s) {
        int c = ch - base;
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
    t[v].cntLeaf++;
    t[v].fim.pb(id);
}

int go(int v, char ch);

// So chamar depois que todas strings estiverem na trie
int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0){
            t[v].link = 0;
            t[v].endLink = 0;
        }
        else{
            t[v].link = go(get_link(t[v].p), t[v].pch);
            get_link(t[v].link); // tem que chamar pra calcular o cntLeaf de la tambem antes
            t[v].cntLeaf += t[t[v].link].cntLeaf;
            t[v].endLink = (t[t[v].link].leaf ? t[v].link : t[t[v].link].endLink);
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
int s[MAXN];
int vi[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int vj[] = {0,   1, 1, 1, 0, -1,-1,-1};

tuple<int, int, char> ans[MAXN];

bool valid(int i, int j){
    return (i >= 0 && j >= 0 && i < n && j < m);
}

vector<int> sz;

void solve(int i, int j, int d){
    int u = 0;
    vector<pii> steps;
    while(valid(i, j)){
        u = go(u, M[i][j]);
        steps.emplace_back(i, j);
        for(int id: t[u].fim){
            pii p = steps[steps.size()-sz[id]];
            ans[id] = {p.fst, p.snd, 'A' + d};
        }
        i += vi[d];
        j += vj[d];
    }
}

int main (){
    for_tests(tt, ttt){
        t.clear(); 
        t.resize(1);
        scanf("%d%d%d", &n, &m, &k);
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                scanf(" %c", &M[a][b]);
            }
        }
        sz.clear();
        sz.resize(k);
        for(int a=0;a<k;a++){
            char pal[MAXN];
            scanf(" %s", pal);
            sz[a] = strlen(pal);
            add_string(pal, a);
        }
        for(int d=0;d<8;d++){
            for(int i=0;i<n;i++){
                solve(i, 0, d);
                solve(i, m-1, d);
            }
            for(int j=0;j<m;j++){
                solve(0, j, d);
                solve(n-1, j, d);
            }
        }
        for(int a=0;a<k;a++){
            int i, j;
            char c;
            tie(i, j, c) = ans[a];
            printf("%d %d %c\n", i, j, c);
        }
    }
}

