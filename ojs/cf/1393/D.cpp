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

const int MAXN = 2003;

int n, m, k;
char M[MAXN][MAXN];
int dp[4][MAXN][MAXN];

int vi[] = {0, -1, 0, 1};
int vj[] = {-1, 0, 1, 0};

bool valid(int i, int j){
    return (i >=0 && j >= 0 && i < n && j < m);
}

int main (){
	scanf("%d%d", &n, &m);
    for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            scanf(" %c", &M[a][b]);
        }
    }

    int t = 0;
    int tt = (t+1)%4;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int i2 = i+vi[t], j2 = j+vj[t];
            int i3 = i+vi[tt], j3 = j+vj[tt];
            dp[t][i][j] = 1; 
            if(valid(i2, j2) && valid(i3, j3) && M[i][j] == M[i2][j2] && M[i][j] == M[i3][j3]){
                dp[t][i][j] = 1 + min(dp[t][i2][j2], dp[t][i3][j3]);
            }
        }
    }

    t = 1;
    tt = (t+1)%4;
    for(int i=0;i<n;i++){
        for(int j=m-1;j>=0;j--){
            int i2 = i+vi[t], j2 = j+vj[t];
            int i3 = i+vi[tt], j3 = j+vj[tt];
            dp[t][i][j] = 1; 
            if(valid(i2, j2) && valid(i3, j3) && M[i][j] == M[i2][j2] && M[i][j] == M[i3][j3]){
                dp[t][i][j] = 1 + min(dp[t][i2][j2], dp[t][i3][j3]);
            }
        }
    }

    t = 2;
    tt = (t+1)%4;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int i2 = i+vi[t], j2 = j+vj[t];
            int i3 = i+vi[tt], j3 = j+vj[tt];
            dp[t][i][j] = 1; 
            if(valid(i2, j2) && valid(i3, j3) && M[i][j] == M[i2][j2] && M[i][j] == M[i3][j3]){
                dp[t][i][j] = 1 + min(dp[t][i2][j2], dp[t][i3][j3]);
            }
        }
    }

    t = 3;
    tt = (t+1)%4;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
            int i2 = i+vi[t], j2 = j+vj[t];
            int i3 = i+vi[tt], j3 = j+vj[tt];
            dp[t][i][j] = 1; 
            if(valid(i2, j2) && valid(i3, j3) && M[i][j] == M[i2][j2] && M[i][j] == M[i3][j3]){
                dp[t][i][j] = 1 + min(dp[t][i2][j2], dp[t][i3][j3]);
            }
        }
    }
    ll ans = 0;
    for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            int res = dp[0][a][b];
            for(int t=0;t<4;t++)
                res = min(res, dp[t][a][b]);
            ans += res;
        }
    }
    printf("%lld\n", ans);
}

