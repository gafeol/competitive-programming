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

const int MAXN = 212345;

struct node{
    int sz;
    node *link;
    map<char, node*> to;
    node() {}
    node(int sz, node* l): sz(sz), link(l) {}
};


node *imp, *par;

vector<int> ate;
int mx;

struct pal_tree{  
    void init(){
        imp = new node(-1, NULL);
        imp->link = imp;
        par = new node(0, imp);
    }


    pal_tree(string s){
        init();
        node* u = par;
        for(int i=0;i<s.size();i++){
            u = add(u, i, s);
            ate.pb(mx);
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
            u->to[s[i]] = newNode;
            mx = max(mx, newNode->sz);
            debug("retorna newnode\n");
            return newNode;
        }
    }

};


int n, m, k;
int main (){
    IOS();
    cin >> n;
	for(int a=0;a<n;a++){
        string s;
        cin >> s;
        mx = 0;
        ate.clear();
        auto t = pal_tree(s);
        vector<int> aux = ate;
        for(int a=0;a<s.size();a++){
            //printf("ate %d\n", ate[a]);
        }
        reverse(s.begin(), s.end());
        mx = 0;
        ate.clear();
        t = pal_tree(s);
        for(int a=0;a<s.size();a++){
            //printf("ate %d\n", ate[a]);
        }
        int res = 0;
        for(int i=0;i+1<s.size();i++){
            //printf(" considera ate[%d] %d + ate[%d] %d\n", i, ate[i], (int)s.size()-2-i, ate[s.size()-2-i]);
            res = max(res, ate[i] + aux[s.size()-2-i]);
        }
        cout << res << endl;
	}
    return 0;
}

