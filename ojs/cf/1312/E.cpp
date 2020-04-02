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
const ll INF = 0x3f3f3f3f;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 512;

int n, m, k;
int s[MAXN];

int num[MAXN][MAXN];

int join(int i, int j){
    if(num[i][j] != -1) 
        return num[i][j];
    if(i == j)
        return num[i][j] = s[i];
    num[i][j] = INF;
    for(int k=i;k<j;k++){
        if(join(i, k) == join(k+1, j) && join(i, k) != INF){
            num[i][j] = join(i, k) + 1; 
        }
    }
    return num[i][j];
}

int dp[MAXN];

int go(int i){
    if(i == n)
        return 0;
    if(dp[i] != -1)
        return dp[i];
    dp[i] = INF;
    for(int j=i;j<n;j++){
        if(join(i, j) != INF)
            dp[i] = min(dp[i], 1 + go(j+1));
    }
    return dp[i];
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
	}
    memset(num, -1, sizeof(num));
    memset(dp, -1, sizeof(dp));
    printf("%d\n", go(0));
}
