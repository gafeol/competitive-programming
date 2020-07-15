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

ll s[MAXN];

ll res[3];

int sm(ll x, ll y){
    if(x < y)
        return 0;
    if(y < x)
        return 1;
    return 2;
}

int main (){
    ll mx = 1e9;
    for_tests(t,tt){
        res[0] = res[1] = -1;
        for(int a=0;a<3;a++){
            scanf("%lld", s+a);
        }
        res[sm(s[0], s[2])] = 1;
        res[sm(s[0]*s[1], s[2])] = s[1];
        res[sm(s[0]*mx, ((mx+s[1]-1)/s[1])*s[2])] = mx;
        printf("%lld %lld\n", res[0], res[1]);
    }
}

