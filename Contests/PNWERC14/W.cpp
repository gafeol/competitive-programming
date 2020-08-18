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

#define ddd tuple<double, double, double>

const int MAXN = 65;

int n, m, k;
int s[MAXN];

string names[MAXN];
map<string, int> ind;
tuple<double, double, double> pts[MAXN];

double d[MAXN][MAXN];

double sq(double x){
    return x*x;
}

int main (){
    for_tests(t, tt){
        ind.clear();
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            char name[60];
            double x, y, z;
            scanf(" %s %lf %lf %lf", name, &x, &y, &z);
            names[a] = name;
            ind[name] = a;
            pts[a] = {x, y, z};
        }
        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                double x, y, z;
                tie(x, y, z) = pts[a];
                double xx, yy, zz;
                tie(xx, yy, zz) = pts[b];
                d[a][b] = sqrt(sq(x - xx) + sq(y - yy) + sq(z - zz));

            }
        }
        scanf("%d", &m);
        for(int a=0;a<m;a++){
            char pa[60], pb[60];
            scanf(" %s %s", pa, pb);
            int u = ind[pa];
            int v = ind[pb];
            d[u][v] = 0; 
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    d[i][j]= min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        printf("Case %d:\n", tt);
        scanf("%d", &k);
        for(int a=0;a<k;a++){
            char pa[60], pb[60];
            scanf(" %s %s", pa, pb);
            int u = ind[pa];
            int v = ind[pb];
            ll rd = (ll)(d[u][v]+.5);
            printf("The distance from %s to %s is %lld parsecs.\n", pa, pb, rd);
        }
    }
}

