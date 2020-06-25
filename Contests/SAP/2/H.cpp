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
inline int mx(int x) {
    return min(x, 2);
}

const int MAXN = 2123;

int n, m, k;

struct vtx{
    int adj[2];
    int fim;

    vtx() {
        adj[0] = adj[1] = -1;
        fim = 0;
    }
};

vector<vtx> trie;

int nxt(int u, int t){
    //assert(u < trie.size());
    //assert(t < 2);
    if(trie[u].adj[t] == -1){
        //printf("nao existe no em u %d c %d\n", u, t);
        trie[u].adj[t] = trie.size();
        //printf("criou %d\n", trie.size());
        trie.pb(vtx());
    }
    return trie[u].adj[t];
}

map<char, string> rep;
int tam;
char s[MAXN*22];
char ss[MAXN*22];
int dp[MAXN*22][30*22];

int go(int i, int u){
    if(u == -1) return 0;
    int &r = dp[i][u];
    if(r != -1)
        return r;
    if(i == tam)
        return r = mx(trie[u].fim);
    r = 0;
    r = mx(r + go(i+1, trie[u].adj[s[i]-'0']));
    if(trie[u].fim > 0)
        r = mx(r + trie[u].fim*go(i, 0));
    return r;
}

void add(string pal){
    int u = 0;
    for(char c: pal){
        u = nxt(u, c-'0');
    }
    trie[u].fim++;
}

int main (){
    trie.clear();
    trie.pb(vtx());
    memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        char pal[40], c;
        scanf(" %s %c", pal, &c);
        rep[c] = pal;
        add(pal);
	}
    scanf(" %s", ss);
    int sz = strlen(ss);
    tam = 0;
    for(int a=0;a<sz;a++){
        for(char c: rep[ss[a]]){
            s[tam++] = c;
        }
    }
    s[tam] = '\0';
    //printf("s %s\n", s);
    int nw = go(0, 0);
    assert(nw > 0);
    if(nw == 1)
        puts("No");
    else
        puts("Yes");
}

