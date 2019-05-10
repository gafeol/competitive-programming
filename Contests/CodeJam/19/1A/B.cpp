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

int main (){
    for_tests(t, tt){
        int res[400];
        scanf("%d%d", &n, &m);
        for(int a=2;a<=min(18, n+1);a++){
            for(int i=0;i<18;i++){
                printf("%d%c", a, " \n"[i == 17]);
                fflush(stdout);
            }
            int sum =0;
            for(int i=0;i<18;i++){
                int x;
                scanf("%d", &x);
                if(x == -1) return 0;
                sum = (sum + x)%a;
            }
            res[a] = sum;
        }
        bool printed = false;
        for(int i=1;i<=m;i++){
            bool ok = true;
            for(int j=2;j<=min(18, n+1);j++){
                if((i%j) != res[j]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                printf("%d\n", i);
                printed = true;
                fflush(stdout);
                int ver;
                scanf("%d", &ver);
                if(ver == -1) return 0;
                break;
            }
        }
        if(!printed){
            printf("1\n");
            fflush(stdout);
        }
    }
}

