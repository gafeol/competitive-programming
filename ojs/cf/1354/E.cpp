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

const int MAXN = 5123;

int n, m, k;
int s[MAXN];
vector<int> adj[MAXN];
int rt[MAXN];
int tp[MAXN];
int sz[MAXN][2];

pii prv[MAXN][MAXN];
bool mrk[MAXN][MAXN];

void fail(){
    puts("NO");
    exit(0);
}

void go(int u, int t, int r){
    rt[u] = r;
    tp[u] = t;
    sz[r][t]++;
    for(int nxt: adj[u]){
        if(rt[nxt]){
            if(tp[nxt] != 1-t)
                fail();
            continue;
        }
        go(nxt, 1-t, r);
    }
}

int c[MAXN];
int vis[MAXN];

void color(int u, int t){
    vis[u] = 1;
    if(!t)
        c[u] = 2;
    for(int nxt: adj[u]){
        if(!vis[nxt]){
            color(nxt, 1-t); 
        }
    }
}

int cnt[3];
int main (){
    scanf("%d%d", &n, &m);
    for(int t=0;t<3;t++)
        scanf("%d", cnt+t);
    if(cnt[0] + cnt[1] + cnt[2] != n)
        fail();
    for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        adj[i].pb(j);
        adj[j].pb(i);
    }
    vector<int> roots, single;
    for(int a=1;a<=n;a++){
        if(rt[a]) continue;
        go(a, 0, a);
        if(sz[a][1] > 0)
            roots.pb(a);
        else
            single.pb(a);
    }
    mrk[0][0] = 1;
    int uses = 0;
    for(int r: roots){
        //debug("r %d\n", r);
        for(int val = cnt[1];val>=0;val--){
            if(mrk[uses][val]){
                int nxt = val + sz[r][0];
                if(nxt <= cnt[1] && !mrk[uses+1][nxt]){
                    //printf("from %d %d reach %d %d with %d %d (sz %d)\n", uses, val, uses+1, nxt, r, 0, sz[r][0]);
                    mrk[uses+1][nxt] = 1; 
                    prv[uses+1][nxt] = {r, 0};
                }
                nxt = val + sz[r][1];     
                if(nxt <= cnt[1] && !mrk[uses+1][nxt]){
                    //printf("from %d %d reach %d %d with %d %d (sz %d)\n", uses, val, uses+1, nxt, r, 1, sz[r][1]);
                    mrk[uses+1][nxt] = 1;
                    prv[uses+1][nxt] = {r, 1};
                }
            }
        }
        uses++;
    }
    bool ok = false;
    int nr = roots.size();
    for(int a=max(0, cnt[1]-(int)single.size());!ok && a<=cnt[1];a++){ 
        if(mrk[nr][a]){
            ok = true;
            int dif = cnt[1] - a;
            while(dif--){
                c[single.back()] = 2;
                single.pop_back();
            }
            int u = a;
            int us = nr;
            while(u > 0){
                assert(us > 0);
                color(prv[us][u].fst, prv[us][u].snd);
                u -= sz[prv[us][u].fst][prv[us][u].snd];
                us--;
            }
            assert(us == 0);

        }
    }
    if(!ok)
        fail();
    for(int a=1;a<=n;a++){
        if(!c[a]){
            if(cnt[0]){
                c[a] = 1;
                cnt[0]--;
            }
            else
                c[a] = 3;
        }
    }
    puts("YES");
    for(int a=1;a<=n;a++)
        printf("%d", c[a]);
    puts("");
}

