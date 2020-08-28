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

const int MAXN = 212;

int n, m, k;
char pass[MAXN];

int mrk[MAXN];
vector<int> adj[MAXN];
vector<char> ans;

void go(int u, int p){
    mrk[u] = 1;
    //printf("u %d p %d adj sz %d\n", u, p, adj[u].size());
    if(adj[u].size() > 2 || (adj[u].size() > 1 && u == p))
        return;
    ans.pb(u+'a');
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        go(nxt, u);
    }
}

int main (){
    for_tests(t, tt){
        ans.clear();
        for(int a=0;a<26;a++){
            mrk[a] = 0;
            adj[a].clear();
        }
        scanf(" %s", pass);
        n = strlen(pass);
        for(int a=0;a+1<n;a++){
            if(pass[a] == pass[a+1]) continue;
            adj[pass[a]-'a'].pb(pass[a+1]-'a');
            adj[pass[a+1]-'a'].pb(pass[a]-'a');
        }
        for(int a=0;a<26;a++){
            sort(adj[a].begin(), adj[a].end());
            adj[a].erase(unique(adj[a].begin(), adj[a].end()), adj[a].end());
        }
        for(int a=0;a<26;a++){
            if(mrk[a]) continue;
            if(adj[a].size() > 1) continue;
            go(a, a);
        }
        if(ans.size() == 26){
            puts("YES");
            for(char c: ans)
                printf("%c", c);
            puts("");
        }
        else
            puts("NO");
    }
}

