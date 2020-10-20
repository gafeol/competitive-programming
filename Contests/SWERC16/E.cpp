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
const ll modn = 1000003;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

struct Vertex {
    map<char, int> next; // arestas reais
    bool leaf = false;
    int cntLeaf = 0;
    int p = -1;
    char pch;
    int link = -1; // Calculado de forma lazy, tem que chamar get_link pra calcular
    map<char, int> go; // arestas reais + do automato
    int endLink = -1; // direto pro link que eh leaf mais proximo ou zero

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) { }
};

vector<Vertex> t(1);

inline char simple(char c){
    if(c == '0')
        return 'o';
    else if(c == '1')
        return 'i';
    else if(c == '3')
        return 'e';
    else if(c == '5')
        return 's';
    else if(c == '7')
        return 't';
    if(isalpha(c))
        return tolower(c);
    return c;
}

void cleanString(string &s){
    for(int i=0;i<s.size();i++){
        s[i] = simple(s[i]); 
    }
}

void add_string(string &s) {
    cleanString(s);
    int v = 0;
    for (char c : s) {
        if (t[v].next.find(c) == t[v].next.end()) {
            t[v].next[c] = t.size();
            t.emplace_back(v, c);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
    t[v].cntLeaf++;
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

int go(int v, char c) {
    c = simple(c);
    if (t[v].go.find(c) == t[v].go.end()) {
        if (t[v].next.find(c) != t[v].next.end())
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), c);
    }
    return t[v].go[c];
} 

int n, m, k, L, R;
int tam; 
ll dp[22][1100][2][2][2];

ll solve(int i, int no, bool lo=false, bool up=false, bool dig=false){
    ll &r = dp[i][no][lo][up][dig];
    if(r != -1)
        return r;
    r = 0;
    if(i > tam || t[no].cntLeaf > 0)
        return r = 0;
    if(lo && up && dig)
        r = 1;
    for(char c='a';c<='z';c++)
        r = mod(r + solve(i+1, go(no, c), true, up, dig));
    for(char c='A';c<='Z';c++)
        r = mod(r + solve(i+1, go(no, c), lo, true, dig));
    for(char c='0';c<='9';c++)
        r = mod(r + solve(i+1, go(no, c), lo, up, true));
    return r;
}

void test(){
    assert(simple('1') == 'i');
    assert(simple('2') == '2');
    assert(simple('i') == 'i');
    assert(simple('I') == 'i');
    debug("tests ok\n");
}

int main (){
    //test();
	scanf("%d%d", &L, &R);
    scanf("%d", &n);
	for(int a=0;a<n;a++){
        char pal[22];
        scanf(" %s", pal);
        string p = pal;
        add_string(p);
    }

    for(int i=0;i<t.size();i++)
        get_link(i);

    memset(dp, -1, sizeof(dp));
    tam = R;
    ll ans = solve(0, 0);

    memset(dp, -1, sizeof(dp));
    tam = L-1;
    ans = mod(ans - solve(0, 0));

    ans = mod(ans + modn);
    printf("%lld\n", ans);
}

