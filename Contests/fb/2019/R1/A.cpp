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
int dist[MAXN][MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        for(int a=0;a<=n;a++){
            for(int b=0;b<=n;b++){
                dist[a][b] = (a != b) * INF;
            }
        }
        bool ok = true;

        vector<tuple<int, int, int> > inp;
        for(int a=0;a<m;a++){
            int i, j, w;
            scanf("%d %d %d", &i, &j, &w);
            inp.pb({i, j, w});
            dist[i][j] = w;
            dist[j][i] = w;
        }

        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dist[i][j] > dist[i][k] + dist[k][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        for(tuple<int, int, int> tp: inp){
            int i, j, w;
            tie(i, j, w) = tp;
            if(dist[i][j] != w){
                ok = false;    
            }
        }
        printf("Case #%d: ", tt);
        if(!ok)
            puts("Impossible");
        else{
            printf("%d\n", (int)inp.size());
            for(tuple<int, int, int> tp: inp){
                int i, j, w;
                tie(i, j, w) = tp;
                printf("%d %d %d\n", i, j, w);
            }
        }
    }
}

