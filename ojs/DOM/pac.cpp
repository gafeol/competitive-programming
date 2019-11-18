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

int n, m, k;
int s[MAXN];
int M[MAXN][MAXN], dp[MAXN][MAXN];

int main (){
    for_tests(t,tt){
        scanf("%d%d", &n, &m);
        for(int a=1;a<=n;a++){
            for(int b=1;b<=m;b++){
                if((a == 1 && b == 1) || (a == n && b == m))
                    scanf(" %*c");
                else
                    scanf("%d", &M[a][b]);
            }
        }
        M[1][1] = 0;
        M[n][m] = 0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                dp[i][j] = M[i][j] +  max(dp[i-1][j], dp[i][j-1]);
        printf("Game Board #%d: %d\n", tt, dp[n][m]);
    }
}

