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

const int MAXN = 212345;

int n, k;
int s[MAXN];

struct nd {
    int bm;
    map<int, int> adj;
} root;

vector<nd> trie;

int go(int u, int x){
   if(trie[u].adj.find(x) == trie[u].adj.end()){
       trie.pb(nd());
       trie[u].adj[x] = trie.size()-1;
   }
   return trie[u].adj[x];
}

void add(int bm, vector<int> &v){
    int u = 0;
    for(int x: v){
        u = go(u, x); 
        trie[u].bm = bm;
    }
}

bool has(int u, int x){
    return (trie[u].adj.find(x) != trie[u].adj.end());
}

int qry(vector<int> &v){
    /*
    debug("qry ");
    for(int x: v)
        debug("%d ", x);
    debug("\n");
    */
    int u = 0;
    for(int x: v){
        if(!has(u, x))
            return -1;
        u = go(u, x);
    }
    return trie[u].bm;
}

int main (){
    trie.pb(nd());
	scanf("%d", &n);
	for(int a=0;a<n;a++)
        scanf("%d", s+a);
    int mask = (1<<15)-1;
    for(int bm=0;bm<(1<<15);bm++){
        vector<int> v;
        int fst;
        for(int a=0;a<n;a++){
            int val = __builtin_popcount((s[a]&mask)^bm);
            if(a == 0)
                fst = val;
            else
                v.pb(fst - val);
        }
        add(bm, v);
    }
    for(int bm=0;bm<(1<<15);bm++){
        vector<int> v;
        int fst;
        for(int a=0;a<n;a++){
            int val = __builtin_popcount((s[a]>>15)^bm);
            if(a == 0)
                fst = val;
            else
                v.pb(val - fst);
        }
        int o = qry(v);
        if(o != -1){
            printf("%d\n", (o|(bm << 15)));
            return 0;
        }
    }
    puts("-1");
}

