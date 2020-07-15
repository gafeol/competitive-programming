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
ll s[MAXN];
ll sum[MAXN][2];

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        sum[0][0] = sum[0][1] = 0;
        for(int a=0;a<n;a++){
            scanf("%lld", s+a);
            if(a > 0){
                sum[a][0] = sum[a-1][0];
                sum[a][1] = sum[a-1][1];
            }
            sum[a][(a&1)] += s[a];
        }
        ll res = 0;
        ll back = sum[n-1][0];
        ll mx[] = {sum[0][0] - sum[0][1], 0};
        for(int a=0;a<n;a++){
            int t = (a&1);
            mx[t] = max(mx[t], sum[a][0] - sum[a][1]);
            if(t == 0)
                back -= s[a];
            //printf("A %d t %d sum1 %lld + %lld + back %lld\n", a, t, sum[a][1], mx[t], back);
            res = max(res, sum[a][1] + mx[t] + back);
        }
        printf("%lld\n", res);
    }
}

