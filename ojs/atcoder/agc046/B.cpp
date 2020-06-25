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
const ll modn = 998244353;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 4123;

int n, m, k, nn, mm;
int s[MAXN];

ll dp[MAXN][MAXN];

ll go(int i, int j){
    if(i < n || j < m)
        return 0;
    ll &r = dp[i][j];
    if(r != -1)
        return r;
    r = 0;
    if(i == n && j == m)
        return r = 1;
    ll dis = 0;
    if(i > n && j > m){
        dis = ((ll)i-1)*(j-1)*go(i-1,j-1);
    }
    r = mod(mod(j*go(i-1, j)) + mod(i*go(i, j-1)) - dis);
    //printf("go %d %d : %lld\n", i, j, r);
    r = mod(modn + r);
    return r;
}


int main (){
	scanf("%d%d%d%d", &n, &m, &nn, &mm);
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", go(nn, mm));
    return 0;
}

