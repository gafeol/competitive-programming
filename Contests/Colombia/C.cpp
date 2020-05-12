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
const int DEL = 1100;

int n, m, k;
int s[MAXN];

int dp[2][MAXN];
char A[MAXN], B[MAXN];

int main (){
    scanf(" %s %s", A, B);
    n = strlen(A);
    for(int i = n-1;i>=0;i--){
        int ti = i&1;
        for(int j = min(n-1, i+DEL);j>=max(0, i-DEL);j--){
            if(A[i] == B[j])
                dp[ti][j] = 1 + dp[ti^1][j+1];
            else
                dp[ti][j] = max(dp[ti^1][j], dp[ti][j+1]);
        }
    }
    //debug("ans %d\n", dp[0][0]);
    if(dp[0][0]*100ll >= n*99ll)
        puts("Long lost brothers D:");
    else
        puts("Not brothers :(");
}

