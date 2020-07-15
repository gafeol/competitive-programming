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

random_device rd;     //Get a random seed from the OS entropy device, or whatever
mt19937_64 eng(rd()); //Use the 64-bit Mersenne Twister 19937 generator and seed it with entropy.
//Define the distribution, by default it goes from 0 to MAX(unsigned long long)
uniform_int_distribution<unsigned long long> distr;
unsigned long long getRand() { return distr(eng); }

const int MAXN = 21234;

int n, m, k;
int s[MAXN];

ull rsz[MAXN];
int sz[2][MAXN];
vector<int> adj[2][MAXN];

int getsz(int t, int u, int p){
    sz[t][u] = 1;
    for(int nxt: adj[t][u]){
        if(nxt == p) continue;
        sz[t][u] += getsz(t, nxt, u);
    }
    return sz[t][u];
}

pii getc(int t, int u, int p, int tot){
    for(int nxt: adj[t][u]){
        if(nxt == p) continue;
        if(sz[t][nxt] > tot/2)
            return getc(t, nxt, u, tot);
        else if(sz[t][nxt] == tot/2)
            return {u, nxt};
    }
    return {u, -1};
}

ull geth(int t, int u, int p){
    ull h = 1;
    for(int nxt: adj[t][u]){
        if(nxt == p) continue;
        h = mod(h*geth(t, nxt, u));
    }
    h = mod(h + rsz[sz[t][u]]);
    return h;
}

int main (){
    for(int a=0;a<MAXN;a++)
        rsz[a] = getRand();
    while(scanf("%d", &n) != EOF){
        for(int t=0;t<2;t++){
            for(int a=1;a<=n;a++){
                adj[t][a].clear();
            }
        }
        for(int t=0;t<2;t++){
            for(int a=1;a<n;a++){
                int i, j;
                scanf("%d%d", &i, &j);
                adj[t][i].pb(j);
                adj[t][j].pb(i);
            }
        }
        pii c[2];
        vector<ull> h[2];
        for(int t=0;t<2;t++){
            getsz(t, 1, 1);
            c[t] = getc(t, 1, 1, sz[t][1]);
            int cent = c[t].fst;
            if(cent != -1){
                getsz(t, cent, cent);
                h[t].pb(geth(t, cent, cent));
            }
            cent = c[t].snd;
            if(cent != -1){
                getsz(t, cent, cent);
                h[t].pb(geth(t, cent, cent));
            }
        }
        bool ok = false;
        for(ull x: h[0]){
            for(ull y: h[1]){
               ok |= (x == y); 
            }
        }
        if(ok)
            puts("S");
        else
            puts("N");
    }
}

