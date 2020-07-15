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
double sp[2][MAXN];
int ind[2][MAXN];
double g[MAXN];

int main (){
    for_tests(t, tt){
        double res[2];
        res[0] = res[1] = 0;
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            ind[0][a] = ind[1][a] = a;
            scanf("%lf%lf%lf", g+a, sp[0]+a, sp[1]+a);
            sp[0][a] = 1./sp[0][a];
            sp[1][a] = 1./sp[1][a];
        }
        for(int t=0;t<2;t++){
            sort(ind[t], ind[t]+n, [&](int a, int b) { return (sp[t][a] > sp[t][b] || (sp[t][a] == sp[t][b] && sp[1-t][a] > sp[1-t][b])); });
        }
        int aat[2];
        aat[0] = aat[1] = 0;
        while(max(aat[0], aat[1]) < n){
            int at[2];
            at[0] = ind[0][aat[0]];
            at[1] = ind[1][aat[1]];
            if(g[at[0]] <= 1e-8){
                aat[0]++;
                continue;
            }
            if(g[at[1]] <= 1e-8){
                aat[1]++;
                continue;
            }
            if(at[0] == at[1]){
                double ttm = g[at[0]]/(sp[0][at[0]] + sp[1][at[0]]);
                res[0] += ttm*sp[0][at[0]];
                res[1] += ttm*sp[1][at[0]];
                g[at[0]] = 0;
                aat[0]++;
                aat[1]++;
            }
            else{
                double ttm1 = g[at[0]]/sp[0][at[0]];
                double ttm2 = g[at[1]]/sp[1][at[1]];
                if(ttm1 <= ttm2){
                    res[0] += g[at[0]];        
                    g[at[0]] = 0;
                    res[1] += ttm1*sp[1][at[1]];
                    g[at[1]] -= ttm1*sp[1][at[1]];
                    aat[0]++;
                }
                else{
                    res[1] += g[at[1]];
                    g[at[1]] = 0;

                    res[0] += ttm2*sp[0][at[0]];
                    g[at[0]] -= ttm2*sp[0][at[0]];
                    aat[1]++;
                }
            }
        }
        printf("%.10f %.10f\n", res[0], res[1]);
    }
}

