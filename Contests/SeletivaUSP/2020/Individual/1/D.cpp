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
const ll INF = 1000000000LL;

int n, m, k;
char ss[MAXN];
int s[MAXN];

ll M[27][27];
ll acu[MAXN][27];
const int N = 26;

ll dp[MAXN][27];


ll cus(int i, int c){
    return acu[i+k-1][c] - (i > 0 ? acu[i-1][c] : 0);
}

ll go(int i, int lst){
    if(dp[i][lst] != -1) return dp[i][lst];
    if(i == n)  
        return dp[i][lst] = 0;
    else if(i > n)
        return INF;

    dp[i][lst] = INF;
    ll &r = dp[i][lst];

    if(i + k <= n){
        for(int c=0;c<m;c++){
            r = min(r, go(i+k, c) + cus(i, c));
        }
    }
    if(lst != N)
        r = min(r, go(i+1, lst) + M[s[i]][lst]);

    return r; 
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
    scanf(" %s", ss);
    for(int a=0;a<n;a++)
        s[a] = ss[a]-'a';
	for(int a=0;a<m;a++){
        for(int b=0;b<m;b++){
            scanf("%lld", &M[a][b]);
        }
	}
    for(int k=0;k<m;k++){
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
            }
        }
    }

    for(int c=0;c<m;c++){
        for(int i=0;i<n;i++){
            if(i > 0)
                acu[i][c] = acu[i-1][c];
            else
                acu[i][c] = 0;
            acu[i][c] += M[s[i]][c];
        }
    }

    memset(dp, -1, sizeof(dp));
    printf("%lld\n", go(0, N));
}

