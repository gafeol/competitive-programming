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

const int MAXN = 212;

int n, m, k, i, j;
int s[MAXN];
vector<int> adj[MAXN];

pii go(int u, int p, int t){
    pii res = {0, (u == k)};
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        pii aux = go(nxt, u, t);
        if(u == p && t){
            if(aux.snd){
                res = aux;
                res.fst++;
            }
        }
        else{
            res.fst = max(res.fst, aux.fst + 1);
            res.snd = max(res.snd, aux.snd);
        }
    }
    return res;
}

int main (){
	scanf("%d", &n);
    scanf("%d%d%d", &k, &i, &j);
	for(int a=1;a<n;a++){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
	}
    int ans = INT_MAX;
    for(int a=1;a<=n;a++){
        int t = (i == a || j == a);
        //printf("raiz %d pes %d\n", a, go(a, a, t).fst + 1-t);
        ans = min(ans, go(a, a, t).fst + 1-t);
    }
    printf("%d\n", ans);
}

