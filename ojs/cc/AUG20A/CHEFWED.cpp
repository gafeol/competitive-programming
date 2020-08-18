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

int n, m, k;
int s[MAXN];

ll dp[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &k);
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
            dp[a] = LLONG_MAX;
        }
        for(int i=0;i<n;i++){
            ll cus = 0;
            ll prv = (i > 0 ? dp[i-1] : 0);
            unordered_map<int, int> cnt;
            for(int j=i;j<n;j++){
                if(cnt[s[j]] == 1)
                    cus++;
                if(cnt[s[j]] > 0)
                    cus++;
                cnt[s[j]]++;
                dp[j] = min(dp[j], cus + prv + k);
            }
        }
        printf("%lld\n", dp[n-1]);
    }
}

