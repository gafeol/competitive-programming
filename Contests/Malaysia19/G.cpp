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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 21234;

int n, m, k;
int s[MAXN];


struct task {
    vector<int> dep;
    int type;
    ll runt;
    int endp;


    task(vector<int> d, int t, int x){
        dep = d;
        type = t;
        runt = endp = -1;
        if(t == 0)
            runt = x;
        else
            endp = x;
    }
};


vector<task> endp[MAXN];
vector<int> adj[MAXN];
int deg[MAXN];
ll t[MAXN];

namespace f{
    ll solve(int e){
        debug("solve endp %d\n", e);
        vector<vector<int>> adj(endp[e].size());
        vector<int> deg(endp[e].size(), 0);
        vector<ll> taskTime(endp[e].size(), 0);
        vector<ll> prevTaskTime(endp[e].size(), 0);

        ll ans = 0;

        for(int i=0;i<endp[e].size();i++){
            task tsk = endp[e][i];
            for(int dt: tsk.dep){
                adj[dt].pb(i);
                deg[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<endp[e].size();i++){
            if(deg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int tskid = q.front();
            task tsk = endp[e][tskid];
            q.pop();
            
            debug(" solving tskid %d\n", tskid);
            taskTime[tskid] = prevTaskTime[tskid];
            debug("     prvtsktime %lld\n", prevTaskTime[tskid]);
            if(tsk.type == 0){
                taskTime[tskid] = mod(taskTime[tskid] + tsk.runt);
                debug("     soma runt %lld\n", tsk.runt);
            }
            else {// garantir que t[tsk.endp] ja foi calculado 
                taskTime[tskid] = mod(taskTime[tskid] + t[tsk.endp] + 1);
                debug("     soma t de endp %d: %lld\n", tsk.endp, t[tsk.endp]);
            }

            debug(" solved taskid %d com tempo %lld\n", tskid, taskTime[tskid]);

            for(int nxtt: adj[tskid]){
                deg[nxtt]--;
                prevTaskTime[nxtt] = max(prevTaskTime[nxtt], taskTime[tskid]);
                if(deg[nxtt] == 0)
                    q.push(nxtt);
            }

            ans = max(ans, taskTime[tskid]);
        }
        return ans;
    }
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        int nt;
        scanf("%d", &nt);
        for(int i=0;i<nt;i++){
            int nd;
            scanf("%d", &nd);
            vector<int> dep;
            for(int j=0;j<nd;j++){
                int x;
                scanf("%d", &x);
                x--;
                dep.pb(x);
            }
            int type, x;
            scanf("%d%d", &type, &x);
            if(type == 1){
                x--;
                // a depende de x
                adj[x].pb(a);
                deg[a]++;
            }
            endp[a].pb(task(dep, type, x));
        }
	}
    queue<int> qEnd;
    for(int a=0;a<n;a++){
        if(deg[a] == 0){
            qEnd.push(a);
        }
    }
    while(!qEnd.empty()){
        int u = qEnd.front();
        qEnd.pop();
        for(int nxt: adj[u]){
            deg[nxt]--;
            if(deg[nxt] == 0){
                qEnd.push(nxt);
            }
        }
        t[u] = f::solve(u); 
        debug("resolveu u %d com %lld\n\n", u, t[u]);
    }
    for(int a=0;a<m;a++){
        int x;
        scanf("%d", &x);
        printf("%lld\n", t[x-1]);
    }
}

