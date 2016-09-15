#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 112, INF = 0x3f3f3f3f;

int n, m, k;

vector <pii> adj[MAXN];

set<pii> s;

int mxd, res;
int d[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        for(int a=0;a<=n;a++)
            adj[a].clear();
        for(int a=0;a<m;a++){
            int u, v, k;
            scanf("%d%d%d", &u, &v, &k); 
            adj[u].pb(pii(v, k));
            adj[v].pb(pii(u, k));
        }
        mxd = INT_MAX;
        for(int a=6;a<=n;a++){
            for(int b=1;b<=n;b++){
                d[b] = INF;
            }
            d[a] = 0;
            s.insert(pii(0, a));
            while(!s.empty()){
                int v = s.begin()->snd;
                s.erase(s.begin());
                for(pii nxt: adj[v]){
                    if(d[nxt.fst] > d[v] + nxt.snd){
                        if(d[nxt.fst] != INF)
                            s.erase(pii(d[nxt.fst], nxt.fst));
                        d[nxt.fst] = d[v] + nxt.snd;
                        s.insert(pii(d[nxt.fst], nxt.fst));
                    }
                }   
            }
            int mx = -1;
            if(d[1] == d[2] && d[2] == d[3] && d[3] == d[4] && d[4] == d[5]){
                for(int b=1;b<=n;b++)
                    mx = max(mx, d[b]);
            }
		//	for(int b=1;b<=n;b++){
		//		printf("%d - %d : %d\n", a, b, d[b]);
		//	}
           if(mx != -1 && mx < mxd)
                mxd = mx;
        }
        printf("Map %d: ", tt);
        if(mxd != INF && mxd != INT_MAX)
            printf("%d\n", mxd);
        else
            puts("-1");
    }
}
