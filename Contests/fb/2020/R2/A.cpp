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

const int MAXN = 1123456;

int n, m, k;
ll s[MAXN];
ll x[MAXN], y[MAXN];


int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &k);
        for(int a=0;a<k;a++){
            scanf("%lld", s+a);
        }
        ll A, B, C, D;
        scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
        for(int a=k;a<n;a++)
            s[a] = (A*s[a-2] + B*s[a-1] + C)%D;
        for(int a=0;a<k;a++)
            scanf("%lld", x+a);
        scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
        for(int a=k;a<n;a++)
            x[a] = (A*x[a-2] + B*x[a-1] + C)%D;

        for(int a=0;a<k;a++)
            scanf("%lld", y+a);

        scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
        for(int a=k;a<n;a++)
            y[a] = (A*y[a-2] + B*y[a-1] + C)%D;


        ll tot = 0;
        for(int a=0;a<n;a++)
            tot += s[a];
        ll mn = 0;
        for(int a=0;a<n;a++)
            mn += x[a];
        ll mx = 0;
        for(int a=0;a<n;a++){
            mx += x[a] + y[a];
        }

        printf("Case #%d: ", tt);
        if(tot < mn || tot > mx){
            puts("-1");
            continue;
        }

        ll ans = 0;
        ll sob = 0;
        for(int a=0;a<n;a++){
            if(s[a] > x[a] + y[a]){
                sob += s[a] - x[a] - y[a];
                s[a] = x[a] + y[a];
            }
        }
        ll fal = 0;
        ans += sob;
        for(int a=0;a<n;a++){
            if(s[a] < x[a]){
                if(s[a] + sob < x[a]){
                    s[a] += sob;
                    sob = 0;
                    fal += x[a] - s[a];
                }
                else{
                    sob -= x[a] - s[a];
                    s[a] = x[a];
                }
            }
        }
        ans += fal;
        printf("%lld\n", ans);
    }
}
