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
int pref[MAXN];
int gr[MAXN];

vector<int> vis[MAXN];
vector<int> adj[MAXN];

int got[MAXN];
set<int> per[MAXN];

bool vst[MAXN];

bool res[MAXN];


struct {
    int tot;
    //            pref  list of p
    unordered_map<int, set<int>> p;


    void add(int id){
        if(p[pref[id]].find(id) == p[pref[id]].end()){
            tot++;
            p[pref[id]].insert(id);
        }
        else{
            tot--;
            p[pref[id]].erase(id);
        }
    }

    void save(int milkType){
        tot -= p[milkType].size(); 
        for(int id: p[milkType]){
           res[id] = true; 
           //debug("%d ", id);
        }
        p[milkType].clear();
    }

    void print(){
        debug("======\n");
        for(auto it: p){
            printf("type %d: ", it.fst);
            for(int x: it.snd)
                printf("%d ", x);
            puts("");
        }
        debug("======\n");
    }
} state[MAXN];

int id[MAXN];

queue<int> q;

void go(int vu){
    vst[vu] = true;
    int u = id[vu];


    //debug("v %d save : ", vu);
    state[u].save(s[vu]);
    //puts("");
    
    for(int nxt: adj[vu]){
        if(vst[nxt]) continue;
        gr[nxt]--;
        if(gr[nxt] == 1)
            q.push(nxt);

        // join
        int v = id[nxt]; 
//        debug("join %d (id %d) with %d (id %d)\n", vu, u, nxt, v);
//        debug("%d (id %d)\n", vu, u);
//        //state[u].print();
//        debug("%d (id %d)\n", nxt, v);
        //state[v].print();


        if(state[u].tot < state[v].tot)
            swap(u, v);
        // u is heavier
        id[nxt] = u;

        // u <- v
        for(auto it: state[v].p){
            for(int x: it.snd){
                if(pref[x] == s[nxt])
                    res[x] = 1;
                state[u].add(x);
            }
        }
        state[v].p.clear();

        //debug("joined!\n");
        //state[id[nxt]].print();
    }
}


int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
	}
    for(int a=0;a<n-1;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        i--;j--;
        adj[i].pb(j);        
        adj[j].pb(i);
        gr[i]++;
        gr[j]++;
    }
    for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d%d", &i, &j, &k);
        i--;
        j--;
        res[a] = (s[i] == k || s[j] == k);
        if(i == j)
            continue;
        pref[a] = k;
        state[i].add(a);
        state[j].add(a);
    }
    for(int a=0;a<n;a++){
        id[a] = a;
        if(gr[a] == 1){
            q.push(a);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        //debug("go %d\n", u);
        go(u);
    }
    for(int a=0;a<m;a++){
        printf("%d", res[a]);
    }
    puts("");
}

