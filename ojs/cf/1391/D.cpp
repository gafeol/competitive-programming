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

const int MAXN = 1000006;
const int INF = 0x3f3f3f3f;

int n, m, k;
int dp[MAXN][8];
vector<vector<char>> M;

int go(int j, int bm=0){
    int &r = dp[j][bm];
    if(r != -1)
        return r;
    if(j == m)
        return r = 0;
    int th = (M[0][j]=='1') + 2*(M[1][j]=='1');
    if(n > 2)
        th += 4*(M[2][j]=='1');
    r = INF;
    for(int chg=0;chg<(1<<n);chg++){
        int u = (th^chg);
        if(j > 0 && !(__builtin_popcount((u^bm)&3)&1)) continue;
        if(j > 0 && n == 3 && !((__builtin_popcount((u^bm)&6))&1)) continue;
        r = min(r, __builtin_popcount(chg) + go(j+1, u));
    }
    return r;
}

int main (){
	scanf("%d%d", &n, &m);
    M.resize(n, vector<char>(m));
	for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            scanf(" %c", &M[a][b]);
        }
	}
    if(n >= 4 && m >= 4){
        puts("-1"); 
        return 0;
    }
    if(n > m){
        vector<vector<char>> MM(m, vector<char>(n));
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                MM[b][a] = M[a][b];
            }
        }
        M = MM;
        swap(n, m);
    }
    if(n <= 1){
        puts("0");
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", go(0));
}

