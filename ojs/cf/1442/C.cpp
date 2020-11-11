#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 998244353;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

vector<int> adj[2][MAXN];

struct dis{
    int d, sw;

    dis() {}
    dis(int a, int b) : d(a), sw(b) {}

    dis operator+ (dis a) {
        return {a.d + d, a.sw + sw}; 
    }
    bool operator< (dis o) const {
        if(sw <= 20 && o.sw <= 20){
            return (1<<sw) + d < (1<<o.sw) + o.d;
        }
        if(sw > 20 && o.sw > 20){
            return make_pair(sw,d) < make_pair(o.sw, d);
        }
        return sw < o.sw;
    }

    bool operator >(dis o) const {
        if(sw <= 20 && o.sw <= 20){
            return (1<<sw) + d > (1<<o.sw) + o.d;
        }
        if(sw > 20 && o.sw > 20){
            return make_pair(sw,d) > make_pair(o.sw, d);
        }
        return sw > o.sw;

    }
} d[22][MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        i--;j--;
        adj[0][i].pb(j);
        adj[1][j].pb(i);
	}
    for(int t=0;t<22;t++){
        for(int a=0;a<n;a++){
            d[t][a] = dis(INT_MAX, INT_MAX);
        }
    }
    dis res(INT_MAX, INT_MAX);
    {
        set<tuple<dis, int, int>> q;
        q.insert({{0, 0}, 0, 0});
        d[0][0] = {0, 0};
        while(!q.empty()){
            auto [du, t, u] = *q.begin();
            //printf("u %d du %d %d\n", u, du.d, du.sw);
            q.erase(q.begin());
            for(int nxt: adj[(t&1)][u]){
                //printf("nxt\n");
                if(d[t][nxt] > (du + dis(1, 0))){
                    if(d[t][nxt].d != INT_MAX)
                        q.erase({d[t][nxt], t, nxt});
                    d[t][nxt] = du + dis(1, 0);
                    //printf("nxt %d %d: %d %d\n", t, nxt, d[t][nxt].d, d[t][nxt].sw);
                    q.insert({d[t][nxt], t, nxt});
                }
            }

            if(t < 21){
                int tt = t+1;
                for(int nxt: adj[(tt&1)][u]){
                    //printf("nxt\n");
                    if(d[tt][nxt] > (du + dis(1, 1))){
                        if(d[tt][nxt].d != INT_MAX)
                            q.erase({d[tt][nxt], tt, nxt});
                        d[tt][nxt] = du + dis(1, 1);
                        //printf("nxt %d %d: %d %d\n", t, nxt, d[t][nxt].d, d[t][nxt].sw);
                        q.insert({d[tt][nxt], tt, nxt});
                    }
                }
                if(d[tt][u] > d[t][u] + dis(1, 1)){
                    if(d[tt][u].d != INT_MAX)
                        q.erase({d[tt][u], tt, u});
                    d[tt][u] = d[t][u] + dis(1, 1);
                    q.insert({d[tt][u], tt, u});
                }
            }
        }
        for(int t=0;t<22;t++){
            res = min(res, d[t][n-1]);
        }
    }
    
    {
        set<tuple<pii, int>> q;
        pii d[2][MAXN];
        for(int t=0;t<2;t++){
            for(int i=0;i<n;i++){
                d[t][i] = {INT_MAX, INT_MAX};
            }
        }
        d[0][0] = {0, 0};
        while(!q.empty()){
            auto [dis, u] = *q.begin();
            int t = dis.fst;
            q.erase(q.begin());
            for(int nxt: adj[t][u]){
                //printf("nxt\n");
                if(d[t][nxt] > make_pair(d[t][u].fst, 1 + d[t][u].snd)){
                    if(d[t][nxt].fst != INT_MAX)
                        q.erase({d[t][nxt], nxt});
                    d[t][nxt] = {d[t][u].fst, d[t][u].snd + 1};
                    //printf("nxt %d %d: %d %d\n", t, nxt, d[t][nxt].d, d[t][nxt].sw);
                    q.insert({d[t][nxt], nxt});
                }
            }

            for(int nxt: adj[!t][u]){
                //printf("nxt\n");
                if(d[!t][nxt] > make_pair(d[t][u].fst + 1, d[t][u].snd + 1)){
                    if(d[!t][nxt].fst != INT_MAX)
                        q.erase({d[!t][nxt], nxt});
                    d[!t][nxt] = {d[t][u].fst + 1, + d[t][u].snd + 1};
                    //printf("nxt %d %d: %d %d\n", t, nxt, d[t][nxt].d, d[t][nxt].sw);
                    q.insert({d[!t][nxt], nxt});
                }
            }
        }

        res = min(res, dis(d[0][n-1].snd, d[0][n-1].fst));
        res = min(res, dis(d[1][n-1].snd, d[1][n-1].fst));
    }

    ll ans = mod(res.d);
    //printf("Ans %lld\n", ans);
    //printf("sw %d\n", res.sw);
    ll pot = 1;
    for(int a=0;a<res.sw;a++){
        ans = mod(ans + pot);
        pot = mod(pot*2ll);
    }
    printf("%lld\n", ans);
    return 0;
}

