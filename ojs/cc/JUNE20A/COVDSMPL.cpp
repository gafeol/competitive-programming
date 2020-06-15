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

const int MAXN = 65;

int n, p;
inline bool valid(int i, int j){
    return (i > 0 && j > 0 && i <= n && j <= n);
}

inline int qry(int i, int j, int ii, int jj){
    if(!valid(i, j) || !valid(ii, jj))
        return 0;
    printf("1 %d %d %d %d\n", i, j, ii, jj);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    if(x == -1)
        exit(0);
    return x;
}

int c[MAXN], M[MAXN][MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &p);
        int sum = 0;
        int c = 0;
        for(int i=n;i>=1;i--){
            int tot = qry(i, 1, i, n);
            sum = 0;
            for(int j=1;j<=n/2;j++){
               M[i][j] = tot - (qry(i, j+1, i, n) + sum);
               sum += M[i][j];
            }
            sum = 0;
            for(int j=n;j>=n/2+1;j--){
               M[i][j] = tot - (qry(i, 1, i, j-1) + sum);
               sum += M[i][j];
            }

        }
        puts("2");
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf("%d ",  M[i][j]);
            }
            puts("");
        }
        puts("");
        fflush(stdout);
        int x;
        scanf("%d", &x);
        if(x == -1)
            exit(0);
    } 
}

