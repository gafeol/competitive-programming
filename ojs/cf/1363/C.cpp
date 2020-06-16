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
int s[MAXN];

vector<int> adj[MAXN];


void win(int t){
    if(t == 0)
        puts("Ayush");
    else
        puts("Ashish");
}

int main (){
    for_tests(t, tt){
        int x;
        scanf("%d%d", &n, &x);
        for(int a=1;a<=n;a++)
            adj[a].clear();
        for(int a=1;a<n;a++){
            int u, v;
            scanf("%d%d", &u, &v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int ar = adj[x].size();
        if(ar <= 1){
            win(0);
            continue;
        }
        win(n%2);
    }
}
