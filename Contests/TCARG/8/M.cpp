#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<bool, int> pbi;
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

const int MAXN = 100002;
const int SQRT = 320;

int n, m, k;
int tempo = 0;
int t[2][MAXN];
int sz[2][MAXN];
pbi p[2][MAXN];
int osz[MAXN];
pbi op[MAXN];

vector<pii> nxtB[MAXN/SQRT + 5];
int cmp[MAXN/SQRT + 5];

inline void eval(bool in, int u){
    if(t[in][u] != tempo){
        t[in][u] = tempo;
        if(in){
            p[in][u] = op[u];
            sz[in][u] = osz[u];
        }
        else{
            p[in][u] = {0, u};
            sz[in][u] = 1;
        }
    }
}

pbi raiz(bool in, int u){
    eval(in, u);
    if(p[in][u] == make_pair(in, u)) return {in, u};
    else return p[in][u] = raiz(p[in][u].fst, p[in][u].snd);
}

inline bool join(bool tu, int u, bool tv, int v){
    tie(tu, u) = raiz(tu, u);
    tie(tv, v) = raiz(tv, v);
    if(u == v) return false;
    if(sz[tu][u] < sz[tv][v]){
        swap(tu, tv);
        swap(u, v);
    }
    p[tv][v] = {tu, u};
    sz[tu][u] += sz[tv][v];
    return true;
}

inline int ini(int b){
    return min(n, b*SQRT);

}
int main (){
    tempo = 0;
	scanf("%d%d", &n, &k);
    vector<vector<int>> adj(n);
	for(int a=0;a<n;a++){
        for(int t=0;t<2;t++){
            ::t[t][a] = 0;
            p[t][a] = {t, a};
            sz[t][a] = 1;
        }
        cmp[a/SQRT]++;
	}

    scanf("%d", &m);
    for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        i--;j--;
        if(i > j) swap(i, j);
        adj[i].pb(j);
        int ib = i/SQRT; int jb = j/SQRT;
        if(ib == jb)
            cmp[ib] -= join(1, i, 1, j);
        else
            nxtB[ib].pb({i, j});
    }
    for(int a=0;a<n;a++){
        op[a] = p[1][a];
        osz[a] = sz[1][a];
    }
    int q;
    scanf("%d", &q);
    int ans;
    for(int a=0;a<q;a++){
        ans = 0;
        tempo++;
        int i, j;
        scanf("%d%d", &i, &j);
        i--;j--;
        int inib = i/SQRT + (i%SQRT != 0);
        int lstb = j/SQRT - 1;
        if(inib >= lstb){
            ans = j - i + 1;
            for(int a=i;a<=j;a++){
                for(int nxt: adj[a]){
                    if(nxt >= i && nxt <= j)
                        ans -= join(0, a, 0, nxt);
                }
            }
            printf("%d\n", ans);
        }
        else{
            //assert(ini(inib) >= i);
            ans = ini(inib) - i;
            for(int a=i;a<ini(inib);a++){
                for(int nxt: adj[a]){
                    if(nxt < i) continue;
                    if(nxt < ini(inib)){
                        ans -= join(0, a, 0, nxt);   
                    }
                    else{ //nxt ta num bucket
                        ans -= join(0, a, 1, nxt);
                    }
                }
            }
            //assert(lstb+1 < ini.size());
            //assert(ini(lstb) + SQRT <= j);
            //assert(j - ini(lstb+1) + 1 >= 0);
            ans += max(0, j - ini(lstb+1) + 1);
            for(int a=ini(lstb+1);a<=j;a++){
                for(int nxt: adj[a]){
                    if(nxt > j) continue;
                    if(nxt >= ini(lstb+1))
                        ans -= join(0, nxt, 0, a);
                    else
                        ans -= join(1, nxt, 0, a);
                }
            }

            for(int b=inib;b<lstb;b++){
                ans += cmp[b];
                for(pii nxt: nxtB[b])
                    ans -= join(1, nxt.fst, 1, nxt.snd);
            }
            ans += cmp[lstb];
            for(pii nxt: nxtB[lstb]){
                if(nxt.snd <= j)
                    ans -= join(1, nxt.fst, 0, nxt.snd);
            }
            printf("%d\n", ans);
        }
    }
}

