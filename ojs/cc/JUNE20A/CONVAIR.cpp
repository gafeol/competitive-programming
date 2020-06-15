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

int n, m, k;

int p[MAXN], sz[MAXN];
int app[MAXN];
set<pii> ex[MAXN];
vector<pii> ans;
int cus;

int raiz(int u){
    if(p[u] == u) return u;
    return p[u] = raiz(p[u]);
}

bool join(int u, int v){
    u = raiz(u);
    v = raiz(v);
    if(u == v) return false;

    if(sz[u] < sz[v])
        swap(u, v);
    sz[u] += sz[v];
    p[v] = u;

    if(ex[u].size() < ex[v].size())
        swap(ex[u], ex[v]);
    for(pii x: ex[v])
        ex[u].insert(x);
     
    return true;
}

void extra(int u){
    int r = raiz(u);
    if(app[u] == 0){
        ex[r].insert({-1, u});
    }
    else {
        ex[r].erase({-app[u], u});
        ex[r].insert({-(app[u]+1), u});
    }
    app[u]++;
}

map<int, map<int, int>> brk;
vector<int> adj[MAXN];

void liga(int u, int v){
    // u e v sao raizes proprias
    assert(p[u] == u && p[v] == v);
    if(min(ex[u].size(), ex[v].size()) > 0){
        pii uu = *ex[u].begin();
        ex[u].erase(ex[u].begin());
        pii vv = *ex[v].begin();
        ex[v].erase(ex[v].begin());

        ans.pb({uu.snd, vv.snd});
        uu.fst++;
        vv.fst++;
        if(uu.fst < 0)
            ex[u].insert(uu);
        if(vv.fst < 0)
            ex[v].insert(vv);
    }
    else if(max(ex[u].size(), ex[v].size()) == 0){
        cus+=2;
        ans.pb({u, v});  
    }
    else {
        assert(ex[u].size() > 0 && ex[v].size() == 0);
        if(sz[v] > 1 && ex[u].size() > 1){
            // quebra aresta de v
            int vv = adj[v].back();
            brk[v][vv]++; // NAO APAGA A ARESTA

            pii pbig = *ex[u].begin();
            ex[u].erase(ex[u].begin());
            ans.pb({pbig.snd, v});
            pbig.fst++;
            if(pbig.fst < 0)
                ex[u].insert(pbig);

            pbig = *ex[u].begin();
            ex[u].erase(ex[u].begin());
            ans.pb({pbig.snd, vv});
            pbig.fst++;
            if(pbig.fst < 0)
                ex[u].insert(pbig);
        }
        else{
            cus++;

            pii pbig = *ex[u].begin();
            ex[u].erase(ex[u].begin());
            ans.pb({pbig.snd, v});
            pbig.fst++;
            if(pbig.fst < 0)
                ex[u].insert(pbig);
        } 
    }
    assert(join(u, v));
}

int main (){
    for_tests(t, tt){
        brk.clear();
        scanf("%d%d", &n, &m);
        cus = 0;
        ans.clear();
        for(int a=1;a<=n;a++){
            app[a] = 0;
            adj[a].clear();
            p[a] = a;
            sz[a] = 1;
            ex[a].clear();
        }
        for(int a=0;a<m;a++){
            int i, j;
            scanf("%d%d", &i, &j);
            if(join(i, j)){
                adj[i].pb(j);
                adj[j].pb(i);
                ans.pb({i, j});
            }
            else{
                extra(i);  
                extra(j);
            }
        }
        vector<int> conj;
        for(int a=1;a<=n;a++){
            if(a == raiz(a)){
                conj.pb(a);
            }
        }
        sort(conj.begin(), conj.end(), [&](int a, int b) { return ex[a].size() > ex[b].size(); });
        int u = conj[0]; 
        for(int i=1;i<conj.size();i++){
            liga(u, conj[i]);
            u = raiz(u); // u pode ter virado conj[i]
        }

        while(ex[u].size() > 1){  // N PODE JUNTAR CARAS IGUAIS
            pii pbig = *ex[u].begin();
            ex[u].erase(ex[u].begin());
            pii pbigg = *ex[u].begin();
            ex[u].erase(ex[u].begin());

            ans.pb({pbig.snd, pbigg.snd});
            pbig.fst++;
            if(pbig.fst < 0)
                ex[u].insert(pbig);
            pbigg.fst++;
            if(pbigg.fst < 0)
                ex[u].insert(pbigg);
        }
        pii sobrou = {0,-1};
        if(!ex[u].empty())
            sobrou = *ex[u].begin();
        vector<pii> unbrk;
        for(pii p: ans){
            if(brk[p.fst][p.snd])
                brk[p.fst][p.snd]--;
            else if(brk[p.snd][p.fst])
                brk[p.snd][p.fst]--;
            else{
                if(sobrou.fst >= -1 || sobrou.snd == p.fst || sobrou.snd == p.snd)
                    unbrk.pb(p);
                else{
                    unbrk.pb({p.fst, sobrou.snd});
                    unbrk.pb({p.snd, sobrou.snd});
                    sobrou.fst += 2;
                }
            }
        }
        if(sobrou.fst == -1){
            int o = 1;
            if(sobrou.snd == o)
                o = 2;
            unbrk.pb({sobrou.snd, o});
            cus++;
        }
        printf("%d %d\n", cus, (int)unbrk.size());
        for(pii p: unbrk){
            printf("%d %d\n", p.fst, p.snd);
        }
    }
}

