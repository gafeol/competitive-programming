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

ll n;
int i, j;
void go(int a, int b){
    i = a;
    j = b;
    printf("%d %d\n", i, j);
}

ll s(){
    return (1ll << (i-1ll));
}

void cross(){
    if(j == 1){
        while(j+1 <= i)
            go(i, j+1);
    }
    else{
        while(j-1 >= 1)
            go(i, j-1);
    }
}

int sk;

void skip(){
    if(j == 1)
        go(i+1, j);
    else
        go(i+1, j+1);
    sk--;
}

int nz(ll x){
    int ans = 0;
    while(x > 0){
       ans += (!(x&1));
       x >>= 1;
    }
    return ans;
}

int main (){
    for_tests(t, tt){
        i = 1;
        j = 1;
        scanf("%lld", &n);
        printf("Case #%d:\n", tt);

        go(i, j);

        for(sk=0;;sk++){
            if(nz(n-sk) <= sk)
                break;
        }


        //debug("sk %d\n", sk);
        n-=sk;

        while(n > 0){
            if((n&s()) > 0){
                n ^= s();
                cross();
                if(n > 0){
                    sk++;
                    skip();
                }
            }
            else
                skip();
        }

        while(sk)
            skip();
    }
}

