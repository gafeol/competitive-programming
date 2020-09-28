#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;

const int base = 1000000000;
const int base_digits = 9;

const int K = 2;

struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
    ull q;

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t;

int add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - '0';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
    return v;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - '0';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

const int MAXN = 21234;

map<string, int> fim;

ull soma(int v, ull x){
    if(v == -1) return ull(0);
    if(v == 0 || t[v].leaf){
        t[v].q = ull(x);
        t[v].q -= soma(t[v].next[0], x/2);
        t[v].q -= soma(t[v].next[1], x/2);
        return x;
    }
    else{
        t[v].q = soma(t[v].next[0],x/2);
        t[v].q += soma(t[v].next[1],x/2);
        return t[v].q;
    }
}

int main (){
    int n, m, k;
    while(scanf("%d%d", &n, &k) != EOF && n + k > 0){
        t.clear();
        t.emplace_back();

        fim.clear();
        fim[""] = 0;
        for(int i=0;i<n;i++){
            char pal[MAXN];
            scanf(" %s", pal);
            int sz = strlen(pal);
            pal[sz-1] = '\0';
            assert(strlen(pal) == sz-1);
            fim[pal] = add_string(pal);
        }

        ull x = ull(1);
        while(k--){
            x *= 2ll;
        }
        soma(0, x);
        scanf("%d", &m);
        for(int a=0;a<m;a++){
            char pal[MAXN];
            scanf(" %s", pal);
            int sz = strlen(pal);
            pal[sz-1] = '\0';
            assert(strlen(pal) == sz-1);
            cout << t[fim[pal]].q;
            puts("");
        }
        puts("");
    }
}
