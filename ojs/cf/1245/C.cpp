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

int n, m, k;
char s[MAXN];
ll dp[MAXN];

ll go(int i){
    if(i == n)
        return 1;
    if(dp[i] != -1) return dp[i];
    dp[i] = go(i+1);
    if(i + 1 < n && s[i] == s[i+1] && (s[i] == 'n' || s[i] == 'u'))
        dp[i] = mod(dp[i] + go(i+2));
    return dp[i];
}

int main (){
    scanf(" %s", s);
    n = strlen(s);
    for(int a=0;a<n;a++){
        if(s[a] == 'm' || s[a] == 'w'){
            puts("0");
            return 0;
        }
    }
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", go(0));
}

