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

const int MAXN = 312;
const int INF = 0x3f3f3f3f;

int n, h, x;
int s[MAXN];
char M[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][2];

char ctx(int cs, int t){
    return 'A' + ((cs&1)^t);
}

int go(int idx, int i, int cs, int t){
    if(cs < 0) return INF;
    int &r = dp[idx][i][cs][t];
    if(r != -1) return r;
    if(i == h) return r = 0;
    r = INF;
    if(M[idx][i] == ctx(cs, t))
        r = min(r, go(idx, i+1, cs, t));
    r = min(r, go(idx, i, cs-1, t));
    r = min(r, go(idx, i+1, cs, t) + 1);
    return r;
}

int main (){
    for_tests(t, tt){
        scanf("%d%d%d", &h, &n, &x);
        memset(dp, -1, sizeof(dp));
        for(int a=0;a<h;a++){
            for(int b=0;b<n;b++){
                scanf(" %c", &M[b][a]);
            }
        }

        // valores de dp nao consideram a troca inicial de contexto
        for(int a=0;a<n;a++){
            for(int t=0;t<2;t++){
                for(int k=0;k<=h+2;k++){
                    go(a, 0, k, t);
                }
            }
        }

        int need[MAXN];
        for(int k=0;k<=h+2;k++){
            int mn = INF;
            for(int t=0;t<2;t++){
                int sum = 0;
                for(int a=0;a<n;a++){
                    sum += go(a, 0, k, t);
                    //printf("go %d 0 %d %d: %d\n", a, k, t, go(a, 0, k, t));
                    sum = min(sum, INF);
                }
                //printf("t %d sum %d\n", t, sum);
                mn = min(mn, sum);
            }
            need[k] = mn;
            //debug("k %d need %d\n", k, need[k]);
        }

        printf("Case #%d:", tt);
        for(int a=0;a<x;a++){
            int has;
            scanf("%d", &has);
            int i = 0, j = h+2;
            while(i < j){
                int m = (i + j)/2;
                if(need[m] <= has)
                    j = m;
                else
                    i = m + 1;
            }
            printf(" %d", i+1);
        }
        puts("");
    }
}

