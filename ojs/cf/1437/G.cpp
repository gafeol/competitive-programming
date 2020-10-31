#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
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

const int MAXN = 312345;

const int K = 26;
const char base = 'a'; // aresta vai ser char

struct Vertex {
    int next[K]; // arestas reais
    bool leaf = false;
    int cntLeaf = 0;
    int p = -1;
    char pch;
    int link = -1; // Calculado de forma lazy, tem que chamar get_link pra calcular
    int go[K]; // arestas reais + do automato
    int endLink = -1; // direto pro link que eh leaf mais proximo ou zero
    multiset<int> sus;

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

int add_string(string const& s) {
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
    t[v].sus.insert(0);
    t[v].cntLeaf++;
    return v;
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
string s[MAXN];

int node[MAXN];
int val[MAXN];

int main (){
    IOS();
    cin >> n >> m;
	for(int a=0;a<n;a++){
        cin >> s[a];
        node[a] = add_string(s[a]);
        val[a] = 0;
	}
    for(int a=0;a<m;a++){
        int tip;
        cin >> tip;
        if(tip == 1){
            int i, x;
            cin >> i >> x;
            i--;
            auto &q = t[node[i]].sus;
            q.erase(q.find(val[i]));
            val[i] = x;
            q.insert(val[i]);
        }
        else{
            string q;
            cin >> q;
            int ans = -1;
            int u = 0;
            for(int i=0;i<q.size();i++){
                u = go(u, q[i]); 
                //printf("i %d u %d\n", i, u);
                int dw = u;
                while(dw > 0){
                    //printf("dw %d\n", dw);
                    if(!t[dw].sus.empty())
                        ans = max(ans, *t[dw].sus.rbegin());
                    if(t[dw].link == -1)
                        get_link(dw);
                    dw = t[dw].endLink;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}

