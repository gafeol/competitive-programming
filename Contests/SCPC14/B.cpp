#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
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

const int MAXN = 2123;

struct Vertex {
    unordered_map<int, int> next; // arestas reais
    int cntLeaf = 0;
    int p = -1;
    char pch;
    int link = -1; // Calculado de forma lazy, tem que chamar get_link pra calcular
    unordered_map<int, int> go; // arestas reais + do automato

    Vertex(int p=-1, int ch=INT_MIN) : p(p), pch(ch) {}
};

vector<Vertex> t;

inline void add_string(vector<int>& s) {
    /*
    puts("add");
    for(int x: s)
        printf("%d ", x);
    puts("");
    */

    int v = 0;
    for (int i=0;i<s.size();i++) {
        int c = s[i];
        if (t[v].next.find(c) == t[v].next.end()) {
            t[v].next[c] = t.size();
            t.emplace_back(v, s[i]);
        }
        v = t[v].next[c];
    }
    t[v].cntLeaf++;
}

int go(int v, int ch);

// So chamar depois que todas strings estiverem na trie
int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0){
            t[v].link = 0;
        }
        else{
            t[v].link = go(get_link(t[v].p), t[v].pch);
            get_link(t[v].link);
            t[v].cntLeaf += t[t[v].link].cntLeaf;
        }
    }
    return t[v].link;
}

int go(int v, int ch) {
    int c = ch;
    if (t[v].go.find(c) == t[v].go.end()) {
        if (t[v].next.find(c) != t[v].next.end())
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

int n;
ll k;

vector<int> pal;

int s[4][MAXN];

int main (){
    for_tests(nt, tt){
        t.clear();
        t.emplace_back();
        scanf("%d", &n);
        ll sum = 0;
        for(int b=0;b<4;b++){
            for(int a=0;a<n;a++){
                scanf("%d", &s[b][a]);
                sum += s[b][a];
            }
        }
        printf("Case %d: ", tt);
        if(sum%n){
            puts("No");
            continue;
        }
        bool ok = false;
        k = sum/n;
        pal.resize(n);
        for(int inij=0;inij<n;inij++){
            bool valid = true;
            for(int i=0;i<n;i++){
                int j = (i + inij)%n;
                pal[i] = k - (s[2][i] + s[3][j]);
                if(pal[i] <= 0){
                    valid = false;
                    break;
                }
            }
            if(valid)
                add_string(pal);
        }
        pal.resize(2*n);
        for(int inij=0;inij<n && !ok;inij++){
            bool valid = true;
            for(int i=0;i<n;i++){
                int j = (i + inij)%n;
                pal[i+n] = pal[i] = s[0][i] + s[1][j];
                if(pal[i] >= k)
                    valid = false;
            }
            if(!valid)
                continue;

            /*
            puts("qry");
            for(int a=0;a<n;a++){
                printf("%d ", pal[a]);
            }
            puts("");
            */
            int u = 0;
            for(int a=0;a<2*n;a++){
                u = go(u, pal[a]);
                get_link(u);
                if(t[u].cntLeaf){
                    ok = true;
                    break;
                }
            }
        }
        if(ok)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
