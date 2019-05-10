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

set<pii> q;
void add(int i){
    q.insert({-s[i], i});
}

void rmv(int i){
    q.erase({-s[i], i});
}

int getMx(){
    if(q.empty())
        return 0;
    return q.begin()->snd;
}

vector<int> adj[MAXN];

void print(){
    puts("in q");
    for(auto it: q){
        printf("%d %d\n", it.fst, it.snd);
    }
}

int get(int u){
    rmv(u);
    for(int nxt: adj[u])
        rmv(nxt);
    int ans = getMx();    
    for(int nxt: adj[u])
        add(nxt);
    add(u);
    return ans;
}

int main (){
    for_tests(t, tt){
        q.clear();
        scanf("%d", &n);
        for(int a=1;a<=n;a++){
            scanf("%d", s+a);
            adj[a].clear();
            add(a);
        }
        for(int a=1;a<n;a++){
            int i, j;
            scanf("%d%d", &i, &j);
            adj[i].pb(j);
            adj[j].pb(i);
        }
        for(int i=1;i<=n;i++){
            printf("%d ", get(i));
        }
        puts("");
    }
}

