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

const int MAXN = 212345;

const ll IMP = LLONG_MIN;

int n, m, k;
ll s[MAXN];

//       pega? pripego?
ll dp[MAXN][2][2];

ll go(int i, bool pp, bool jp){
    //printf("go i %d pp %d jp %d\n", i, pp, jp);
    ll &r = dp[i][pp][jp];
    if(r != -1)
        return r;
    if(i == n-1){
        if(pp || jp)
            return r = IMP;
        return r = s[i-1]; // cuidado caso n = 1 ou 2
    }
    if(i == n){
        if(pp && !jp)
            return r = 0;
        else
            return r = IMP;
    }
    if(i == n+1){
        if(!pp && !jp)
            return r = 0;
        else
            r = IMP;
    }
    if(i >= n+2)
        return r = IMP;


    int prv = (i+n-1)%n; 
    r = s[prv] + go(i+2, pp, jp);
    if(jp)
        r = max(r, s[prv] + s[i+1] + go(i+3, pp, 0));
    if(r < 0)
        r = IMP;

    return r;
}

int main (){
    memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%lld", s+a);
	}
    if(n == 1){
        printf("%lld\n", s[0]);
        return 0;
    }
    if(n == 2){
        printf("%lld\n", max(s[0], s[1]));
        return 0;
    }
    /*
    printf("pega o 0: %lld\n", go(0, 1, 1));
    printf("pega o 1: %lld\n", go(1, 0, 1));
    printf("pega o 2: %lld\n", s[0] + go(2, 0, 0));
    */
    ll ans = max(max(go(1, 0, 1), go(0, 1, 1)), s[0] + go(2, 0, 0));
    printf("%lld\n", ans); 

}
