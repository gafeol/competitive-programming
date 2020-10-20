#include "bits/stdc++.h"
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

void p(int w){
    if(w == 1)
        puts("First");
    else
        puts("Second");
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        ll x = 0;
        for(int a=0;a<n;a++){
            scanf("%lld", s+a);
            x ^= s[a];
        }
        if(x == 0){
            p(2);
            continue;
        }
        if(n == 1){
            p(1);
            continue;
        }

        if((n&1)){
            if(x != 0)
                p(2);
            else
                    p(1);
            }
            else{
                if(x != 0)
                    p(1);
                else
                    p(2);
            }
        }
    }

