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
const int INF = 0x3f3f3f3f;

int n, m, k;
string s[MAXN];

int id[MAXN][55];

int d[MAXN*55];

map<string, int> ind;
int cnt;

int add(string x){
    //if(ind.find(x) == ind.end())
        ind[x] = cnt++;
    return ind[x];
}

vector<pii> adj[MAXN*55];

void add_edge(int u, int v, int cus){
    //printf("add edge %d %d %d\n", u, v, cus);
    adj[u].pb({v, cus});
}

int pref(string &a, string &b){
    int mn = min(a.size(), b.size()); 

    for(int i=0;i<mn;i++){
        if(a[i] != b[i])
            return 0;
    }
    return 1 + (a.size() > b.size());
}

int main (){
    while(scanf("%d", &n) != EOF && n > 0){
        for(int a=0;a<=cnt;a++){
            adj[a].clear();
        }
        cnt = 0;
        ind.clear();

        for(int a=0;a<n;a++){
            char pal[55];
            scanf(" %s", pal);
            s[a] = pal;
        }
        for(int i=0;i<n;i++){
            for(int sti=0;sti<s[i].size();sti++){
                id[i][sti] = add(s[i].substr(sti, s[i].size()-sti));
            }
        }

        int S = cnt++;
        int T = cnt++;

        for(int i=0;i<n;i++)
            add_edge(S, id[i][0], s[i].size());
        for(int i=0;i<n;i++){
            for(int sti=0;sti<s[i].size();sti++){
                string suf = s[i].substr(sti, s[i].size()-sti);
                int sufId = id[i][sti];
                for(int j=0;j<n;j++){
                    if(sti == 0 && i == j) continue;
                    string &c = s[j];
                    int cId = id[j][0];
                    int isPref = pref(c, suf);
                    if(isPref == 1){ // c pref de suf
                        if(c.size() == suf.size())
                            add_edge(sufId, T, 0);
                        else
                            add_edge(sufId, id[i][sti+c.size()], 0);
                    }
                    if(isPref == 2){
                        int cus = c.size() - suf.size();
                        add_edge(sufId, id[j][suf.size()], cus);
                    }
                }
            }
        }

        for(int a=0;a<cnt;a++)
            d[a] = INF;
        set<pii> q;
        d[S] = 0;
        q.insert({0, S});
        while(!q.empty()){
            pii top = *q.begin();
            q.erase(q.begin());
            int u = top.snd;
            for(pii e: adj[u]){
                int v = e.fst;
                int cus = e.snd;
                if(d[v] > d[u] + cus){
                    if(d[v] < INF)
                        q.erase({d[v],v});
                    d[v] = d[u] + cus;
                    q.insert({d[v], v});
                }
            }
        }
        if(d[T] == INF)
            puts("-1");
        else
            printf("%d\n", d[T]);
    }
}

