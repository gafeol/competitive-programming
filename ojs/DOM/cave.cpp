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

const int MAXN = 212345, INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];

int val[4];

struct ares{
    int to;
    vector<int> nd = {0, 0, 0, 0};

    ares(){}
    ares(int too, vector<int> ndd) : to(too), nd(ndd) {}
};

int d[MAXN];
vector<ares> adj[MAXN];

int np(vector<int> &p, int d){
    int ans = 0;
    for(int x : p)
       ans += max(0, x - d); 
    return ans;
}

bool valid(int d, vector<int> &p, vector<int> &nd){
    for(int i=0;i<4;i++)
        if(max(0, p[i] - d) < nd[i])
            return false;
    return true;
}

int main (){
    map<char, int> cvt;
    cvt['F'] = 0;
    cvt['E'] = 1;
    cvt['W'] = 2;
    cvt['P'] = 3;
    for_tests(t, tt){
        vector<int> p(4);
        scanf("%d%d%d%d%d%d", &n, &m, &p[0], &p[1], &p[2], &p[3]);
        for(int a=1;a<=n;a++){
            scanf("%d", s+a);
            adj[a].clear();
        }
        for(int a=0;a<m;a++){
            int i, j;
            scanf("%d%d", &i, &j);
            string st;
            cin >> st;

            vector<int> nd(4, 0);
            if(st[0] != 'N') {
                for(char c: st)
                    nd[cvt[c]]++;
            }
            adj[i].pb({j, nd});
            adj[j].pb({i, nd});
        }
        memset(d, INF, sizeof(d));
        d[1] = 0;
        set<pii> q;
        q.insert({0, 1});
        while(!q.empty()){
            pii par = *q.begin();
            q.erase(q.begin());
            int u = par.snd;
            for(ares e: adj[u]){
                int nxt = e.to;
                vector<int> &nd = e.nd;
                int cus = (s[u] != 0);
                if(d[nxt] > d[u] + cus && s[nxt] <= np(p, d[u] + cus) && valid(d[u] + cus, p, nd)){
                    if(d[nxt] != INF)
                        q.erase({d[nxt], nxt});
                    d[nxt] = d[u] + cus;
                    q.insert({d[nxt], nxt}); 
                }
            }
        }
        printf("Cave #%d: ", tt);
        if(d[n] == INF)
            puts("DOOMED");
        else
            printf("%d\n", np(p, d[n]));
    }
}

