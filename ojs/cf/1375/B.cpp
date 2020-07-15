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

const int MAXN = 312;

int n, m, k;
int s[MAXN];
int M[MAXN][MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        bool ok = true;
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                scanf(" %d", &M[a][b]);
                int neigh = (a > 0) + (b > 0) + (a < n-1) + (b < m-1);
                if(M[a][b] > neigh)
                    ok= false;
                M[a][b] = neigh;
            }
        }
        if(ok){
            puts("YES");
            for(int a=0;a<n;a++){
                for(int b=0;b<m;b++){
                    printf("%d ", M[a][b]);
                }
                puts("");
            }
        }
        else
            puts("NO");
    }
}

