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

ll A, B;
int n;

ll acu[MAXN];

inline int check(ll x){
    return (((x%A)%B) != ((x%B)%A));
}

ll go(ll x){
    return acu[x%(A*B)] +  acu[A*B-1]*(x/(A*B));
}

int main (){
    for_tests(t, tt){
        scanf("%lld%lld%d", &A, &B, &n);
        
        acu[0] = 0;
        for(int a=1;a<A*B;a++)
            acu[a] = acu[a-1] + check(a);

        for(int a=0;a<n;a++){
            ll l, r;
            scanf("%lld %lld", &l, &r);
            ll res = go(r) - go(l-1);
            printf("%lld ", res);
        }
        puts("");
    }
}
