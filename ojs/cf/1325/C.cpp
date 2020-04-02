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

const int MAXN = 112345;

int n, m, k;
int s[MAXN];
vector<pii> adj[MAXN];
int res[MAXN];
int deg[MAXN];
int mrk[MAXN];

int go(int u, int p){
    int val = mrk[u];  
    for(pii ar: adj[u]){
        int nxt = ar.fst;
        if(nxt == p) continue;
        val = max(val, go(nxt, u));
    }
    return val;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n-1;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        adj[i].pb({j, a});
        adj[j].pb({i, a});
        deg[i]++;
        deg[j]++;
	}
    if(n == 2){
        puts("0");
        return 0;
    }
    memset(res, -1, sizeof(res));
    int cnt = 0;
    pii vert[2];
    for(int a=1;cnt < 2;a++){
        if(deg[a] > 1) continue;
        mrk[a] = 1;
        res[adj[a][0].snd] = cnt++;
    }
    for(int a=1;cnt < 3 && a<=n;a++){
        if(deg[a] > 2){
            for(pii ar: adj[a]){
                int nxt = ar.fst;
                int val = go(nxt, a);
                if(!val){
                    res[ar.snd] = cnt++;
                    break;
                }
            }
        }
    }
    for(int a=0;a<n-1;a++){
        if(res[a] != -1)
            printf("%d\n", res[a]);
        else
            printf("%d\n", cnt++);
    }

}

