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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

vector<int> adj[MAXN];

int umx, dmx;
int A, B;
int db;

void go(int u, int p, int d){
    if(dmx <= d){
        dmx = d;
        umx = u;
    }
    if(u == B)
        db = d;
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        go(nxt, u, d+1);
    }
}

int main (){
    for_tests(t, tt){
        int u, v, du, dv;
        scanf("%d%d%d%d%d", &n, &u, &v, &du, &dv);
        A = u;
        B = v;
        for(int a=1;a<=n;a++)
            adj[a].clear();
        for(int a=1;a<n;a++){
            int i, j;
            scanf("%d%d", &i, &j);
            adj[i].pb(j);
            adj[j].pb(i);
        }
        if(dv <= 2*du){
            puts("Alice");
            continue;
        }
        dmx = 0;
        go(A, A, 0);
        if(db <= du){
            puts("Alice");
            continue;
        }
        dmx = 0;
        go(umx, umx, 0);
        if(dmx <= 2*du)
            puts("Alice");
        else
            puts("Bob");
    }
}

