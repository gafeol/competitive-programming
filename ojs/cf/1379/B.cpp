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

ll m;
int s[MAXN];
int l, r;

bool valid(int x){
    return (l <= x && x <= r);
}

bool valid(int a, int b, int c){
    return valid(a) && valid(b) && valid(c);
}

int main (){
    for_tests(t, tt){
        scanf("%d%d%lld", &l, &r, &m);
        for(ll a=l;a<=r;a++){
            ll n = (m + r - l)/a;
            ll d = n*a - m;
            if(d > r - l || d < l - r) continue;
            ll b, c;
            if(d <= 0){
                b = r;
                c = d + r;
            }
            else{
                c = r;
                b = r - d;
            }
            if(valid(a, b, c) && m == n*a + b - c){
                printf("%lld %lld %lld\n", a, b, c);
                break;
            }
        }
    }
}

