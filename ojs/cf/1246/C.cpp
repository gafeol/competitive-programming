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

const int MAXN = 2123;

int n, m, k;
ll dp[MAXN][MAXN][2];

char M[MAXN][MAXN];
int acc[MAXN][MAXN][2];
ll adp[MAXN][MAXN][2];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            scanf(" %c", &M[a][b]);
        }
	}
    if(n == 1 && m == 1){
        printf("%d\n", (M[0][0] == '.'));
        return 0;
    }
    for(int a=n-1;a>=0;a--){
        for(int b=m-1;b>=0;b--){
            acc[a][b][0] += acc[a][b+1][0] + (M[a][b] == 'R'); 
        }
    }
    for(int b=m-1;b>=0;b--){
        for(int a=n-1;a>=0;a--){
            acc[a][b][1] += acc[a+1][b][1] + (M[a][b] == 'R'); 
        }
    }
    for(int a=n-1;a>=0;a--){
        for(int b=m-1;b>=0;b--){
            int nw = acc[a][b+1][0];
            dp[a][b][0] = mod(adp[a][b+1][1] - adp[a][m-nw][1]);
            nw = acc[a+1][b][1];
            dp[a][b][1] = mod(adp[a+1][b][0] - adp[n-nw][b][0]);
            if(a == n-1 && b == m-1)
                dp[a][b][0] = dp[a][b][1] = 1; 

            adp[a][b][0] = mod(dp[a][b][0] + adp[a+1][b][0]);
            adp[a][b][1] = mod(dp[a][b][1] + adp[a][b+1][1]);
        }
    }
    printf("%lld\n", mod(modn + mod(dp[0][0][0] + dp[0][0][1])));
}

