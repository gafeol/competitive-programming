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
ll s[2][MAXN];
ll ans = 0;

void use(int x, int y){
    ll q = min(s[0][x], s[1][y]);
    ll val = 0;
    if(x > y)
        val = x*y;
    else if(x < y)
        val = -x*y;

    ans += val*q;
    s[0][x] -= q;
    s[1][y] -= q;
}

int main (){
    for_tests(t, tt){
        for(int i=0;i<2;i++){
            for(int a=0;a<3;a++){
                scanf("%lld", &s[i][a]);
            }
        }
        ans = 0;
        use(2, 1);
        use(2, 2);
        use(2, 0);
        use(0, 2);
        use(1, 1);
        use(1, 0);
        use(0, 1);
        use(0, 0);
        use(1, 2);
        assert(*max_element(s[0], s[0]+3) == 0);
        assert(*max_element(s[1], s[1]+3) == 0);
        printf("%lld\n", ans);
    }
}

