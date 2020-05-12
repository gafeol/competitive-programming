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

const int MAXN = 3123;

int n, m, k;
char s[MAXN], t[MAXN];
ll dp[MAXN][MAXN];

long long go(int i, int j){
    ll &r = dp[i][j];
    if(j == 0 && i >= m-1)
        return r = n - i;
    if(i == n-1)
        return r = 0;
    if(r != -1)
        return r;
    r = 0;
    if(j > 0 && s[i+1] == t[j-1])
        r = mod(r + go(i+1, j-1));
    int end = i + j + 1;
    if(end >= m || s[i+1] == t[end]){
        if(j == m)
            r = mod(r + 2ll*go(i+1, j));
        else
            r = mod(r + go(i+1, j));
    }
    //printf("go %d %d %lld\n", i, j, r);
    return r;
}

int main (){
    scanf(" %s %s", s, t);
    n = strlen(s);
    m = strlen(t);
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    for(int a=0;a<m;a++){
        if(s[0] == t[a]){
            //printf("go(0, %d) %lld\n", a, go(0, a));
            ans = mod(ans + go(0, a));
        }
    }
    ans = mod(ans + go(0, m));
    printf("%lld\n", mod(2ll*ans)); 
}
