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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 412345;

int n, m, k;
int s[MAXN];

vector<int> adj[MAXN];
int deg[MAXN];

vector<int> inv[MAXN];
int ideg[MAXN];

void add_edge(int u, int v){
    // u needs to be solved before v
    adj[u].pb(v);
    inv[v].pb(u);
}

int sob[MAXN];

void propagate(){
    queue<int> q;
    for(int a=0;a<n;a++){
        if(deg[a] == 0){
            q.push(a);  
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        debug("u %d sob %d\n", u, sob[u]);
        for(int nxt: adj[u]){
            sob[nxt] = min(sob[nxt], sob[u]-1);
            deg[nxt]--;
            if(deg[nxt] == 0)
                q.push(nxt);
        }
    }
}

bool go(int tmax){
    debug("go %d\n", tmax);
    for(int a=0;a<n;a++){
        sob[a] = tmax - s[a]; 
        if(sob[a] < 0) return false;
        deg[a] = inv[a].size();
        ideg[a] = adj[a].size();
    }

    propagate();
    
    set<pii> q;
    for(int a=0;a<n;a++){
        if(ideg[a] == 0){
            q.insert({sob[a], a});
        }
    }
    int jafoi = 0;
    while(!q.empty()){
        pii p = *q.begin();  
        q.erase(q.begin());
        int u = p.snd;
        debug("u %d jafoi %d s %d\n", u, jafoi, s[u]);
        if(tmax < jafoi + s[u])
            return false;
        for(int nxt: inv[u]){
            ideg[nxt]--;
            if(ideg[nxt] == 0)
                q.insert({sob[nxt], nxt});
        }
        jafoi++;
    }
    return true;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        int x;
        scanf("%d %d", &s[a], &x); 
        while(x--){
            int b;
            scanf("%d", &b);
            b--;
            add_edge(a, b);
        }
	}
    int i = 0, j = 2000000;
    while(i < j){
        int m = (i + j)/2;
        if(go(m))
            j = m;
        else
            i = m+1;
    }
    printf("%d\n", i);
}

