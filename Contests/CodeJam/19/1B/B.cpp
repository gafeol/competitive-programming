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
int s[MAXN];

void valid(ll x){
    if(x == -1)
        exit(0);
}

ll print(int day){
    printf("%d\n", day); 
    fflush(stdout);
    ll ver;
    scanf("%lld", &ver);
    valid(ver);
    return ver;
}

int main (){
    int t;
    scanf("%d%d", &t, &k);
    while(t--){
        int ans[10];
        for(int i=6;i>=1;i--){
            int d = 63*(i-1);
            if(i == 1) d = 1;
            ll sum = print(d);            
            for(int j = i + 1;j<=6;j++){
                int exp = d/j;
                sum -= (1ll << exp)*ans[j];
            }
            int e = d/i;
            assert(sum % (1ll << e) == 0);
            ans[i] = sum/(1ll << e);
        }
        for(int a=1;a<=6;a++){
            printf("%d ", ans[a]);
        }
        puts("");
        fflush(stdout);
        int ver;
        scanf("%d", &ver);
        valid(ver);
    }
}

