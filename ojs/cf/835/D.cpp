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

const int MAXN = 5123;
const int LOGN = 20;

struct node{
    int sz;
    node *link;
    node *lt[LOGN];
    int occ = 0;
    int ind;
    int k = 0;
    map<char, node*> to;
    node() {}
    node(int sz, node* l): sz(sz), link(l) {}
};

vector<node*> nodes;
node *imp, *par;

struct pal_tree{  
    void init(){
        imp = new node(-1, NULL);
        imp->link = imp; 
        imp->ind = 0;
        nodes.pb(imp);
        par = new node(0, imp);
        par->k = imp->k = 0;
        for(int a=0;a<LOGN;a++)
            imp->lt[a] = par->lt[a] = imp;
        par->ind = 1;
        nodes.pb(par);
    }

    pal_tree(string s){
        init();
        node* u = par;
        for(int i=0;i<s.size();i++){
            u = add(u, i, s);
            u->occ++;
            debug("passei pelo u %d occ %d\n", u->ind, u->occ);
        }
    }

    node* add(node*u, int i, string &s){
        while(1){
            if(i - u->sz > 0 && s[i- u->sz - 1] == s[i])
                break;
            u = u->link;
        }
        if(u->to.find(s[i]) != u->to.end()){
            debug("aresta de u %d com char %c ja existe\n", u->sz, s[i]);
            return u->to[s[i]];
        }
        else{
            debug("novo no sz %d\n", u->sz+2);
            node *l = u->link;
            while(s[i-l->sz-1] != s[i])
                l = l->link;
            debug("to no l %d\n", l->sz);
            if(l->sz > -1)
                assert(l->to.find(s[i]) != l->to.end());
            l = (l->to.find(s[i]) != l->to.end() ? l->to[s[i]] : par);
            node *newNode = new node(u->sz + 2, l);
            newNode->lt[0] = l;
            for(int a=1;a<LOGN;a++)
                newNode->lt[a] = newNode->lt[a-1]->lt[a-1];
            int halfSz = newNode->sz/2;
            node *half = newNode;
            for(int a=LOGN-1;a>=0;a--){
                if(half->lt[a]->sz > halfSz)
                    half = half->lt[a];
            }
            half = half->link;
            newNode->k = (half->sz == halfSz ? half->k + 1 : 1);
            u->to[s[i]] = newNode;
            debug("retorna newnode\n");
            newNode->ind = nodes.size();
            debug("ind %d\n", (int)nodes.size());
            nodes.pb(newNode);
            return newNode;
        }
    }

};

int n, m, k;
char s[MAXN];

int main (){
    scanf(" %s", s);
    n = strlen(s);
    auto t = pal_tree(s);
    vector<ll> occ(nodes.size());
    for(node *u: nodes)
        occ[u->ind] += u->occ;
    vector<ll> ans(n+1, 0);
    for(int a=nodes.size()-1;a>=0;a--){
        node *u = nodes[a];
        occ[u->link->ind] += occ[u->ind];
        //printf("u ind %d k %d occ %lld\n", u->ind, u->k, occ[u->ind]);
        ans[u->k] += occ[u->ind];
    }
    for(int a=n-1;a>=0;a--){
        ans[a] += ans[a+1];
    }
    for(int a=1;a<=n;a++)
        printf("%lld ", ans[a]);
    puts("");

}
