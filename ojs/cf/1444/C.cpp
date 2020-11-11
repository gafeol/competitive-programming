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

const int MAXN = 512345;

int n, m, k;
int s[MAXN];
int color[MAXN];
bool isBip[MAXN];

vector<int> adj[MAXN];

map<int, vector<pii>> sAdj[MAXN];

int p[MAXN], sz[MAXN];

int raiz(int u){
    if(p[u] == u) return u;
    return p[u] = raiz(p[u]);
}

bool join(int i, int j){
    i = raiz(i);
    j = raiz(j);
    if(i == j) return false;

    if(sz[j] > sz[i])
        swap(i, j);
    p[j] = i;
    sz[i] += sz[j];
    return true;
}

bool go(int u, int c=1){
    //printf("go u %d c %d\n", u, c);
    color[u] = c; 
    bool ver = true;
    for(int nxt: adj[u]){
        if(color[nxt] == -1)
            ver &= go(nxt, 3-c);
        else
            ver &= (color[nxt] == 3-c);
    }
    return ver;
}

bool check(pii u, int c, map<pii, vector<pii>> &adj, map<pii, int> &color){
    bool ver = true;
    color[u] = c;
    for(pii nxt: adj[u]){
        if(color.find(nxt) == color.end())
            ver &= check(nxt, 1-c, adj, color);
        else
            ver &= (color[nxt] == 1-c);
    }
    return ver;
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
    vector<vector<int>> incomp(k);
	for(int a=0;a<n;a++){
        color[a] = -1;
        sz[a] = 1;
        p[a] = a;
        scanf("%d", s+a);
        s[a]--;
        incomp[s[a]].pb(a);
	}
    for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        i--;j--;
        if(s[i] == s[j]){
            adj[i].pb(j);
            adj[j].pb(i);
            join(i, j);
        }
        else{
            if(s[i] > s[j])
                swap(i, j);
            sAdj[s[i]][s[j]].pb({i, j});
        }
    }

    int tot = 0;
    for(int a=0;a<k;a++){
        isBip[a] = true;
        for(int v: incomp[a]){
            if(color[v] != -1) continue;
            //printf("incomp[%d] v %d\n", a, v);
            isBip[a] &= go(v);
        }
        tot += isBip[a];
    }
    ll ans = 0;
    for(int a=0;a<k;a++){
        if(!isBip[a]) continue;
        tot--;
        int otot = tot;
        //printf("A comp %d\n", a);
        for(auto [b, v] : sAdj[a]){
            map<pii, bool> inv;
            if(!isBip[b]) continue;
            tot--;
            //printf("B comp %d\n", b);

            set<int> vertices, ov;
            map<pii, vector<pii>> ar;
            auto liga = [&](int u, int v) {
                int cu = color[u], cv = color[v];
                cu--; cv--;
                u = raiz(u); v = raiz(v);
                vertices.insert(u);
                ov.insert(v);
                ar[{u, cu}].pb({v, cv});
                ar[{v, cv}].pb({u, cu});
                //printf("ar u %d c %d v %d c %d\n", u, cu, v, cv);
            };

            for(pii p: v){
                //printf("liga %d %d\n", p.fst, p.snd);
                liga(p.fst, p.snd);
            }
        
            bool ok = true;

            map<pii, int> C;
            for(auto u: vertices){
                ar[{u, 0}].pb({u, 1});
                ar[{u, 1}].pb({u, 0});
            }
            for(auto u: ov){
                ar[{u, 0}].pb({u, 1});
                ar[{u, 1}].pb({u, 0});
            }
            while(!vertices.empty()){
                int u = *vertices.begin();
                vertices.erase(vertices.begin());
                if(C.find({u, 0}) == C.end())
                    ok &= check({u, 0}, 0, ar, C);
            }
            if(ok)
                ans++;
            //printf("Ok %d\n", ok);
        }
        ans += tot;
        tot = otot;
    }
    printf("%lld\n", ans);
    return 0;
}
