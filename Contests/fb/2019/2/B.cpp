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

int p[MAXN], sz[MAXN];
int val[MAXN];

bool dp[MAXN];
int prv[MAXN];

int raiz(int u){
    if(p[u] == u) return u;
    return p[u] = raiz(p[u]);
}

void join(int i, int j){
    i = raiz(i); j = raiz(j);
    if( i == j ) return ;
    if(sz[j] > sz[i]) swap(i, j);
    p[j] = i;
    sz[i] += sz[j];
}

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        for(int a=0;a<=n;a++){
            p[a] = a;
            sz[a] = 1;
            val[a] = 0;
        }
        for(int a=0;a<m;a++){
            int i, j;
            scanf("%d%d", &i, &j);
            i--;j--;
            while(i < j){
                join(i, j);
                i++;
                j--;
            }
        }
        vector<int> moedas;
        for(int a=0;a<n;a++)
            moedas.pb(raiz(a));
        sort(moedas.begin(), moedas.end());
        moedas.erase(unique(moedas.begin(), moedas.end()), moedas.end());
        int meta = n/2;
        for(int a=0;a<=meta;a++){
            prv[a] = -1;
            dp[a] = false;
        }

        dp[0] = true;
        prv[0] = -1;

        for(int u: moedas){
            int mv = sz[u];
            //printf("moeda %d sz %d\n", u, mv);
            for(int v = meta-mv;v>=0;v--){
                if(!dp[v]) continue;
                if(!dp[v+mv]){
                    dp[v + mv] = true;
                    //printf("dp[%d] true\n", v + mv);
                    prv[v + mv] = u;
                }
            }
        }

        int mx = -1;
        for(int v=meta;v>=0;v--){
            if(dp[v]){
                mx = v;
                break;
            }
        }
        //printf("mx %d prv %d\n", mx, prv[mx]);
        while(prv[mx] != -1){
            val[prv[mx]] = 1;
            mx -= sz[prv[mx]];
            //printf("mx %d prv %d\n", mx, prv[mx]);
        }
        printf("Case #%d: ", tt);
        for(int a=0;a<n;a++){
            printf("%d", val[raiz(a)]);
        }
        puts("");
    }
}

