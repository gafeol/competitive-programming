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

const int MAXN = 212;

int n, m, k;
int s[MAXN];
int nxt[MAXN];

long double dp[MAXN];

int cvt(int i, int j){
    return i*10 + (i%2==0 ? j : 9 - j);
}

long double go(int i){
    if(i >= 99) 
        return dp[i] = 0;
    if(dp[i] >= 0) 
        return dp[i];

    dp[i] = 0;
    for(int p=1;p<=6;p++){
        if(i + p < 100)
            dp[i] += (1. + min(go(i+p), go(nxt[i+p])))/6;
    }
    int miss = 6 - (99 - i);
    if(miss > 0)
        dp[i] = (dp[i]*6 + miss)/(6.-miss);
    return dp[i];
}

int main (){
	for(int a=9;a>=0;a--){
        for(int b=0;b<10;b++){
            int lk;
            scanf("%d", &lk);
            int idx = cvt(a, b);
            nxt[idx] = cvt(a+lk, b);
        }
	}
    memset(dp, -1, sizeof(dp));
    printf("%.10Lf\n", go(0)); 
}

