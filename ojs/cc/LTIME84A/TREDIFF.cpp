#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pll;
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

const int MAXN = 212345, LOGN = 20;

int n, m, k;
int s[MAXN];
int z;
vector<int> adj[MAXN];

int p[MAXN][LOGN];
int h[MAXN];

struct bs{
    bitset<110> b;
    bool z;

    bs() {
        b.reset();
        z = false;
    }

    inline bs operator | (bs o){
        bs c;
        c.z = (z || o.z || (b&o.b).count());
        c.b = (b|o.b);
        return c;
    }

    inline void operator |= (bs o){
        z = (z || o.z || (b&o.b).count());
        b = (b|o.b);
    }

    inline void operator |= (int x){
        //printf("colocar x em b, antes b[%d] %d\n", x, (int)b[x]);
        if(b[x])
            z = true;
        b[x] = 1;
        //printf("depois b[%d] %d\n", x, (int)b[x]);
    }

    inline void reset (){
        z = false;
        b.reset();
    }

} x[MAXN][LOGN];

void go(int u, int pai){
    h[u] = h[pai] + 1;
    p[u][0] = pai;
    x[u][0] |= s[u];
    for(int i=1;i<LOGN;i++){
        x[u][i] = (x[u][i-1] | x[p[u][i-1]][i-1]);
        p[u][i] = p[p[u][i-1]][i-1];
    }
    for(int nxt: adj[u]){
        if(nxt == pai) continue;
        go(nxt,u);   
    }
}

bs qry(int u, int v){
    bs ans;
    if(h[u] != h[v]){
        if(h[u] < h[v]) swap(u, v);
        for(int i=LOGN-1;i>=0;i--){
            if(h[p[u][i]] > h[v]){
                ans |= x[u][i];
                u = p[u][i]; 
            }
        }
        ans |= x[u][0];
        u = p[u][0];
    }
    if(u == v){
        ans |= s[u];
        return ans;
    }
    for(int i=LOGN-1;i>=0;i--){
        if(p[u][i] != p[v][i]){
            ans |= x[u][i];
            ans |= x[v][i];
            u = p[u][i];
            v = p[v][i];
        }
    }
    ans |= x[u][0];
    ans |= x[v][0];
    u = p[u][0];
    ans |= s[u];
    return ans;
}

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        for(int a=1;a<=n;a++){
            for(int b=0;b<LOGN;b++)
                x[a][b].reset();
            adj[a].clear();
            scanf("%d", s+a);
        }
        for(int a=0;a<n-1;a++){
            int i, j;
            scanf("%d%d", &i, &j);
            adj[i].pb(j);
            adj[j].pb(i);
        }
        go(1, 1);
        for(int a=0;a<m;a++){
            int i, j;
            scanf("%d%d", &i, &j);
            z = 0;
            bs q = qry(i, j);
            int ans = 10000;
            //printf("qry %d %d z %d\n", i, j, q.z);
            if(!q.z){
                int lst = -1000;
                for(int a=0;a<=100;a++){
                    if(q.b[a] == 0) continue;
                    //printf("bit %d set\n", a);
                    ans = min(ans, a - lst);        
                    lst = a;
                }
            }
            else
                ans = 0;
            printf("%d\n", ans);
        }
    }
}

