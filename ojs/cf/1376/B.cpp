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
int deg[MAXN];
int s[MAXN], ss[MAXN];
int cnt, cntt;
vector<int> adj[MAXN];

int main (){
    srand(time(NULL));
	scanf("%d%d", &n, &m);
    for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        adj[i].pb(j);
        adj[j].pb(i);
    }
    clock_t clk = clock();
    while(((double) clock() - clk)/CLOCKS_PER_SEC < 60.){
        unordered_map<int, bool> v;
        for(int a=1;a<=n;a++){
            deg[a] = adj[a].size();
            s[a] = 0;
            v[a] = true;
        }
        cnt = 0;
        while(!v.empty()){
            unordered_map<int, bool> sel;
            for(auto it: v){
                int u = it.fst;
                if(((double)rand())/RAND_MAX <= 1./(2*deg[u])){
                    sel[u] = true; 
                    for(int nxt: adj[u]){
                        if(sel.find(nxt) != sel.end()){
                            if(deg[nxt] < deg[u] || (deg[nxt] == deg[u] && nxt < u)){
                                sel.erase(u);
                                break;
                            }
                            else
                                sel.erase(nxt);
                        }
                    }
                }
            }
            for(auto it: sel){
                int u = it.fst;
                v.erase(u);
                s[u] = 1;
                cnt++;
                for(int nxt: adj[u]){
                    if(v.find(nxt) != v.end()){
                        for(int nxtt: adj[nxt])
                            deg[nxtt]--;
                        v.erase(nxt);
                    }
                }
            }
        }
        if(cnt > cntt){
            cntt = cnt;
            for(int a=1;a<=n;a++)
                ss[a] = s[a];
        }
    }
    printf("%d\n", cntt);
    for(int a=1;a<=n;a++){
        printf("%d ", ss[a]);
    }
    puts("");
}

