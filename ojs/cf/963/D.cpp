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

int n, m, k;
char s[MAXN];

vector<int> occ[MAXN];

const int K = 26;
const char base = 'a'; // aresta vai ser char

struct Vertex {
    int next[K]; // arestas reais
    bool leaf = false;
    int id=-1;
    int cntLeaf = 0;
    int p = -1;
    char pch;
    int link = -1; // Calculado de forma lazy, tem que chamar get_link pra calcular
    int endLink = -1;
    int go[K]; // arestas reais + do automato

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

int add_string(string const& s, int id) {
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
    assert(t[v].id == -1);
    t[v].id = id;
    t[v].cntLeaf++;
    return v;
}

int go(int v, char ch);

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

int main (){
    scanf(" %s", s);
	scanf("%d", &n);
    vector<int> k(n), sz(n);
	for(int a=0;a<n;a++){
        char pal[MAXN];
        scanf("%d %s", &k[a], pal);
        sz[a] = strlen(pal);
        add_string(pal, a);
	}
    int u = 0;
    int i = 0;
    int tam = strlen(s);
    while(i < tam){
        u = go(u, s[i]);
        get_link(u);
        int v = (t[u].leaf ? u : t[u].endLink);
        while(v > 0){
            occ[t[v].id].pb(i);
            v = t[v].endLink;
        }
        i++;
    }

    for(int a=0;a<n;a++){
        sort(occ[a].begin(), occ[a].end());
        //printf("qry %d occ sz %d:\n", (int)occ[a].size());
        //for(int x: occ[a])
            //printf("%d ", x);
        //puts("");
        int ans = INT_MAX;
        for(int i=0;i+k[a]-1<occ[a].size();i++){
            ans = min(ans, occ[a][i+k[a]-1] - occ[a][i] + sz[a]);
        }
        if(ans == INT_MAX)
            puts("-1");
        else
            printf("%d\n", ans);
    }
}

