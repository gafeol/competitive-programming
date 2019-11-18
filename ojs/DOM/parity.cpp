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
map<int, int> pai, sz;
char s[10];

int raiz(int u){
    if(pai[u] == u) return u;
    return pai[u] = raiz(pai[u]);     
}

void join(int u, int v){
   u = raiz(u); 
   v = raiz(v);

   if(u == v) 
       return ;
   if(sz[u] > sz[v])
       swap(u, v);
   pai[u] = v;
   sz[v] += sz[u];
}

void setv(int x){
    if(pai.find(x) == pai.end()){
        pai[x] = x;
        sz[x] = 1;
    }
}

int main (){
    while(scanf("%d", &n) != EOF && n != -1){
        pai.clear();
        sz.clear();
        scanf("%d", &k);                
        vector<pii> odds;
        int a, ans = -1;
        for(a=0;a<k;a++){
            int l, r;
            scanf("%d %d %s", &l, &r, s);
            if(ans != -1) 
                continue;
            setv(l-1); setv(r);
            if(raiz(l-1) == raiz(r)){
                ans = a;
                continue;
            }
            if(s[0] == 'o')
                odds.pb({l-1, r});  
            else{
                join(l-1, r);
                bool ok = true;
                for(pii p: odds)
                    if(raiz(p.fst) == raiz(p.snd))
                        ans = a;
            }
        }
        if(ans == -1)
            ans = a;
        printf("%d\n", ans);
    }
}

