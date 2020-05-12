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
const int BIT = (1<<21) + 10;

const int INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];
int lst;

int dp[BIT][10];
int go(int bm, int lst){
    int &r = dp[bm][lst];
    if(r != -1)
        return r;
    if(bm == (1<<n) - 1)
        return r = 0;
    r = INF;
    for(int a=0;a<n;a++){
        if(bm&(1<<a)) continue;
        for(int dis=0;dis<=lst;dis++){
            if(dis >= s[a]) break;
            r = min(r, s[a] - dis + go(bm|(1<<a), s[a] - 1 - dis));
        }
    }
    return r;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
	}
    memset(dp, -1, sizeof(dp));
    printf("%d\n", go(0, 0));
}

