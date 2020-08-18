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

const int MAXN = 3003;

int n, m, k;
ll dp[4][MAXN][MAXN];
ll M[MAXN][MAXN];

ll go(int i, int j, int c){
    if(i >= n || j >= m) return 0;
    ll &r = dp[c][i][j]; 
    if(r != -1) return r;
    if(c == 0) return r = 0;
    r = 0;
    r = max(r, go(i, j+1, c-1) + M[i][j]);
    r = max(r, go(i+1, j, 3) + M[i][j]);
    r = max(r, go(i+1, j, 3));
    r = max(r, go(i, j+1, c));
    return r;
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
    memset(dp, -1, sizeof(dp));
	for(int a=0;a<k;a++){
        int i, j;
        ll x;
        scanf("%d%d%lld", &i, &j, &x);
        i--;j--;
        M[i][j] = x;
	}
    printf("%lld\n", go(0,0,3));
}

