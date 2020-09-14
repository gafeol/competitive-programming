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

const int MAXN = 512345;

int n, m, k;
vector<int> mrk;
vector<vector<int>> adj;

void go(int u, int t){
    mrk[u] = t;
    for(int nxt: adj[u]){
        if(mrk[nxt] == 0){
            go(nxt, t^3);
        }
    }
}

int main (){
	scanf("%d", &n);
    if(n&1){
        puts("Second");
        fflush(stdout);
        vector<vector<int>> s(n+1);
        adj.clear();
        adj.resize(2*n+1);
        for(int a=1;a<=2*n;a++){
            int x;
            scanf("%d", &x);
            s[x].pb(a);
        }
        for(int a=1;a<=n;a++){
            adj[a].pb(a+n);
            adj[a+n].pb(a);
            adj[s[a][0]].pb(s[a][1]);
            adj[s[a][1]].pb(s[a][0]);
        }
        mrk.clear();
        mrk.resize(2*n+1, 0);
        ll sum = 0;
        for(int a=1;a<=2*n;a++){
            if(mrk[a] == 0)
                go(a, 1);
            if(mrk[a] == 1)
                sum += a;
        }
        if(sum%(2*n) == 0){
            for(int a=1;a<=2*n;a++){
                if(mrk[a] == 1)
                    printf("%d ", a);
            }
        }
        else{
            for(int a=1;a<=2*n;a++){
                if(mrk[a] == 2)
                    printf("%d ", a);
            }
        }
        puts("");
        fflush(stdout);
    }
    else{
        puts("First");
        for(int a=0;a<2*n;a++)
            printf("%d%c", 1 + a%n, " \n"[a==2*n-1]);
        fflush(stdout);
    }
    scanf("%*d");
}

