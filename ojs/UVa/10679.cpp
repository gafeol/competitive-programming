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

const int MAXN = 112345;

const int K = 2*26;

int val(char c){
    if(c >= 'a' && c <= 'z')
        return c - 'a';
    return 26 + c - 'A';
}

struct Vertex {
    int next[K]; // arestas reais
    bool leaf = false;
    int cntLeaf = 0;
    int p = -1;
    char pch;
    int link = -1; // Calculado de forma lazy, tem que chamar get_link pra calcular
    int go[K]; // arestas reais + do automato

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);
vector<bool> vis;

int add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = val(ch);
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
    t[v].cntLeaf++;
    return v;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else{
            t[v].link = go(get_link(t[v].p), t[v].pch);
            t[v].cntLeaf += t[t[v].link].cntLeaf;
        }
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = val(ch);
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

int n, m, k;
char s[MAXN];

void mrk(int u){
    if(u == 0 || vis[u]) return;
    vis[u] = true;
    mrk(get_link(u));
}

int main (){
    for_tests(nt, tt){
        t.clear();
        t.emplace_back();
        scanf(" %s", s);
        n = strlen(s);
        scanf("%d", &m);
        vector<int> q(m);
        for(int a=0;a<m;a++){
            char pal[1123];
            scanf(" %s", pal);
            q[a] = add_string(pal);
        }
        vis.clear();
        vis.resize(t.size(), 0);
        int u = 0, i = 0;
        vis[u] = 1;
        while(i < n){
            u = go(u, s[i]);
            mrk(u);
            i++; 
        }
        for(int a=0;a<m;a++){
            if(vis[q[a]])
                puts("y");
            else
                puts("n");
        }
    }
}
