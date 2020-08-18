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

const int MAXN = 25;

int n, m, k;
int s[MAXN];

int main (){
    scanf("%d", &n);
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            printf("%lld ", ((a&1) ? 0 : (1ll << (a + b))));
        }
        puts("");
    }
    fflush(stdout);
    int q;
    scanf("%d", &q);
    while(q--){
        ll sum;
        scanf("%lld", &sum);
        fflush(stdout);
        int lin = 0;
        int col = 0;
        printf("%d %d\n", lin+1, col+1);
        while(lin < n-1 && col < n-1){
            if(lin&1){
                if(sum&(1ll << lin+col+1)) 
                    lin++;
                else
                    col++;
            }
            else{
                if(sum&(1ll << lin+col+1))
                    col++;
                else
                    lin++;
            }
            printf("%d %d\n", lin+1, col+1);
        }
        while(lin < n-1){
            lin++;
            printf("%d %d\n", lin+1, col+1);
        }
        while(col < n-1){
            col++;
            printf("%d %d\n", lin+1, col+1);
        }
        fflush(stdout);
    }

}

