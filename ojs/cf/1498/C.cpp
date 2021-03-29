#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define eb emplace_back
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

const int MAXN = 1123;

int n, m, k;
ll dp[MAXN][MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &k);
        ll res = 1;
        if(k > 1){
            for(int i=0;i<n;i++){
                dp[k-1][i] = 1;
                res++;
            }
        }
        k--;
        int turn = 1;
        while(k > 1){
            ll sum = 0;
            if(!turn){
                for(int i=0;i<n;i++){
                    dp[k-1][i] = sum;
                    res = mod(res + sum);
                    sum = mod(sum + dp[k][i]);
                }
            }
            else{
                for(int i=n-1;i>=0;i--){
                    dp[k-1][i] = sum;
                    res = mod(res + sum);
                    sum = mod(sum + dp[k][i]);
                }
            }
            turn ^= 1;
            k--;
        }
        printf("%lld\n", res);
    }
    return 0;
}

